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

/* A collection of macro, constants and functions shared between the plugins 
 */

#ifndef __FLB_COMMON_H_INCLUDED__
#define __FLB_COMMON_H_INCLUDED__

#include "ndds/ndds_c.h"
#include <fluent-bit/flb_log.h>
#include <fluent-bit/flb_output.h>

// Stringification...
// I.e.:
//      #define FOO     5
//      RTI_STR(FOO)   -> "FOO"
//      RTI_XSTR(FOO)  -> "5"
//
#define RTI_XSTR(s)             RTI_STR(s)
#define RTI_STR(s)              #s


// A quick macro to check for out of memory conditions.
// usage:
//      char *foo = malloc(xx);
//      OOM_CHECK(foo);
// Prints the name of the variable that failed to allocate and call abort
// in case of out of memory
//
static inline RTIBool OOM_CHECK_fn(const void *ptr, const char *ptrName, const char *fnFile, int fnLoc) {
    if (!ptr) {
        flb_error("OUT OF MEMORY: ptr=%s at %s:%d", ptrName, fnFile, fnLoc);
#ifdef DEBUG
        abort();
#else
        return RTI_FALSE;
#endif
    }
    return RTI_TRUE;
}

// #define OOM_CHECK(ptr)      if (!(ptr)) do { flb_error("OUT OF MEMORY: " RTI_XSTR(ptr)); abort(); } while(0)
#define OOM_CHECK(ptr)          OOM_CHECK_fn(ptr, RTI_XSTR(ptr), __FUNCTION__, __LINE__)


// The maximum number of XMLFile_x parameters supported
#define MAX_XML_FILE        10

struct FBCommon_DDSConfig {
    const char *domainParticipantName;
    const char *dataWriterName;
    const char *XMLFile[MAX_XML_FILE];
    int XMLFileCount;
    const char *typeRegName;
};

void FBCommon_DDSConfig_init(struct FBCommon_DDSConfig *me);

// Returns RTI_TRUE if success, or RTI_FALSE in case of parse error
RTIBool FBCommon_parseArguments(struct flb_output_instance *ins,
        struct FBCommon_DDSConfig *ddsArgs);


// Modifies the DDS_DomainParticipantFactory of the factory singleton to add the
// given files to the list of files to load
RTIBool FBCommon_setXMLFilesToFactoryQoS(const char **xmlFile, int xmlFileCount);


// Returns RTI_TRUE if success, or RTI_FALSE in case of error
RTIBool FBCommon_createDDSEntities(struct FBCommon_DDSConfig *ddsArgs,
        DDS_DomainParticipant **participant,
        DDS_DataWriter **writer);

#endif          // !defined(__FLB_COMMON_H_INCLUDED__)
