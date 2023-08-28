########################################################################################################################
# NPSI build stage
########################################################################################################################
FROM ubuntu:22.04 AS multipartypsi

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libstdc++6 \
    libboost-all-dev 

WORKDIR /npsi

COPY /multipartypsi/ ./multipartypsi
COPY CMakeLists.txt .

WORKDIR /npsi/multipartypsi

RUN cmake -DCMAKE_BUILD_TYPE=Release .. && \
    cmake --build . --parallel 8

########################################################################################################################
# npsi image
########################################################################################################################

FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    libstdc++6 \
    libboost-all-dev

RUN adduser --system --group norieprojects

COPY --chown=norieprojects:norieprojects --from=multipartypsi \
    ./npsi/multipartypsi/npsi \
    ./app/

ENTRYPOINT [ "./app/npsi" ]
