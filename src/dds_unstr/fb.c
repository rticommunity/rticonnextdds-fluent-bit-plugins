

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from fb.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#ifndef dds_c_log_infrastructure_h                      
#include "dds_c/dds_c_infrastructure_impl.h"       
#endif 

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "fb.h"

#ifndef NDDS_STANDALONE_TYPE
#include "fbPlugin.h"
#endif

/* ========================================================================= */
const char *ValueKindTYPENAME = "ValueKind";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* ValueKind_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member ValueKind_g_tc_members[12]=
    {

        {
            (char *)"NIL",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            NIL, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"BOOLEAN",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BOOLEAN, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"POSITIVE_INTEGER",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            POSITIVE_INTEGER, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"NEGATIVE_INTEGER",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            NEGATIVE_INTEGER, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"FLOAT32",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            FLOAT32, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"FLOAT64",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            FLOAT64, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"FLOAT",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            FLOAT, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"STR",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            STR, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"ARRAY",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            ARRAY, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"MAP",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            MAP, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"BIN",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            BIN, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"EXT",/* Member name */
            {
                0, /* Ignored */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            EXT, 
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Member visibility */ 

            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode ValueKind_g_tc =
    {{
            DDS_TK_ENUM, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ValueKind", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            12, /* Number of members */
            ValueKind_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for ValueKind*/

    if (is_initialized) {
        return &ValueKind_g_tc;
    }

    ValueKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    /* Initialize the values for annotations. */
    ValueKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    ValueKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

    ValueKind_g_tc._data._sampleAccessInfo =
    ValueKind_get_sample_access_info();
    ValueKind_g_tc._data._typePlugin =
    ValueKind_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &ValueKind_g_tc;
}

RTIXCdrSampleAccessInfo *ValueKind_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo ValueKind_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo ValueKind_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &ValueKind_g_sampleAccessInfo;
    }

    ValueKind_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

    ValueKind_g_sampleAccessInfo.memberAccessInfos = 
    ValueKind_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(ValueKind);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            ValueKind_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            ValueKind_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    ValueKind_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &ValueKind_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *ValueKind_get_type_plugin_info()
{
    static RTIXCdrTypePlugin ValueKind_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        ValueKind_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        ValueKind_finalize,
        NULL
    };

    return &ValueKind_g_typePlugin;
}
#endif

RTIBool ValueKind_initialize(
    ValueKind* sample) {
    *sample = NIL;
    return RTI_TRUE;
}

RTIBool ValueKind_initialize_ex(
    ValueKind* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ValueKind_initialize_w_params(
        sample,&allocParams);

}

RTIBool ValueKind_initialize_w_params(
    ValueKind* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    *sample = NIL;
    return RTI_TRUE;
}

void ValueKind_finalize(
    ValueKind* sample)
{

    if (sample==NULL) {
        return;
    }
}

void ValueKind_finalize_ex(
    ValueKind* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ValueKind_finalize_w_params(
        sample,&deallocParams);
}

void ValueKind_finalize_w_params(
    ValueKind* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void ValueKind_finalize_optional_members(
    ValueKind* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool ValueKind_copy(
    ValueKind* dst,
    const ValueKind* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'ValueKind' sequence class.
*/
#define T ValueKind
#define TSeq ValueKindSeq

#define T_initialize_w_params ValueKind_initialize_w_params

#define T_finalize_w_params   ValueKind_finalize_w_params
#define T_copy       ValueKind_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *ValueTYPENAME = "Value";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* Value_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Value_g_tc_str_string = DDS_INITIALIZE_STRING_TYPECODE(((MAX_STR_LEN)));

    static DDS_TypeCode_Member Value_g_tc_members[6]=
    {

        {
            (char *)"b",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            1, /* Number of labels */
            (BOOLEAN), /* First label C (BOOLEAN) */
            NULL, /* Labels (it is NULL when there is only one label)*/
            RTI_CDR_NONKEY_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"u64",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            1, /* Number of labels */
            (POSITIVE_INTEGER), /* First label C (POSITIVE_INTEGER) */
            NULL, /* Labels (it is NULL when there is only one label)*/
            RTI_CDR_NONKEY_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"i64",/* Member name */
            {
                3,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            1, /* Number of labels */
            (NEGATIVE_INTEGER), /* First label C (NEGATIVE_INTEGER) */
            NULL, /* Labels (it is NULL when there is only one label)*/
            RTI_CDR_NONKEY_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"f32",/* Member name */
            {
                4,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            1, /* Number of labels */
            (FLOAT32), /* First label C (FLOAT32) */
            NULL, /* Labels (it is NULL when there is only one label)*/
            RTI_CDR_NONKEY_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"f64",/* Member name */
            {
                5,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            1, /* Number of labels */
            (FLOAT64), /* First label C (FLOAT64) */
            NULL, /* Labels (it is NULL when there is only one label)*/
            RTI_CDR_NONKEY_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"str",/* Member name */
            {
                6,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            1, /* Number of labels */
            (STR), /* First label C (STR) */
            NULL, /* Labels (it is NULL when there is only one label)*/
            RTI_CDR_NONKEY_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Value_g_tc =
    {{
            DDS_TK_UNION, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Value", /* Name */
            NULL,     /* Base class type code is assigned later */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            6, /* Number of members */
            Value_g_tc_members, /* Members */
            DDS_VM_NONE, /* Type Modifier */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Value*/

    if (is_initialized) {
        return &Value_g_tc;
    }

    Value_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Value_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;
    Value_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
    Value_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_longlong;
    Value_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
    Value_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    Value_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&Value_g_tc_str_string;

    /* Initialize the values for member annotations. */
    Value_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
    Value_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

    Value_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
    Value_g_tc_members[1]._annotations._defaultValue._u.ulong_long_value = 0ull;
    Value_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
    Value_g_tc_members[1]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
    Value_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
    Value_g_tc_members[1]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

    Value_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_LONGLONG;
    Value_g_tc_members[2]._annotations._defaultValue._u.long_long_value = 0ll;
    Value_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_LONGLONG;
    Value_g_tc_members[2]._annotations._minValue._u.long_long_value = RTIXCdrLongLong_MIN;
    Value_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_LONGLONG;
    Value_g_tc_members[2]._annotations._maxValue._u.long_long_value = RTIXCdrLongLong_MAX;

    Value_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
    Value_g_tc_members[3]._annotations._defaultValue._u.float_value = 0.0f;
    Value_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
    Value_g_tc_members[3]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
    Value_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
    Value_g_tc_members[3]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

    Value_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
    Value_g_tc_members[4]._annotations._defaultValue._u.double_value = 0.0;
    Value_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
    Value_g_tc_members[4]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
    Value_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
    Value_g_tc_members[4]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;

    Value_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    Value_g_tc_members[5]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    /* Discriminator type code */
    Value_g_tc._data._typeCode = (RTICdrTypeCode *)ValueKind_get_typecode();

    Value_g_tc._data._sampleAccessInfo =
    Value_get_sample_access_info();
    Value_g_tc._data._typePlugin =
    Value_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Value_g_tc;
}

RTIXCdrSampleAccessInfo *Value_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo Value_g_memberAccessInfos[7] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Value_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Value_g_sampleAccessInfo;
    }

    Value_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((Value *)NULL)->_d);

    Value_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((Value *)NULL)->_u.b);

    Value_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((Value *)NULL)->_u.u64);

    Value_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((Value *)NULL)->_u.i64);

    Value_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((Value *)NULL)->_u.f32);

    Value_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((Value *)NULL)->_u.f64);

    Value_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((Value *)NULL)->_u.str);

    Value_g_sampleAccessInfo.memberAccessInfos = 
    Value_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Value);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Value_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Value_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Value_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Value_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Value_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Value_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Value_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Value_finalize,
        NULL
    };

    return &Value_g_typePlugin;
}
#endif

DDS_LongLong Value_getDefaultDiscriminator(){

    return 1;
}

RTIBool Value_initialize(
    Value* sample) {
    return Value_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Value_initialize_ex(
    Value* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Value_initialize_w_params(
        sample,&allocParams);

}

RTIBool Value_initialize_w_params(
    Value* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->_d = (ValueKind)Value_getDefaultDiscriminator();

    sample->_u.b = 0;

    sample->_u.u64 = 0ull;

    sample->_u.i64 = 0ll;

    sample->_u.f32 = 0.0f;

    sample->_u.f64 = 0.0;

    if (allocParams->allocate_memory) {
        sample->_u.str = DDS_String_alloc(((MAX_STR_LEN)));
        RTICdrType_copyStringEx(
            &sample->_u.str,
            "",
            ((MAX_STR_LEN)),
            RTI_FALSE);
        if (sample->_u.str == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->_u.str != NULL) {
            RTICdrType_copyStringEx(
                &sample->_u.str,
                "",
                ((MAX_STR_LEN)),
                RTI_FALSE);
            if (sample->_u.str == NULL) {
                return RTI_FALSE;
            }
        }
    }

    return RTI_TRUE;
}

void Value_finalize(
    Value* sample)
{

    Value_finalize_ex(sample,RTI_TRUE);
}

void Value_finalize_ex(
    Value* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Value_finalize_w_params(
        sample,&deallocParams);
}

void Value_finalize_w_params(
    Value* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->_u.str != NULL) {
        DDS_String_free(sample->_u.str);
        sample->_u.str=NULL;

    }
}

void Value_finalize_optional_members(
    Value* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    switch(sample->_d) {
        case (BOOLEAN):
            {
        } break ;
        case (POSITIVE_INTEGER):
            {
        } break ;
        case (NEGATIVE_INTEGER):
            {
        } break ;
        case (FLOAT32):
            {
        } break ;
        case (FLOAT64):
            {
        } break ;
        case (STR):
            {
        } break ;
        default: 
        {
            /* 
            * Prevents compiler warnings when discriminator is an enum
            * and unionType does not specify all enumeration members.
            */ 
        }
    }
}

RTIBool Value_copy(
    Value* dst,
    const Value* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    if (!ValueKind_copy(
        &dst->_d,(const ValueKind*)&src->_d)) {
        return RTI_FALSE;
    } 

    switch(src->_d) {

        case (BOOLEAN):
            {
                if (!RTICdrType_copyBoolean (
                    &dst->_u.b, &src->_u.b)) { 
                    return RTI_FALSE;
            }
        } break ;
        case (POSITIVE_INTEGER):
            {
                if (!RTICdrType_copyUnsignedLongLong (
                    &dst->_u.u64, &src->_u.u64)) { 
                    return RTI_FALSE;
            }
        } break ;
        case (NEGATIVE_INTEGER):
            {
                if (!RTICdrType_copyLongLong (
                    &dst->_u.i64, &src->_u.i64)) { 
                    return RTI_FALSE;
            }
        } break ;
        case (FLOAT32):
            {
                if (!RTICdrType_copyFloat (
                    &dst->_u.f32, &src->_u.f32)) { 
                    return RTI_FALSE;
            }
        } break ;
        case (FLOAT64):
            {
                if (!RTICdrType_copyDouble (
                    &dst->_u.f64, &src->_u.f64)) { 
                    return RTI_FALSE;
            }
        } break ;
        case (STR):
            {
                if (!RTICdrType_copyStringEx (
                    &dst->_u.str, src->_u.str, 
                    ((MAX_STR_LEN)) + 1, RTI_FALSE)){
                    return RTI_FALSE;
            }
        } break ;

        default: 
        {
            /* 
            * Prevents compiler warnings when discriminator is an enum
            * and unionType does not specify all enumeration members.
            */ 
        }
    }
    return RTI_TRUE;

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Value' sequence class.
*/
#define T Value
#define TSeq ValueSeq

#define T_initialize_w_params Value_initialize_w_params

#define T_finalize_w_params   Value_finalize_w_params
#define T_copy       Value_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *RecordTYPENAME = "Record";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* Record_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Record_g_tc_key_string = DDS_INITIALIZE_STRING_TYPECODE(((MAX_KEY_LEN)));

    static DDS_TypeCode_Member Record_g_tc_members[2]=
    {

        {
            (char *)"key",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"value",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Record_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Record", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            Record_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Record*/

    if (is_initialized) {
        return &Record_g_tc;
    }

    Record_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    Record_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&Record_g_tc_key_string;
    Record_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)Value_get_typecode();

    /* Initialize the values for member annotations. */
    Record_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    Record_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    Record_g_tc._data._sampleAccessInfo =
    Record_get_sample_access_info();
    Record_g_tc._data._typePlugin =
    Record_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Record_g_tc;
}

RTIXCdrSampleAccessInfo *Record_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo Record_g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Record_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Record_g_sampleAccessInfo;
    }

    Record_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((Record *)NULL)->key);

    Record_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((Record *)NULL)->value);

    Record_g_sampleAccessInfo.memberAccessInfos = 
    Record_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(Record);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            Record_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            Record_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    Record_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Record_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Record_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Record_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        Record_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        Record_finalize,
        NULL
    };

    return &Record_g_typePlugin;
}
#endif

RTIBool Record_initialize(
    Record* sample) {
    return Record_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool Record_initialize_ex(
    Record* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return Record_initialize_w_params(
        sample,&allocParams);

}

RTIBool Record_initialize_w_params(
    Record* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        sample->key = DDS_String_alloc(((MAX_KEY_LEN)));
        RTICdrType_copyStringEx(
            &sample->key,
            "",
            ((MAX_KEY_LEN)),
            RTI_FALSE);
        if (sample->key == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->key != NULL) {
            RTICdrType_copyStringEx(
                &sample->key,
                "",
                ((MAX_KEY_LEN)),
                RTI_FALSE);
            if (sample->key == NULL) {
                return RTI_FALSE;
            }
        }
    }

    if (!Value_initialize_w_params(&sample->value,
    allocParams)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

void Record_finalize(
    Record* sample)
{

    Record_finalize_ex(sample,RTI_TRUE);
}

void Record_finalize_ex(
    Record* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    Record_finalize_w_params(
        sample,&deallocParams);
}

void Record_finalize_w_params(
    Record* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->key != NULL) {
        DDS_String_free(sample->key);
        sample->key=NULL;

    }
    Value_finalize_w_params(&sample->value,deallocParams);

}

void Record_finalize_optional_members(
    Record* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    Value_finalize_optional_members(&sample->value, deallocParams->delete_pointers);
}

RTIBool Record_copy(
    Record* dst,
    const Record* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_copyStringEx (
        &dst->key, src->key, 
        ((MAX_KEY_LEN)) + 1, RTI_FALSE)){
        return RTI_FALSE;
    }
    if (!Value_copy(
        &dst->value,(const Value*)&src->value)) {
        return RTI_FALSE;
    } 

    return RTI_TRUE;

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Record' sequence class.
*/
#define T Record
#define TSeq RecordSeq

#define T_initialize_w_params Record_initialize_w_params

#define T_finalize_w_params   Record_finalize_w_params
#define T_copy       Record_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *FBTYPENAME = "FB";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* FB_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode FB_g_tc_tag_string = DDS_INITIALIZE_STRING_TYPECODE(((MAX_TAG_LEN)));
    static DDS_TypeCode FB_g_tc_records_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE(((MAX_RECORDS)),NULL);

    static DDS_TypeCode_Member FB_g_tc_members[3]=
    {

        {
            (char *)"ts",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"tag",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_KEY_MEMBER , /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"records",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode FB_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"FB", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            FB_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for FB*/

    if (is_initialized) {
        return &FB_g_tc;
    }

    FB_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    FB_g_tc_records_sequence._data._typeCode = (RTICdrTypeCode *)Record_get_typecode();
    FB_g_tc_records_sequence._data._sampleAccessInfo = &DDS_g_sai_seq;
    FB_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
    FB_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&FB_g_tc_tag_string;
    FB_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& FB_g_tc_records_sequence;

    /* Initialize the values for member annotations. */
    FB_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
    FB_g_tc_members[0]._annotations._defaultValue._u.double_value = 0.0;
    FB_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
    FB_g_tc_members[0]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
    FB_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
    FB_g_tc_members[0]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;

    FB_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    FB_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    FB_g_tc._data._sampleAccessInfo =
    FB_get_sample_access_info();
    FB_g_tc._data._typePlugin =
    FB_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &FB_g_tc;
}

RTIXCdrSampleAccessInfo *FB_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo FB_g_memberAccessInfos[3] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo FB_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &FB_g_sampleAccessInfo;
    }

    FB_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((FB *)NULL)->ts);

    FB_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((FB *)NULL)->tag);

    FB_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((FB *)NULL)->records);

    FB_g_sampleAccessInfo.memberAccessInfos = 
    FB_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(FB);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            FB_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            FB_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    FB_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &FB_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *FB_get_type_plugin_info()
{
    static RTIXCdrTypePlugin FB_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        FB_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        FB_finalize,
        NULL
    };

    return &FB_g_typePlugin;
}
#endif

RTIBool FB_initialize(
    FB* sample) {
    return FB_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool FB_initialize_ex(
    FB* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return FB_initialize_w_params(
        sample,&allocParams);

}

RTIBool FB_initialize_w_params(
    FB* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    void* buffer = NULL;
    if (buffer) {} /* To avoid warnings */

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->ts = 0.0;

    if (allocParams->allocate_memory) {
        sample->tag = DDS_String_alloc(((MAX_TAG_LEN)));
        RTICdrType_copyStringEx(
            &sample->tag,
            "",
            ((MAX_TAG_LEN)),
            RTI_FALSE);
        if (sample->tag == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->tag != NULL) {
            RTICdrType_copyStringEx(
                &sample->tag,
                "",
                ((MAX_TAG_LEN)),
                RTI_FALSE);
            if (sample->tag == NULL) {
                return RTI_FALSE;
            }
        }
    }

    if (allocParams->allocate_memory) {
        if(!RecordSeq_initialize(&sample->records )){
            return RTI_FALSE;
        };
        if(!RecordSeq_set_element_allocation_params(&sample->records ,allocParams)){
            return RTI_FALSE;
        };
        if(!RecordSeq_set_absolute_maximum(&sample->records , ((MAX_RECORDS)))){
            return RTI_FALSE;
        }
        if (!RecordSeq_set_maximum(&sample->records, ((MAX_RECORDS)))) {
            return RTI_FALSE;
        }
    } else { 
        if(!RecordSeq_set_length(&sample->records, 0)){
            return RTI_FALSE;
        }    
    }
    return RTI_TRUE;
}

void FB_finalize(
    FB* sample)
{

    FB_finalize_ex(sample,RTI_TRUE);
}

void FB_finalize_ex(
    FB* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    FB_finalize_w_params(
        sample,&deallocParams);
}

void FB_finalize_w_params(
    FB* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->tag != NULL) {
        DDS_String_free(sample->tag);
        sample->tag=NULL;

    }
    if(!RecordSeq_set_element_deallocation_params(
        &sample->records,deallocParams)){
        return; 
    }
    if(!RecordSeq_finalize(&sample->records)){
        return;
    }

}

void FB_finalize_optional_members(
    FB* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    {
        DDS_UnsignedLong i, length;
        length = RecordSeq_get_length(
            &sample->records);

        for (i = 0; i < length; i++) {
            Record_finalize_optional_members(
                RecordSeq_get_reference(
                    &sample->records, i), deallocParams->delete_pointers);
        }
    }  

}

RTIBool FB_copy(
    FB* dst,
    const FB* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_copyDouble (
        &dst->ts, &src->ts)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyStringEx (
        &dst->tag, src->tag, 
        ((MAX_TAG_LEN)) + 1, RTI_FALSE)){
        return RTI_FALSE;
    }
    if (!RecordSeq_copy(&dst->records ,
    &src->records )) {
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'FB' sequence class.
*/
#define T FB
#define TSeq FBSeq

#define T_initialize_w_params FB_initialize_w_params

#define T_finalize_w_params   FB_finalize_w_params
#define T_copy       FB_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

