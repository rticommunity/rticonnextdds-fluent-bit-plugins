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

#ifndef __FLB_OUT_DDS_STR_H_INCLUDED__
#define __FLB_OUT_DDS_STR_H_INCLUDED__

#include <fluent-bit/flb_info.h>
#include <fluent-bit/flb_output.h>
#include <fluent-bit/flb_time.h>
#include <fluent-bit/flb_pack.h>
#include <stdio.h>
#include <stdlib.h>
#include "ndds/ndds_c.h"

typedef enum PrecisionLossAction_t {
    PrecisionLossAction_NONE,
    PrecisionLossAction_WARN,
    PrecisionLossAction_WARN_ONCE,
    PrecisionLossAction_ABORT
} PrecisionLossAction;

#define DEFAULT_PRECISION_LOSS_ACTION   PrecisionLossAction_WARN

struct cJSON;

struct flb_out_dds_str_config {
	DDS_DomainParticipant *participant;
	DDS_DynamicDataWriter *writer;
        const DDS_TypeCode    * typeCode;
        struct DDS_DynamicDataTypeSupport *typeSupport;
        DDS_DynamicData *instance;
	DDS_InstanceHandle_t instance_handle;

        PrecisionLossAction     pcAction;       

        struct cJSON * typeMap;
};

#endif          // !defined(__FLB_OUT_DDS_STR_H_INCLUDED__)
