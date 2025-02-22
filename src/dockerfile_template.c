#include <templates.h>
#include <stdio.h>

#define DOCKERFILE_FILENAME     "Dockerfile"

static const char *content = 
{
    "FROM ubuntu:22.04\n\n"
    "RUN apt-get update && \\\n"
    "    apt-get install \\\n"
    "    cmake \\\n"
    "    wget \\\n"
    "    g++ \\\n"
    "    gdb \\\n"
    "    netcat \\\n"
    "    git \\\n"
    "    curl \\\n"
    "    uuid-dev \\\n"
    "    libmysqlclient-dev \\\n"
    "    libcurl4-openssl-dev \\\n"
    "    librdkafka-dev \\\n"
    "    pkg-config \\\n"
    "    libglib2.0-dev \\\n"
    "    libpq-dev \\\n"
    "    libhiredis-dev \\\n"
    "    -y\n\n"
    "WORKDIR /development\n\n"
    "RUN git clone https://github.com/civetweb/civetweb.git && \\\n"
    "    mkdir -p civetweb/_build && \\\n"
    "    cd civetweb/_build && \\\n"
    "    cmake .. && \\\n"
    "    make install && \\\n"
    "    rm -rf /development/civetweb\n\n"
    "RUN wget https://www.sqlite.org/2024/sqlite-autoconf-3450100.tar.gz && \\\n"
    "    tar -xvf sqlite-autoconf-3450100.tar.gz && \\\n"
    "    cd sqlite-autoconf-3450100 && \\\n"
    "    ./configure --prefix=/usr/local && \\\n"
    "    make install && \\\n"
    "    cd .. && \\\n"
    "    rm -rf sqlite-autoconf-3450100.tar.gz sqlite-autoconf-3450100\n\n"
    "RUN cd /development && \\\n"
    "    git clone https://github.com/eclipse/paho.mqtt.c.git && \\\n"
    "    cd paho.mqtt.c && \\\n"
    "    make install && \\\n"
    "    cd .. && \\\n"
    "    rm -rf paho.mqtt.c\n\n"
    "RUN cd /development && \\\n"
    "    git clone https://github.com/NakedSolidSnake/sat.git && \\\n"
    "    mkdir -p sat/build && \\\n"
    "    cd sat/build && \\\n"
    "    cmake \\\n"
    "    -DSAT_WEBSERVER=ON \\\n"
    "    -DSAT_CURL=ON \\\n"
    "    -DSAT_PROPERTIES=ON \\\n"
    "    -DSAT_JSON=ON \\\n"
    "    -DSAT_KAFKA=ON \\\n"
    "    -DSAT_MQTT=ON \\\n"
    "    -DSAT_MYSQL=ON \\\n"
    "    -DSAT_POSTGRES=ON \\\n"
    "    -DSAT_REDIS=ON \\\n"
    "    -DSAT_SQLITE=ON \\\n"
    "    .. && \\\n"
    "    make install && \\\n"
    "    rm -rf /development/sat && \\\n"
    "    ldconfig\n\n"
    "RUN cd /development && \\\n"
    "    git clone https://github.com/NakedSolidSnake/sat_scaffolding.git && \\\n"
    "    mkdir -p sat_scaffolding/build && \\\n"
    "    cd sat_scaffolding/build && \\\n"
    "    cmake .. && \\\n"
    "    make install && \\\n"
    "    rm -rf /development/sat_scaffolding\n\n"
    "RUN useradd -ms /bin/bash developer && chmod 0777 /development\n\n"
    "USER developer\n\n"
    "EXPOSE 1234\n\n"
    "ENTRYPOINT [ \"/bin/tail\", \"-f\", \"/dev/null\" ]"
};


bool sat_scaffolding_create_dockerfile_template (void)
{
    bool status = false;

    FILE *file = fopen (DOCKERFILE_FILENAME, "w");
    if (file != NULL)
    {
        fputs (content, file);

        fclose (file);
        status = true;
    }

    return status;
}