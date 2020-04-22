# Locate your Connext DDS installation (e.g. rti_connext_dds-6.0.0) at your current directory. 

# Build a Docker image for Fluent Bit with Connext DDS plugins:
# $ docker build -t flb-dds .

# Run the image:
# $ docker run -tdi -v $PWD/rti-license.dat:/app/rti-license.dat flb-dds

FROM ubuntu:18.04 as builder

ARG CONNEXT_DDS=rti_connext_dds-6.0.0
ENV ARCHITECTURE=x64Linux4gcc7.3.0
ENV PATH=/rti_connext_dds/bin:$PATH

COPY $CONNEXT_DDS /rti_connext_dds

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    ca-certificates \
    build-essential \
    git \
    cmake \
    make \
    wget \
    flex \
    bison \
    automake \
    libtool \
    && cd / && wget https://github.com/fluent/fluent-bit/archive/v1.3.2.tar.gz && \
    tar xvfz v1.3.2.tar.gz && \
    cd /fluent-bit-1.3.2/build && cmake .. && make

RUN cd /rti_connext_dds && \
    wget https://github.com/rticommunity/connext-config/releases/download/0.9.9/connext-config-0.9.9.tar.gz && \
    tar xvfz connext-config-0.9.9.tar.gz

RUN cd / && git clone https://github.com/kyoungho/rticonnextdds-fluent-bit-plugins && \
    cd /rticonnextdds-fluent-bit-plugins && \
    ./bootstrap.sh && \
    ./configure --enable-target=$ARCHITECTURE \
            --with-connextdds=/rti_connext_dds \
            --enable-dynamic \
            --enable-debug \
            --with-fluentbit=/fluent-bit-1.3.2 && \
    make && \
    make install

FROM ubuntu:18.04

ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/app/lib

COPY --from=builder /rti_connext_dds/lib/x64Linux4gcc7.3.0 /app/lib
COPY --from=builder /usr/local/lib/*flb* /app/lib/
COPY --from=builder /fluent-bit-1.3.2/build/lib/libfluent-bit.so /app/lib/libfluent-bit.so
COPY --from=builder /fluent-bit-1.3.2/build/bin/fluent-bit /app/fluent-bit
COPY --from=builder /rticonnextdds-fluent-bit-plugins/examples/McAfee/* /app/
COPY --from=builder /rticonnextdds-fluent-bit-plugins/examples/McAfee/mcafee.conf /app/fluent-bit.conf
COPY --from=builder /rticonnextdds-fluent-bit-plugins/examples/McAfee/mcafee.log /app/log.txt

WORKDIR /app
CMD ./fluent-bit -e /app/lib/flb-out_dds_str.so -c fluent-bit.conf
