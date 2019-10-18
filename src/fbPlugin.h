

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from fb.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef fbPlugin_1282814932_h
#define fbPlugin_1282814932_h

#include "fb.h"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
ValueKindPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
ValueKindPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ValueKindPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern void
ValueKindPluginSupport_print_data(
    const ValueKind *sample, const char *desc, int indent_level);

#define ValuePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

#define ValuePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ValuePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define ValuePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ValuePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern Value*
ValuePluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern Value*
ValuePluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern Value*
ValuePluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ValuePluginSupport_copy_data(
    Value *out,
    const Value *in);

NDDSUSERDllExport extern void 
ValuePluginSupport_destroy_data_w_params(
    Value *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
ValuePluginSupport_destroy_data_ex(
    Value *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ValuePluginSupport_destroy_data(
    Value *sample);

NDDSUSERDllExport extern void 
ValuePluginSupport_print_data(
    const Value *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ValuePlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ValuePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
ValuePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ValuePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
ValuePlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    Value *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
ValuePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    Value *out,
    const Value *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
ValuePlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const Value *sample); 

NDDSUSERDllExport extern RTIBool
ValuePlugin_serialize_to_cdr_buffer_ex(
    char *buffer,
    unsigned int *length,
    const Value *sample,
    DDS_DataRepresentationId_t representation);

NDDSUSERDllExport extern RTIBool 
ValuePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    Value **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
ValuePlugin_deserialize_from_cdr_buffer(
    Value *sample,
    const char * buffer,
    unsigned int length);    
#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport extern DDS_ReturnCode_t
ValuePlugin_data_to_string(
    const Value *sample,
    char *str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property);    
#endif

NDDSUSERDllExport extern unsigned int 
ValuePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
ValuePlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ValuePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ValuePlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ValuePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    Value ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern
struct RTIXCdrInterpreterPrograms *ValuePlugin_get_programs();

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ValuePlugin_new(void);

NDDSUSERDllExport extern void
ValuePlugin_delete(struct PRESTypePlugin *);

#define RecordPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

#define RecordPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define RecordPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define RecordPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define RecordPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern Record*
RecordPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern Record*
RecordPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern Record*
RecordPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
RecordPluginSupport_copy_data(
    Record *out,
    const Record *in);

NDDSUSERDllExport extern void 
RecordPluginSupport_destroy_data_w_params(
    Record *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
RecordPluginSupport_destroy_data_ex(
    Record *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
RecordPluginSupport_destroy_data(
    Record *sample);

NDDSUSERDllExport extern void 
RecordPluginSupport_print_data(
    const Record *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
RecordPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
RecordPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
RecordPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
RecordPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
RecordPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    Record *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
RecordPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    Record *out,
    const Record *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
RecordPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const Record *sample); 

NDDSUSERDllExport extern RTIBool
RecordPlugin_serialize_to_cdr_buffer_ex(
    char *buffer,
    unsigned int *length,
    const Record *sample,
    DDS_DataRepresentationId_t representation);

NDDSUSERDllExport extern RTIBool 
RecordPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    Record **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
RecordPlugin_deserialize_from_cdr_buffer(
    Record *sample,
    const char * buffer,
    unsigned int length);    
#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport extern DDS_ReturnCode_t
RecordPlugin_data_to_string(
    const Record *sample,
    char *str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property);    
#endif

NDDSUSERDllExport extern unsigned int 
RecordPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
RecordPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
RecordPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
RecordPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
RecordPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    Record ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern
struct RTIXCdrInterpreterPrograms *RecordPlugin_get_programs();

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
RecordPlugin_new(void);

NDDSUSERDllExport extern void
RecordPlugin_delete(struct PRESTypePlugin *);

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct FB
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct FB)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* FB must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct FB.
*/
typedef  struct FB FBKeyHolder;

#define FBPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

#define FBPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define FBPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define FBPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define FBPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define FBPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define FBPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern FB*
FBPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern FB*
FBPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern FB*
FBPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
FBPluginSupport_copy_data(
    FB *out,
    const FB *in);

NDDSUSERDllExport extern void 
FBPluginSupport_destroy_data_w_params(
    FB *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
FBPluginSupport_destroy_data_ex(
    FB *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
FBPluginSupport_destroy_data(
    FB *sample);

NDDSUSERDllExport extern void 
FBPluginSupport_print_data(
    const FB *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern FB*
FBPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern FB*
FBPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
FBPluginSupport_destroy_key_ex(
    FBKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
FBPluginSupport_destroy_key(
    FBKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
FBPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
FBPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
FBPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
FBPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
FBPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    FB *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
FBPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    FB *out,
    const FB *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
FBPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const FB *sample); 

NDDSUSERDllExport extern RTIBool
FBPlugin_serialize_to_cdr_buffer_ex(
    char *buffer,
    unsigned int *length,
    const FB *sample,
    DDS_DataRepresentationId_t representation);

NDDSUSERDllExport extern RTIBool 
FBPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    FB **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
FBPlugin_deserialize_from_cdr_buffer(
    FB *sample,
    const char * buffer,
    unsigned int length);    
#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport extern DDS_ReturnCode_t
FBPlugin_data_to_string(
    const FB *sample,
    char *str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property);    
#endif

NDDSUSERDllExport extern unsigned int 
FBPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
FBPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
FBPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
FBPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
FBPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    FB ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
FBPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    FBKeyHolder *key, 
    const FB *instance);

NDDSUSERDllExport extern RTIBool 
FBPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    FB *instance, 
    const FBKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
FBPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const FB *instance,
    RTIEncapsulationId encapsulationId);

NDDSUSERDllExport extern RTIBool 
FBPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

NDDSUSERDllExport extern
struct RTIXCdrInterpreterPrograms *FBPlugin_get_programs();

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
FBPlugin_new(void);

NDDSUSERDllExport extern void
FBPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* fbPlugin_1282814932_h */

