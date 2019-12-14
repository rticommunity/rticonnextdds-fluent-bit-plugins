# RTI ConnextDDS Fluent-Bit Plugins

A collection of dynamically loadable plugins for Fluent-Bit to interface with Connext DDS

---
## Building
If you are building from a cloned git repository, you need to generate the configure script first.
For this use the `bootstrap.sh` script

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


---
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

------
## Output DDS Structured Plugin
The configuration parameters for the output DDS Structured Plugin are the following:

   * **XMLFile_0**, **XMLFile_1**, ... **XMLFile_9** (optional): identify the
     XML files containing the published data type, topic and all the participant
     definitions required by the plug-in for publishing. The plug-in will look
     incrementally for all those properties and will stop loading the XML files
     once it finds an undefined property. For example, if you define XMLFile_0, 
     XMLFile_1, XMLFile_3, the plug-in will load only the files specified by
     XMLFile_0 and XMLFile_1.
     If no XML are specified, the plug-in will follow the XML location rules
     as defined in the RTI Connext User's manual (for example, it will look
     at the environment variable `$USER_QOS_PROFILE`, will look for the file 
     `USER_QOS_PROFILES.xml`).

   * **DomainParticipant** (required): defines the fully qualified name in the 
     form: `DomainParticipantLibrary::DomainParticipantName` to use.

   * **DataWriter** (required): defines the `PublisherName::DataWriterName` of
     the data writer to use for publication.

   * **PrecisionLoss** (optional): defines the action the plug-in will perform
     when it detects a loss of precision when mapping FluentBit events into
     the structured data type. For example, if attempting to map a long 32-bit
     integer into a 16-bit integer, depending on the value, you might get a
     data corruption. Possible values are:
       * `none` (default): don't do anything.
       * `warn`: print a warning on the console every time this condition is
         detected.
       * `warn_once`: print a warning on the console the first time this condition
         is detected (but don't keep printing it if a similar situation is 
         encountered).
       * `abort`: call abort() to terminate immediately the application if
         this condition is detected. It is recommended to use this condition 
         only for debugging and troubleshooting.

   * **TypeMap** (required): defines the name of a JSON file containing the
     instructions on how to map fields of events from FluentBit into DDS type. 







------
## Notes

  * The name of the plugin you specify with the `-e` command-line option is
    important as it determines the name of the plugin, and the entry point of the
    plugin. The installed `/usr/local/lib/flb-out_dds_str.so` is a symlink
    to the real loadable plugin that is `/usr/local/lib/libflb_out_dds_str.so`.

  * Refer to the examples (inside the `examples` folder) to see how to use the
    plugin

