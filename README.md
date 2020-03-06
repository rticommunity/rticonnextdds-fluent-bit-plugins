# RTI ConnextDDS Fluent-Bit Plugins

A collection of dynamically loadable plugins for Fluent-Bit to interface with Connext DDS

---
## Requirements

* You need to have a recent Linux distribution (Ubuntu 18.04, Linux Mint 19, ...) with installed C compiler, autotools are required if you are building from a checkout tree.

* You need [RTI Connext DDS Professional](https://www.rti.com/products/connext-dds-professional). 

* The `configure` script relies on the [connext-config](https://github.com/fabriziobertocci/connext-config) tool to determine the build flags for a given architecture. Make sure you have it installed on top of your RTI Connext DDS Professional installation.

<br/><br/>

----------------

## Building

If you are building from a cloned git repository, you need to generate the configure script first.
For this use the `bootstrap.sh` script.

After that just build like any other autoconf-based project. The `configure` 
script requires the following arguments:

  - `--with-connextdds`: must point to the directory where RTI Connext DDS is
    installed. This is optional if you have defined the environment variable
    `$NDDSHOME`.

  - `--enable-target`: specifies the target build system. If you are not sure 
    on the RTI Connext DDS target to use (, check what are the targets you have
    available by looking into your `$NDDSHOME/lib`.

  - `--with-fluentbit`: here you need to point to the location where you have
    the source code of FluentBit. Unfortunately as FluentBit 1.3.2 when you
    build from sources and you `make install`, the script will copy the libraries,
    the main FluentBit headers, but it does not install the headers of the 
    libraries used in FluentBit.

Once configure completes, you build as usual with make:

Example:

```
./configure --enable-target=x64Linux4gcc7.3.0 \
            --with-connextdds=~/rti_connext_dds-6.0.0 \
            --enable-dynamic \
            --enable-debug \
            --with-fluentbit=~/FluentBit/fluent-bit-1.3.2
make
sudo make install
```

That will do it! You will end up with the dynamically loadable plugins under `$PREFIX/lib`
(default to `/usr/local/lib`)



<br/><br/>

-------------

## Usage
To use any of the defined plugin, you need to tell FluentBit to dynamically 
load and initialize them using the -e command-line option:

For example, if you launch FluentBit with:

```
fluent-bit -e /usr/local/lib/flb-out_dds_str.so -c myFluentBit.conf
```
Now you can use the output plugin `dds_str` from the configuration:

```
[OUTPUT]
    Name  dds_str
    ...
```

Note that FluentBit uses the file name as foundation to load and dynamically build
the plugin. Do not rename the plugin files.

<br/><br/>

---
## Plugins
This project contains the following plugins:
* Output DDS Unstructured
* Output DDS Structured

The next section contains information on the configuration parameters for each plugin

<br/>


### Output DDS Unstructured Plugin

This output plugin can publish data over DDS using a simple type that contain a sequence of key-value pairs holding the FluentBit event. The data type definitions are in the [IDL file](src/common/fb.idl).

In the unstructured plugin FluentBit events are published over DDS using a simple mapping where all the fields are stored in sequence of properties. The top-level type is defined as:

```idl
struct FB {
    double ts;
    string<MAX_TAG_LEN> tag;//@key
    sequence<Record, MAX_RECORDS> records;
};
```

The `tag` property contains the tag associated with the given event and represent the key of the message being published.

The `Record` structure is a simple key-value pair:

```idl
struct Record {
    string<MAX_KEY_LEN> key;
    Value value;
};
```

Where the `Value` object is defined one of the native fluent bit types:

```idl
union Value switch (ValueKind) {
        case BOOLEAN:
                boolean b;
        case POSITIVE_INTEGER:
                unsigned long long u64;
        case NEGATIVE_INTEGER:
                long long i64;
        case FLOAT32:
                float f32;
        case FLOAT64:
                double f64;
        case STR:
                string<MAX_STR_LEN> str;
};
```



Complex FluentBit types (array, maps) are not supported.

<br/><br/>

### Output DDS Structured Plugin
The structured output plugin publishes the FluentBit events using a user-defined type, by performing a data transformation described through rules that can be defined in the configuartion file.

Those transformation rules tells the plugin how to map the FluentBit properties into the user-provided data type:

<p align="center">From FluentBit Type <b>BOOLEAN</b>:</p>

| DDS Type                                                     | Value                                             |
| ------------------------------------------------------------ | ------------------------------------------------- |
| `boolean`                                                    | false=DDS_BOOLEAN_FALSE<br/>true=DDS_BOOLEAN_TRUE |
| `short (int16)`<br />`unsigned short (uint16)`<br />`long (int32)`<br />`unsigned long (uint32)`<br />`long long (int64)`<br />`unsigned long long (uint64)` | false=0<br/>true=1                                |
| `float (float32)`<br />`double (float64)`                    | false=0.0<br/>true=1.0                            |
| `char (char8)`<br />`wchar (char16)`                         | false='0'<br/>true='1'                            |
| `string`<br />`wstring`                                      | false="FALSE"<br/>true="TRUE"                     |
| `long double (float128)`                                     | *unsupported, plugin reports an error*            |



<p align="center">From FluentBit Type <b>POSITIVE_INTEGER (unsigned int)</b> and <b>NEGATIVE_INTEGER (signed int)</b>:</p>

| DDS Type                                                     | Value                                                        |
| :----------------------------------------------------------- | ------------------------------------------------------------ |
| `boolean`                                                    | 0 = DDS_BOOLEAN_FALSE<br/>non-zero = DDS_BOOLEAN_TRUE        |
| `short (int16)`<br />`unsigned short (uint16)`<br />`long (int32)`<br />`unsigned long (uint32)`<br />`long long (int64)`<br />`unsigned long long (uint64)` | DDS Value is the same as the FluentBit.<br/>Plugin will trigger a precision loss condition <br/>if the number cannot be assigned/converted without <br/>a loss of information. |
| `float (float32)`<br />`double (float64)`                    | DDS Value is the same as the FluentBit.<br/>Plugin will trigger a precision loss condition <br/>if the number cannot be assigned/converted without <br/>a loss of information. |
| `char (char8)`<br />`wchar (char16)`                         | Only the numbers: [0..9] are transformed in a single<br/>UTF8 character '0', '1', ... '9'. Any other number will trigger <br/>a precision loss condition. |
| `string`<br />`wstring`                                      | The UTF-8 representation of the number.                      |
| `long double (float128)`                                     | *unsupported*, plugin reports an error                       |



<p align="center">From FluentBit Type <b>FLOAT64 (double)</b>:</p>

| DDS Type                                                     | Value                                                        |
| :----------------------------------------------------------- | ------------------------------------------------------------ |
| `boolean`                                                    | +/- 0.0 = DDS_BOOLEAN_FALSE<br/>any other value = DDS_BOOLEAN_TRUE |
| `short (int16)`<br />`unsigned short (uint16)`<br />`long (int32)`<br />`unsigned long (uint32)`<br />`long long (int64)`<br />`unsigned long long (uint64)` | The assigned DDS value is the integer portion<br/>of the FluentBit number.<br/>A precision loss condition is <b>always</b> triggered for<br/>all the values converted from double to (any) integer. |
| `float (float32)`                                            | The DDS value is the casted value of the FluentBit number<br/>(value is rounded to single precision). A precision loss<br/>condition is <b>always</b> triggered. |
| `double (float64)`                                           | Same as FluentBit value                                      |
| `char (char8)`<br />`wchar (char16)`                         | *unsupported*, value published is always `'\0'`<br/>A precision loss condition is <b>always triggered</b>. |
| `string`<br />`wstring`                                      | The UTF-8 representation of the number converted using<br/>sprintf and the conversion "%lg".<br/>A precision loss condition is <b>always triggered</b>. |
| `long double (float128)`                                     | *unsupported*, plugin reports an error                       |



<p align="center">From FluentBit Type <b>STR (string)</b>:</p>

| DDS Type                                                     | Value                                                        |
| :----------------------------------------------------------- | ------------------------------------------------------------ |
| `boolean`                                                    | The following strings are accepted for TRUE:<br/>"TRUE", "1".<br/>The following strings are accepted for FALSE:<br/>"FALSE", "0"<br/>String comparison is **not** case sensitive ("*True*" is accepted). |
| `short (int16)`<br />`unsigned short (uint16)`<br />`long (int32)`<br />`unsigned long (uint32)`<br />`long long (int64)`<br />`unsigned long long (uint64)` | The assigned DDS value is the result of the <br/>ASCII to integer conversion of the FluentBit number.<br/>A precision loss condition is triggered if the converted<br/>value cannot be represented with in the given DDS type. |
| `float (float32)`<br/>`double (float64)`                     | The DDS value is converted from the FluentBit number<br/>using `strtof()` / `strtod()`. A precision loss is<br/>triggered if an invalid character is detected when parsing. |
| `char (char8)`<br />`wchar (char16)`                         | The first character of the string is used as DDS value.<br/>A precision loss condition is <b>triggered</b> if the FluentBit<br/>string is longer than 1 character. <br/>Empty strings are converted to character `'\0'`. |
| `string`<br />`wstring`                                      | The FluentBit string value *as is*.                          |
| `long double (float128)`                                     | *unsupported*, plugin reports an error                       |



Complex FluentBit types (array, maps) are not supported.

When the converting FluentBit and DDS types that are not compatible, the plugin may trigger a precision loss condition. For example, if the DDS type is a short and the FluentBit value is 100,000, the condition is triggered (because 100,000 cannot be represented in a 16-bit integer).

User can control what to do when a precision loss condition is triggered through the plugin setting **PrecisionLoss**.

<br/>

**Configuration Parameters**

The configuration parameters for the output DDS Structured Plugin are the following:

   * **XMLFile || XMLFile_0**, **XMLFile_1**, ... **XMLFile_9** (optional): identify the XML files containing the published data type, topic and all the participant definitions required by the plug-in for publishing. You can specify either a single XML file (using the property **XMLFile**, or multiple files, using **XMLFile*_x***. The plug-in will look incrementally for all those properties and will stop loading the XML files once it finds an undefined property. For example, if you define XMLFile_0, XMLFile_1, XMLFile_3, the plug-in will load only the files specified by XMLFile_0 and XMLFile_1.
     If no XML are specified, the plug-in will follow the standard XML location rules as defined in the RTI Connext User's manual (for example, it will look at the environment variable `$USER_QOS_PROFILE`, the file `USER_QOS_PROFILES.xml`, ...).
   * **DomainParticipant** (required): defines the fully qualified name in the form: `DomainParticipantLibrary::DomainParticipantName` to use. The domain participant must be defined in one of the `<participant_library>` defined in any XML. 
   * **DataWriter** (required): defines the `PublisherName::DataWriterName` of the data writer to use for publication.
   * **PrecisionLoss** (optional): defines the action the plug-in will perform when it detects a loss of precision when mapping FluentBit events into the structured data type. For example, if attempting to map a long 32-bit integer into a 16-bit integer, depending on the value, you might get a data corruption. Possible values are:
       * `none` (default): don't do anything.
       * `warn`: print a warning on the console **every time** this condition is detected.
       * `warn_once`: print a warning on the console **only the first** time this condition is detected (but don't keep printing it if a similar situation is encountered).
       * `abort`: call abort() to terminate immediately the application if this condition is detected. It is recommended to use this condition only for debugging and troubleshooting.
   * **TypeMap** (required): defines the name of a JSON file containing the instructions on how to map fields of events from FluentBit into DDS type. 

<br/>

**Type Map File**

The TypeMap file tells the plugin how to map all the properties of the events (in FluentBit) into DDS samples. The file is encoded using JSON where the top-level element is an array containing the individual mapping:

```javascript
[ EventMap, EventMap, ...]
```

Each `EventMap` is an object that tells how to identify the event in FluentBit (by tag comparison) and how to generate the DDS data. The structure of the `EventMap` object is as follow:

```javascript
{
    "tag": String,            // Required
    "map": FieldMapObject,    // Optional
    "static": StaticMapObject // Optional
}
```

* The value of the `tag` property defines the tag of the event for which this map applies.
* The `map` property defines a dynamic map that explain how to translate FluentBit field into DDS members of struct:
  * property name = name of the fluent bit field
  * property value = fully qualified name of the DDS member (for nested structures, use the '.' separator)
* The `static` properties defines an object that statically assign the value of the members of the DDS struct:
  * property name = fully qualified name of the DDS member
  * property value = static value to assign

Note that only the defined DDS members will be assigned: all the other non-specified members will have their default value (whether defined through the IDL or by the system).

For an example of a map file, refer to the [McAfee AV example](examples/McAfee/README.md).



<br/><br/>

------
## Notes

  * The name of the plugin you specify with the `-e` command-line option is important as it determines the name of the plugin, and the entry point of the plugin. The installed `/usr/local/lib/flb-out_dds_str.so` is a symlink to the real loadable plugin that is `/usr/local/lib/libflb_out_dds_str.so`.
    
  * Refer to the [McAfee AV example](examples/McAfee/README.md) (inside the `examples` folder) to see how to use the
    plugin

