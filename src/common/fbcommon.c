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

#include "fbcommon.h"
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/* {{{ FBCommon_DDSConfig_init
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
void FBCommon_DDSConfig_init(struct FBCommon_DDSConfig *me) {
    memset(me, 0, sizeof(*me));
}

// }}}

/* {{{ FBCommon_parseArguments
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
RTIBool FBCommon_parseArguments(struct flb_output_instance *ins,
        struct FBCommon_DDSConfig *ddsArgs) {
    char fileCountKey[20];

    assert(ins);
    assert(ddsArgs);

    // Plain XMLFile only?
    ddsArgs->XMLFile[0] = flb_output_get_property("XMLFile", ins);
    if (ddsArgs->XMLFile[0]) {
        ddsArgs->XMLFileCount = 1;
    } else {
        // Attempt to read the XMLFile_0, XML_File_1 ...
        for (ddsArgs->XMLFileCount = 0; ddsArgs->XMLFileCount < MAX_XML_FILE; ++ddsArgs->XMLFileCount) {
            snprintf(fileCountKey, sizeof(fileCountKey), "XMLFile_%d", ddsArgs->XMLFileCount);
            ddsArgs->XMLFile[ddsArgs->XMLFileCount] = flb_output_get_property(fileCountKey, ins);
            if (!ddsArgs->XMLFile[ddsArgs->XMLFileCount]) {
                // Don't scan for all the keys, as soon as we don't find a key stop
                break;
            }
        }
        if (ddsArgs->XMLFileCount == MAX_XML_FILE) {
            flb_warn("This plugin support only %d XMLFile_xx keys", MAX_XML_FILE);
        }
    }

    ddsArgs->domainParticipantName = flb_output_get_property("DomainParticipant", ins);
    if (!ddsArgs->domainParticipantName) {
        flb_error("Missing required parameter 'DomainParticipant'");
        return RTI_FALSE;
    }

    ddsArgs->dataWriterName = flb_output_get_property("DataWriter", ins);
    if (!ddsArgs->dataWriterName) {
        flb_error("Missing required parameter 'DataWriter'");
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

// }}}
/* {{{ FBCommon_setXMLFilesToFactoryQoS
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
RTIBool FBCommon_setXMLFilesToFactoryQoS(const char **xmlFile, int xmlFileCount) {
    struct DDS_DomainParticipantFactoryQos factoryQos = DDS_DomainParticipantFactoryQos_INITIALIZER;
    DDS_ReturnCode_t rc;

    assert(xmlFile);

    if ((rc = DDS_DomainParticipantFactory_get_qos(DDS_TheParticipantFactory, &factoryQos)) != DDS_RETCODE_OK) {
        flb_error("Unable to get participant factory QoS: %d", rc);
        return RTI_FALSE;
    }
    if (!DDS_StringSeq_from_array(&factoryQos.profile.url_profile, xmlFile, xmlFileCount)) {
        flb_error("Failed to copy XML file list from array");
        return RTI_FALSE;
    }
    if ((rc = DDS_DomainParticipantFactory_set_qos(DDS_TheParticipantFactory, &factoryQos)) != DDS_RETCODE_OK) {
        flb_error("Unable to set participant factory QoS: %d", rc);
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

// }}}
/* {{{ FBCommon_createDDSEntities
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */
RTIBool FBCommon_createDDSEntities(struct FBCommon_DDSConfig *ddsArgs,
        DDS_DomainParticipant **participant,
        DDS_DataWriter **writer) {

    assert(ddsArgs);
    assert(participant);
    assert(writer);

    if (ddsArgs->XMLFileCount > 0) {
        if (!FBCommon_setXMLFilesToFactoryQoS(ddsArgs->XMLFile, ddsArgs->XMLFileCount)) {
            return RTI_FALSE;
        }
    }

    *participant = DDS_DomainParticipantFactory_create_participant_from_config(DDS_TheParticipantFactory, 
            ddsArgs->domainParticipantName);
    if (!*participant) {
        flb_error("Failed to create domain participant '%s'", ddsArgs->domainParticipantName);
        return RTI_FALSE;
    }
    
    *writer = DDS_DomainParticipant_lookup_datawriter_by_name(*participant, ddsArgs->dataWriterName);
    if (!*writer) {
        flb_error("Cannot find data writer '%s' in domain participant", ddsArgs->dataWriterName);
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

// }}}
/* {{{ FBCommon_readFile
 * -------------------------------------------------------------------------
 */
char * FBCommon_readFile(const char *path, size_t *sizeOut) {
    RTIBool ok = RTI_FALSE;
    FILE *f = NULL;
    struct stat fs;
    char *retVal = NULL;

    assert(path);

    if (stat(path, &fs)) {
        flb_warn("Failed to read type map file: %s", path);
        return NULL;
    }

    retVal = (char *)flb_calloc(fs.st_size + 1, 1);
    if (!OOM_CHECK(retVal)) {
        goto done;
    }

    f = fopen(path, "r");
    if (!f) {
        // Hmm how come stat didn't fail?
        flb_warn("Error opening type map file: %s (error=%s, errno=%d)", path, strerror(errno), errno);
        goto done;
    }

    if (fread(retVal, 1, (size_t)fs.st_size, f) < (size_t)fs.st_size) {
        flb_warn("Error reading type map file: %s (errno=%d)", strerror(errno), errno);
        goto done;
    }

    if (sizeOut) {
        *sizeOut = fs.st_size;
    }

    ok = RTI_TRUE;

done:
    if (f) {
        fclose(f);
    }
    if (!ok && retVal) {
        flb_free(retVal);
        retVal = NULL;
    }
    return retVal;
}
/* }}} */

