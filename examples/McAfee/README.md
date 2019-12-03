# McAfee Demo
This demo shows how to use the FluentBit Structured DDS plug-in
to publish scan results from McAfee over DDS using
a data model that is designed to insert data into [Splunk CIM for Malware](https://docs.splunk.com/Documentation/CIM/4.14.0/User/Malware).

### Data Model
The data model used by this example is as follow (using a compact IDL syntax without
commentsm or [XTypes](https://www.omg.org/spec/DDS-XTypes/1.1/About-DDS-XTypes/) annotations):

```
module Common {
  struct HostIdentification {
    string<20> host;
    string<50> ip;
    string<50> name;
  };

  struct UTCTimestamp {
    uint32 sec;
    uint32 nanosec;
  };

  const uint16 HASH_STRING_MAX = 32;
  const uint16 PATH_STRING_MAX = 200;
  const uint16 EMAIL_STRING_MAX = 200;
  const uint16 USER_STRING_MAX = 40;
  const uint16 URL_STRING_MAX = 200;
  const uint16 VENDOR_STRING_MAX = 100;
};

module Malware {
    enum Action {
      @value(1)
      Allowed,
      @value(2)
      Blocked,
      @value(3)
      Deferred
    };

    struct Attacks {
      CIM::Malware::Action  action_enum;
      string<40>            category;
      Common::UTCTimestamp  date;
      Common::HostIdentification dest;
      string<30> dest_nt_domain;
      string<Common::HASH_STRING_MAX> file_hash;
      string<Common::PATH_STRING_MAX> file_name;
      string<Common::PATH_STRING_MAX> file_path;
      string<Common::EMAIL_STRING_MAX> sender;
      string<50> signature;
      Common::HostIdentification src;
      string<Common::USER_STRING_MAX> user;
      string<Common::URL_STRING_MAX> url;
      string<Common::VENDOR_STRING_MAX> vendor_product;
    };
```

The file `SplunkMalware.xml` contains the XML representation of the published type.

### FluentBit Configuration
This example creates three inputs that are used to identify different type of messages from a McAfee
log output:

   * Start messages: an entry line that signal the beginning of the scan operation. The 
     line has the following format:
```
Oct 01 00:16:03 ubuntu INFO OASManager [27304] Starting OAS Manager
```
This event is not tr

   * A line to report an error while attempting to access a file like this:


   * A line to 
Refer to the master configuration file `mcafee.conf` for additional information














