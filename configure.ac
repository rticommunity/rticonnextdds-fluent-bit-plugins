dnl **********************************************************************************
dnl (c) Copyright 2018, Real-Time Innovations, Inc. All rights reserved.
dnl **********************************************************************************

AC_INIT(flb-out_dds, 1.0, fabrizio@rti.com)
AC_CONFIG_SRCDIR([src/out_dds_unstr/out_dds_unstr.c])
LT_INIT([dlopen])


dnl subdir-objects tells Makefile to place object files in the same dir as sources.
dnl See: https://www.gnu.org/software/automake/manual/html_node/List-of-Automake-options.html
AM_INIT_AUTOMAKE([subdir-objects])

AC_PROG_CC
AM_PROG_CC_C_O

AC_CONFIG_MACRO_DIRS([m4])

dnl **********************************************************************************************
dnl * Initialize build architecture
dnl * Defines one of the following macros made available to the library
dnl **********************************************************************************************
AC_MSG_CHECKING(the build architecture)
case `uname -s` in
    Darwin)
        myarch="Mac OS X"
        CFLAGS="$CFLAGS -DBUILD_ARCH_MACOS"
        ;;

    Linux)
        myarch="Linux"
        CFLAGS="$CFLAGS -DBUILD_ARCH_LINUX"
        ;;

    CYGWIN_NT-5.1)
        myarch="Cygwin"
	CFLAGS="$CFLAGS -DBUILD_ARCH_CYGWIN"
	LDFLAGS="$LDFLAGS -static-libgcc"
        ;;

    MINGW32_NT-6.1)
        myarch="MINGW"
	CFLAGS="$CFLAGS -DBUILD_ARCH_MINGW -D_WINDOWS -fexceptions"
	LDFLAGS="$LDFLAGS -static-libgcc"
	;;

    *)
        echo "Build architecture not supported"
        false
        ;;
esac

AC_MSG_RESULT($myarch)
RTI_LIBSUFFIX=""

dnl **********************************************************************************************
dnl * Static/Dynamic                                                                             *
dnl **********************************************************************************************
AC_ARG_ENABLE(dynamic,
[  --enable-dynamic        uses RTI dynamic libraries instead of static lib],
[],[
        RTI_LIBSUFFIX="${RTI_LIBSUFFIX}z"
])

dnl **********************************************************************************************
dnl * Debug/Release                                                                              *
dnl **********************************************************************************************
AC_ARG_ENABLE(debug,
[  --enable-debug          enable full debugging information (and disable optimization)],
[
        CFLAGS="-g -O0 -DDEBUG"
        RTI_LIBSUFFIX="${RTI_LIBSUFFIX}d"
],[
        CFLAGS="-O2 -DNDEBUG"
])


dnl **********************************************************************************************
dnl * Enable/disable compiler warnings                                                           *
dnl **********************************************************************************************
AC_ARG_ENABLE(warnings,
[  --enable-warnings       enable compiler warnings during build ],
[
        CFLAGS="$CFLAGS -Wall -Wpointer-arith -Wwrite-strings -Wconversion -Wcast-qual -W"
],[
        CFLAGS="$CFLAGS -W"
])

dnl **********************************************************************************************
dnl * Connext DDS
dnl **********************************************************************************************
AC_ARG_WITH(connextdds,
[   --with-connextdds=ARG   specify the location of RTI Connext DDS],
[
        if test "${withval}" = "yes"; then
            AC_MSG_ERROR(missing argument for --with-connextdds parameter);
        else
            NDDSHOME="${withval}"
        fi
],[
        AC_MSG_RESULT(Checking for NDDSHOME...)
        if test "a${NDDSHOME}a" = "aa"; then
            AC_MSG_ERROR(NDDSHOME not defined. You must specify the --with-connextdds argument);
        else
            NDDSSHOME="${NDDSHOME}"
        fi
])

AC_CHECK_FILE("${NDDSHOME}/include/ndds/ndds_cpp.h", 
[
        AC_MSG_RESULT(Found RTI Connext DDS at ${NDDSHOME})
],[
        AC_MSG_RESULT(RTI Connext DDS not found or NDDSHOME not defined)
])

dnl **********************************************************************************************
dnl * FluentBit
dnl **********************************************************************************************
AC_ARG_WITH(fluentbit,
[   --with-fluentbit=ARG   specify the location of FluentBit sources],
[
        if test "${withval}" = "yes"; then
            AC_MSG_ERROR(missing argument for --with-fluentbit parameter);
        else
            FBHOME="${withval}"
        fi
],[
        AC_MSG_ERROR(Missing required argument --with-fluentbit);
])
AC_CHECK_FILE("${FBHOME}/include/fluent-bit.h", 
[
        AC_MSG_RESULT(Found FluentBit at ${FBHOME})
],[
        AC_MSG_RESULT(Wrong location for FluentBit: ${FBHOME})
])



dnl **********************************************************************************************
dnl * Target kind
dnl **********************************************************************************************
AC_ARG_ENABLE(target,
[  --enable-target=ARG     enable cross compiling the application for an external platform.
                          Possible values are: rpi, i86Linux, x64Linux, x64Darwin ],
[
        if test "${enableval}" = "yes"; then
            AC_MSG_ERROR(missing argument for --enable-target parameter);
        elif test "${enableval}" = "x64Linux"; then
            CFLAGS="$CFLAGS -Wno-invalid-offsetof -DTARGET_ARCH_x64Linux -DRTI_UNIX -DRTI_LINUX -DRTI_64BIT -DRTI_STATIC -m64"
            LDFLAGS="-m64 -static-libgcc -Wl,--no-as-needed"
            RTI_SYSLIBS="-ldl -lnsl -lm -lpthread -lrt"
            TARGET_ARCH="x64Linux4gcc7.3.0"
            dnl TARGET_ARCH="x64Linux3gcc4.8.2"
        elif test "${enableval}" = "i86Linux"; then
            CFLAGS="$CFLAGS -Wno-invalid-offsetof -DTARGET_ARCH_i86Linux -DRTI_UNIX -DRTI_LINUX -DRTI_32BIT -DRTI_STATIC -m32"
            LDFLAGS="-m32 -static-libgcc"
            RTI_SYSLIBS="-ldl -lnsl -lm -lpthread -lrt"
            TARGET_ARCH="i86Linux3.xgcc4.6.3"
        elif test "${enableval}" = "rpi"; then
            CFLAGS="$CFLAGS -Wno-invalid-offsetof -DFL_TARGET_armRaspbian -fpic -DRTI_UNIX -DRTI_LINUX -DRTI_STATIC -march=armv6 -mfpu=vfp -mfloat-abi=hard -mlong-calls"
            RTI_SYSLIBS="-ldl -lnsl -lm -lpthread -lrt"
            TARGET_ARCH="armv6vfphLinux3.xgcc4.7.2"
        elif test "${enableval}" = "x64Darwin"; then
            CFLAGS="$CFLAGS -DTARGET_ARCH_x64Darwin -m64 -DRTI_UNIX -DRTI_DARWIN -DRTI_DARWIN64 -DRTI_64BIT -DRTI_STATIC"
            LDFLAGS="-m64"
            RTI_SYSLIBS="-ldl -lm -lpthread"
            TARGET_ARCH="x64Darwin15clang7.0"
        else
            AC_MSG_ERROR(invalid or unsupported target type. Invoke configure with --help for a list of possible values);
        fi
        AC_MSG_RESULT(Building for target ${enableval} system)
],[
        AC_MSG_ERROR(you must specify --enable-target with a valid target. See --help for more info)
])


CFLAGS="$CFLAGS -I${NDDSHOME}/include -I${NDDSHOME}/include/ndds -I{FBHOME}/include -I${FBHOME}/lib/monkey/include -I${FBHOME}/lib/mbedtls-2.16.3/include -I${FBHOME}/lib/jemalloc-5.2.1/include -I${FBHOME}/lib/msgpack-3.2.0/include -I${FBHOME}/lib/chunkio/include -I${FBHOME}/lib/flb_libco -I${FBHOME}/lib"
LDFLAGS="$LDFLAGS -L${NDDSHOME}/lib/${TARGET_ARCH} -L${FBHOME}/build/lib"
RTI_LIBS="-lnddsc${RTI_LIBSUFFIX} -lnddscore${RTI_LIBSUFFIX} ${RTI_SYSLIBS} -lfluent-bit"

AC_SUBST(RTI_LIBS, "${RTI_LIBS}")

AC_OUTPUT(Makefile src/out_dds_unstr/Makefile)

