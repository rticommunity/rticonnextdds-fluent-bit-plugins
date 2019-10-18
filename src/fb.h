

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from fb.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef fb_1282814932_h
#define fb_1282814932_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

#define MAX_RECORDS (128)

#define MAX_STR_LEN (1024)
typedef enum ValueKind
{
    NIL ,      
    BOOLEAN ,      
    POSITIVE_INTEGER ,      
    NEGATIVE_INTEGER ,      
    FLOAT32 ,      
    FLOAT64 ,      
    FLOAT ,      
    STR ,      
    ARRAY ,      
    MAP ,      
    BIN ,      
    EXT      
} ValueKind;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* ValueKind_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *ValueKind_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *ValueKind_get_sample_access_info(void);
#endif

DDS_SEQUENCE(ValueKindSeq, ValueKind);

NDDSUSERDllExport
RTIBool ValueKind_initialize(
    ValueKind* self);

NDDSUSERDllExport
RTIBool ValueKind_initialize_ex(
    ValueKind* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool ValueKind_initialize_w_params(
    ValueKind* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
void ValueKind_finalize(
    ValueKind* self);

NDDSUSERDllExport
void ValueKind_finalize_ex(
    ValueKind* self,RTIBool deletePointers);

NDDSUSERDllExport
void ValueKind_finalize_w_params(
    ValueKind* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void ValueKind_finalize_optional_members(
    ValueKind* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool ValueKind_copy(
    ValueKind* dst,
    const ValueKind* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

extern const char *ValueTYPENAME;

typedef struct Value {

    ValueKind _d;
    struct Value_u 
    {

        DDS_Boolean   b ;
        DDS_UnsignedLongLong   u64 ;
        DDS_LongLong   i64 ;
        DDS_Float   f32 ;
        DDS_Double   f64 ;
        DDS_Char *   str ;
    }_u;

} Value ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* Value_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *Value_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Value_get_sample_access_info(void);
#endif

DDS_SEQUENCE(ValueSeq, Value);

NDDSUSERDllExport
RTIBool Value_initialize(
    Value* self);

NDDSUSERDllExport
RTIBool Value_initialize_ex(
    Value* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Value_initialize_w_params(
    Value* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
void Value_finalize(
    Value* self);

NDDSUSERDllExport
void Value_finalize_ex(
    Value* self,RTIBool deletePointers);

NDDSUSERDllExport
void Value_finalize_w_params(
    Value* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Value_finalize_optional_members(
    Value* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Value_copy(
    Value* dst,
    const Value* src);

NDDSUSERDllExport
DDS_LongLong Value_getDefaultDiscriminator();

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

extern const char *RecordTYPENAME;

typedef struct Record {

    DDS_Char *   key ;
    Value   value ;

} Record ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* Record_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *Record_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Record_get_sample_access_info(void);
#endif

DDS_SEQUENCE(RecordSeq, Record);

NDDSUSERDllExport
RTIBool Record_initialize(
    Record* self);

NDDSUSERDllExport
RTIBool Record_initialize_ex(
    Record* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Record_initialize_w_params(
    Record* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
void Record_finalize(
    Record* self);

NDDSUSERDllExport
void Record_finalize_ex(
    Record* self,RTIBool deletePointers);

NDDSUSERDllExport
void Record_finalize_w_params(
    Record* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Record_finalize_optional_members(
    Record* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Record_copy(
    Record* dst,
    const Record* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

extern const char *FBTYPENAME;

typedef struct FB {

    DDS_Double   ts ;
    DDS_Char *   tag ;
    struct    RecordSeq  records ;

} FB ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* FB_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *FB_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *FB_get_sample_access_info(void);
#endif

DDS_SEQUENCE(FBSeq, FB);

NDDSUSERDllExport
RTIBool FB_initialize(
    FB* self);

NDDSUSERDllExport
RTIBool FB_initialize_ex(
    FB* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool FB_initialize_w_params(
    FB* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
void FB_finalize(
    FB* self);

NDDSUSERDllExport
void FB_finalize_ex(
    FB* self,RTIBool deletePointers);

NDDSUSERDllExport
void FB_finalize_w_params(
    FB* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void FB_finalize_optional_members(
    FB* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool FB_copy(
    FB* dst,
    const FB* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* fb */

