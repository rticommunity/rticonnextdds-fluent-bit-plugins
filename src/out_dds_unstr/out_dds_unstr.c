/*******************************************************************************
 (c) 2005-2019 Copyright, Real-Time Innovations, Inc.  All rights reserved.
 RTI grants Licensee a license to use, modify, compile, and create derivative
 works of the Software.  Licensee has the right to distribute object form only
 for use with RTI products.  The Software is provided "as is", with no warranty
 of any type, including any warranty for fitness for any purpose. RTI is under
 no obligation to maintain or support the Software.  RTI shall not be liable for
 any incidental or consequential damages arising out of the use or inability to
 use the software.
 ******************************************************************************/

#include <fluent-bit/flb_info.h>
#include <fluent-bit/flb_output.h>
#include <fluent-bit/flb_time.h>
#include <fluent-bit/flb_pack.h>
#include <stdio.h>
#include <stdlib.h>
#include "fb.h"
#include "fbSupport.h"
#include "fbcommon.h"

struct flb_out_dds_unstr_config {
    int domain_id;

    DDS_DomainParticipant *participant;
    DDS_Publisher *publisher;
    DDS_Topic *topic;
    DDS_DataWriter *writer;
    FBDataWriter *fb_writer;
    const char *type_name;
    FB *instance;
    DDS_InstanceHandle_t instance_handle;
};


#define PLUGIN_NAME         "out_dds_unstr"

/* {{{ cb_dds_exit
 * -------------------------------------------------------------------------
 */
static int cb_dds_exit(void *data, 
        UNUSED_PARAM struct flb_config *config) {
    struct flb_out_dds_unstr_config *ctx = data;
    if (!ctx) {
        return 0;
    }

    if (ctx->participant) {
        FBCommon_shutdownDDS(ctx->participant);

    }

    flb_free(ctx);

    return 0;
}

// }}}
/* {{{ cb_dds_init
 * -------------------------------------------------------------------------
 */
static int cb_dds_init(struct flb_output_instance *ins,
        UNUSED_PARAM struct flb_config *config,
        UNUSED_PARAM void *data) {
    struct flb_out_dds_unstr_config *ctx;
    const char *tmp = NULL;
    DDS_ReturnCode_t retcode;
    struct FBCommon_DDSConfig argDDSConfig;

    ctx = flb_calloc(1, sizeof(struct flb_out_dds_unstr_config));
    if (!OOM_CHECK(ctx)) {
        goto err;
    }

    // Read configuration parameters
    FBCommon_DDSConfig_init(&argDDSConfig);
    if (!FBCommon_parseArguments(ins, &argDDSConfig)) {
        goto err;
    }

    // Get Domain ID
    tmp = flb_output_get_property("domain_id", ins);
    if (tmp != NULL && atoi(tmp) >= 0) {
        ctx->domain_id = atoi(tmp);
    }
    else {
        ctx->domain_id = 0;
    }

    if (argDDSConfig.XMLFileCount > 0) {
        if (!FBCommon_setXMLFilesToFactoryQoS(argDDSConfig.XMLFile, argDDSConfig.XMLFileCount)) {
            goto err;
        }
    } 
    ctx->participant = DDS_DomainParticipantFactory_create_participant(
            DDS_TheParticipantFactory, ctx->domain_id, &DDS_PARTICIPANT_QOS_DEFAULT,
            NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (ctx->participant == NULL) {
        flb_error("[%s] create_participant error\n", PLUGIN_NAME);
        FBCommon_shutdownDDS(ctx->participant);
        goto err;
    }

    /* To customize publisher QoS, use
       DDS_DomainParticipant_get_default_publisher_qos() instead */
    ctx->publisher = DDS_DomainParticipant_create_publisher(
            ctx->participant, &DDS_PUBLISHER_QOS_DEFAULT, NULL /* listener */,
            DDS_STATUS_MASK_NONE);
    if (ctx->publisher == NULL) {
        flb_error("[%s] create_publisher error\n", PLUGIN_NAME);
        FBCommon_shutdownDDS(ctx->participant);
        goto err;
    }

    /* Register type before creating topic */
    ctx->type_name = FBTypeSupport_get_type_name();
    retcode = FBTypeSupport_register_type(
            ctx->participant, ctx->type_name);
    if (retcode != DDS_RETCODE_OK) {
        flb_error("[%s] register_type error %d\n", PLUGIN_NAME, retcode);
        FBCommon_shutdownDDS(ctx->participant);
        goto err;
    }

    /* To customize topic QoS, use
       DDS_DomainParticipant_get_default_topic_qos() instead */
    ctx->topic = DDS_DomainParticipant_create_topic(
            ctx->participant, "FluentBit",
            ctx->type_name, &DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
            DDS_STATUS_MASK_NONE);
    if (ctx->topic == NULL) {
        flb_error(" [%s] create_topic error\n", PLUGIN_NAME);
        FBCommon_shutdownDDS(ctx->participant);
        goto err;
    }

    /* To customize data writer QoS, use
       DDS_Publisher_get_default_datawriter_qos() instead */
    ctx->writer = DDS_Publisher_create_datawriter(
            ctx->publisher, ctx->topic,
            &DDS_DATAWRITER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (ctx->writer == NULL) {
        flb_error("[%s] create_datawriter error\n", PLUGIN_NAME);
        FBCommon_shutdownDDS(ctx->participant);
        goto err;
    }

    ctx->fb_writer = FBDataWriter_narrow(ctx->writer);
    if (ctx->fb_writer == NULL) {
        flb_error("[%s] DataWriter narrow error\n", PLUGIN_NAME);
        FBCommon_shutdownDDS(ctx->participant);
        goto err;
    }

    /* Create data sample for writing */
    ctx->instance = FBTypeSupport_create_data_ex(DDS_BOOLEAN_TRUE);
    if (ctx->instance == NULL) {
        flb_error("[%s] FBTypeSupport_create_data error\n", PLUGIN_NAME);
        FBCommon_shutdownDDS(ctx->participant);
        goto err;
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
    flb_info("[%s] domain_id=%d", PLUGIN_NAME, ctx->domain_id);
    return 0;

err:
    cb_dds_exit(ctx, NULL);
    return -1;
}

// }}}
/* {{{ cb_dds_flush
 * -------------------------------------------------------------------------
 */
static void cb_dds_flush(const void *data, 
        size_t bytes,
        UNUSED_PARAM const char *tag, 
        UNUSED_PARAM int tag_len,
        UNUSED_PARAM struct flb_input_instance *i_ins,
        void *out_context,
        UNUSED_PARAM struct flb_config *config) {
    size_t i;
    size_t off = 0;
    struct flb_out_dds_unstr_config *ctx = out_context;
    struct flb_time tms;
    size_t count = 0;
    msgpack_object *obj;
    msgpack_unpacked result;
    msgpack_object key;
    msgpack_object value;
    Record *record;
    DDS_ReturnCode_t retcode;

    msgpack_unpacked_init(&result);

    flb_debug("[%s]: got to flush some sample...", PLUGIN_NAME);
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

        flb_debug("[%s]: Writing record #%d (%d fields)", PLUGIN_NAME, ++count, obj->via.map.size);
        retcode = FBDataWriter_write(ctx->fb_writer, ctx->instance, &(ctx->instance_handle));
        if (retcode != DDS_RETCODE_OK) {
            flb_warn("[%s] writer error %d", PLUGIN_NAME, retcode);
        }
        RecordSeq_set_length(&ctx->instance->records, 0);
    }

    msgpack_unpacked_destroy(&result);
    FLB_OUTPUT_RETURN(FLB_OK);
}

// }}}
/* {{{ out_dds_unstr_plugin
 * -------------------------------------------------------------------------
 * The only public exported symbol of the shared library
 */
struct flb_output_plugin out_dds_unstr_plugin = {
    .name         = "dds_unstr",
    .description  = "DDS Unstructured Output Plugin",
    .cb_init      = cb_dds_init,
    .cb_flush     = cb_dds_flush,
    .cb_exit      = cb_dds_exit,
    .flags        = 0
};

