#include "out_dds.h"

static int dds_shutdown(DDS_DomainParticipant *participant)
{
    int status = 0;
    DDS_ReturnCode_t retcode;

    if (participant != NULL) {
        retcode = DDS_DomainParticipant_delete_contained_entities(participant);
        if (retcode != DDS_RETCODE_OK) {
            flb_error("[out_dds] delete_contained_entities error %d\n", retcode);
            status = -1;
        }
        retcode = DDS_DomainParticipantFactory_delete_participant(
            DDS_TheParticipantFactory, participant);
        if (retcode != DDS_RETCODE_OK) {
            flb_error("[out_dds] delete_participant error %d\n", retcode);
            status = -1;
        }
    }
    /* RTI Data Distribution Service provides the finalize_instance() method on
    domain participant factory for users who want to release memory used
    by the participant factory. Uncomment the following block of code for
    clean destruction of the singleton. */
    /*
    retcode = DDS_DomainParticipantFactory_finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        printf("finalize_instance error %d\n", retcode);
        status = -1;
    }
    */
    return status;
}

static int cb_dds_init(struct flb_output_instance *ins,
		struct flb_config *config,
		void *data)
{   
	struct flb_out_dds_config *ctx;
	const char *tmp = NULL;
	DDS_ReturnCode_t retcode;

	ctx = flb_calloc(1, sizeof(struct flb_out_dds_config));
	if (!ctx) {
		flb_errno();
		return -1;
	}

	// Setting Domain ID
	tmp = flb_output_get_property("domain_id", ins);
	if (tmp != NULL && atoi(tmp) >= 0) {
		ctx->domain_id = atoi(tmp);
	}
	else {
		ctx->domain_id = 0;
	}

	/* To customize participant QoS, use
	   the configuration file USER_QOS_PROFILES.xml */
	ctx->participant = DDS_DomainParticipantFactory_create_participant(
			DDS_TheParticipantFactory, ctx->domain_id, &DDS_PARTICIPANT_QOS_DEFAULT,
			NULL /* listener */, DDS_STATUS_MASK_NONE);
	if (ctx->participant == NULL) {
		flb_error("[out_dds] create_participant error\n");
		dds_shutdown(ctx->participant);
		flb_errno();
		return -1;
	}

	/* To customize publisher QoS, use
	   DDS_DomainParticipant_get_default_publisher_qos() instead */
	ctx->publisher = DDS_DomainParticipant_create_publisher(
			ctx->participant, &DDS_PUBLISHER_QOS_DEFAULT, NULL /* listener */,
			DDS_STATUS_MASK_NONE);
	if (ctx->publisher == NULL) {
		flb_error("[out_dds] create_publisher error\n");
		dds_shutdown(ctx->participant);
		flb_errno();
		return -1;
	}

	/* Register type before creating topic */
	ctx->type_name = FBTypeSupport_get_type_name();
	retcode = FBTypeSupport_register_type(
			ctx->participant, ctx->type_name);
	if (retcode != DDS_RETCODE_OK) {
		flb_error("[out_dds] register_type error %d\n", retcode);
		dds_shutdown(ctx->participant);
		flb_errno();
		return -1;
	}

	/* To customize topic QoS, use
	   DDS_DomainParticipant_get_default_topic_qos() instead */
	ctx->topic = DDS_DomainParticipant_create_topic(
			ctx->participant, "FluentBit",
			ctx->type_name, &DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
			DDS_STATUS_MASK_NONE);
	if (ctx->topic == NULL) {
		flb_error(" [out_dds] create_topic error\n");
		dds_shutdown(ctx->participant);
		flb_errno();
		return -1;
	}

	/* To customize data writer QoS, use
	   DDS_Publisher_get_default_datawriter_qos() instead */
	ctx->writer = DDS_Publisher_create_datawriter(
			ctx->publisher, ctx->topic,
			&DDS_DATAWRITER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
	if (ctx->writer == NULL) {
		flb_error("[out_dds] create_datawriter error\n");
		dds_shutdown(ctx->participant);
		flb_errno();
		return -1;
	}

	ctx->fb_writer = FBDataWriter_narrow(ctx->writer);
	if (ctx->fb_writer == NULL) {
		flb_error("[out_dds] DataWriter narrow error\n");
		dds_shutdown(ctx->participant);
		flb_errno();
		return -1;
	}

	/* Create data sample for writing */
	ctx->instance = FBTypeSupport_create_data_ex(DDS_BOOLEAN_TRUE);
	if (ctx->instance == NULL) {
		flb_error("[out_dds] FBTypeSupport_create_data error\n");
		dds_shutdown(ctx->participant);
		flb_errno();
		return -1;
	}

	ctx->instance_handle = DDS_HANDLE_NIL;

	/* For data type that has key, if the same instance is going to be
	   written multiple times, initialize the key here
	   and register the keyed instance prior to writing */
	/*
	   instance_handle = FBDataWriter_register_instance(
	   fb_writer, instance);
	   */

	/* Export context */
	flb_output_set_context(ins, ctx);
	flb_info("[out_dds] domain_id=%d", ctx->domain_id);
	return 0;
}

static void cb_dds_flush(const void *data, size_t bytes,
		const char *tag, int tag_len,
		struct flb_input_instance *i_ins,
		void *out_context,
		struct flb_config *config) {

	int i;
	size_t off = 0;
	struct flb_out_dds_config *ctx = out_context;
	struct flb_time tms;
	msgpack_object *obj;
	msgpack_unpacked result;
	msgpack_object key;
	msgpack_object value;
	Record *record;
	DDS_ReturnCode_t retcode;

	msgpack_unpacked_init(&result);

	while(msgpack_unpack_next(&result, data, bytes, &off) == MSGPACK_UNPACK_SUCCESS) {
		flb_time_pop_from_msgpack(&tms, &result, &obj);

		strcpy(ctx->instance->tag, tag);
		ctx->instance->ts = flb_time_to_double(&tms);
		RecordSeq_set_length(&ctx->instance->records, obj->via.map.size);

		for (i = 0; i < obj->via.map.size; i++) {
			record = RecordSeq_get_reference(&ctx->instance->records, i);
			key = obj->via.map.ptr[i].key;
			value = obj->via.map.ptr[i].val;

			strncpy(record->key, key.via.str.ptr, key.via.str.size);

			switch(value.type) {
				case MSGPACK_OBJECT_NIL:
					break;
				case MSGPACK_OBJECT_BOOLEAN:
					break;
				case MSGPACK_OBJECT_POSITIVE_INTEGER:
					record->value._d = POSITIVE_INTEGER;
					record->value._u.u64 = value.via.u64;
					break;
				case MSGPACK_OBJECT_NEGATIVE_INTEGER:
					record->value._d = NEGATIVE_INTEGER;
					record->value._u.u64 = value.via.i64;
					break;
				case MSGPACK_OBJECT_FLOAT64:
					record->value._d = FLOAT64;
					record->value._u.f64 = value.via.f64;
					break;
				case MSGPACK_OBJECT_STR:
					record->value._d = STR;
					strncpy(record->value._u.str, value.via.str.ptr, value.via.str.size);
					break;
				case MSGPACK_OBJECT_FLOAT32:
					break;
				case MSGPACK_OBJECT_BIN:
					break;
				case MSGPACK_OBJECT_EXT:
					break;
				case MSGPACK_OBJECT_ARRAY:
					break;
				case MSGPACK_OBJECT_MAP:
					break;
				default:
					flb_warn("[%s] unknown msgpack type %d", __FUNCTION__, value.type);
			}
		}

		retcode = FBDataWriter_write(ctx->fb_writer, ctx->instance, &(ctx->instance_handle));
		if (retcode != DDS_RETCODE_OK) {
			flb_warn("[%s] writer error %d", __FUNCTION__, retcode);
		}
		RecordSeq_set_length(&ctx->instance->records, 0);
	}

	msgpack_unpacked_destroy(&result);
	FLB_OUTPUT_RETURN(FLB_OK);
}

static int cb_dds_exit(void *data, struct flb_config *config) {
	struct flb_out_dds_config *ctx = data;
	if (!ctx) {
		return 0;
	}

	if (ctx->participant) {
		dds_shutdown(ctx->participant);

	}

	flb_free(ctx);

	return 0;
}

struct flb_output_plugin out_dds_plugin = {
	.name         = "dds",
	.description  = "DDS Output Plugin",
	.cb_init      = cb_dds_init,
	.cb_flush     = cb_dds_flush,
	.cb_exit      = cb_dds_exit,
	.flags        = 0
};

