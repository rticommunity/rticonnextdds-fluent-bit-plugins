# RTI ConnextDDS Fluent-Bit Plugins

A collection of dynamically loadable plugins for Fluent-Bit to interface with Connext DDS

---
## Building
If you are building from a cloned git repository, you need to generate the configure script first. For this use the `bootstrap.sh` script

After that just build like any other autoconf-based project. The `configure` 
script requires the following (mandatory) arguments:

- `--with-connextdds`: must point to the directory where RTI Connext DDS is
  installed.
- `--enable-target`: must specify the target build system 

- Use the `bootstrap.sh` script to (re)generate the autotools.
- Use the `configure` script to build a Makefile. I.e.:

```
./configure --enable-target=x64Linux --with-connextdds=~/rti_connext_dds-6.0.0 --enable-dynamic --enable-debug --with-fluentbit=~/FluentBit/fluent-bit-1.3.2
```

NOTE: since bit-Fluent does not install the dependency libraries, you need to have a buildable source files installed in your system. Use the option `--with-fluentbit` to tell the build system where do you have the source files.

- Build:

```
make
```

- Install:

```
sudo make install
```

That will do it! You will end up with the dynamically loadable plugins under `$PREFIX/lib` (default to `/usr/local/lib`


---
## Usage
To use any of the defined plugin, you need to tell FluentBit to dynamically 
load and initialize them using the -e command-line option:

For example, if you launch FluentBit with:

```
fluent-bit -e /usr/local/lib/flb-out_dds_str.so -c myFluentBit.conf
```
Now you can use the output plugin "dds_str" from the configuration:

```
[OUTPUT]
    Name  dds_str
    ...
```

