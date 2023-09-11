########################################################################################################################
# NPSI build stage
########################################################################################################################
FROM ubuntu:22.04 AS MultipartyPSI

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libstdc++11

WORKDIR /npsi

COPY /MultipartyPSI/ ./MultipartyPSI
COPY CMakeLists.txt .

WORKDIR /MultipartyPSI/npsi

RUN cmake -DCMAKE_BUILD_TYPE=Release .. && \
    cmake --build . --parallel 8

########################################################################################################################
# npsi image
########################################################################################################################

FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    libstdc++11

RUN adduser --system --group norieprojects

COPY --chown=norieprojects:norieprojects --from=MultipartyPSI \
    ./MultipartyPSI/npsi \
    ./srcfront/

ENTRYPOINT [ "./npsi/backend/main.cpp" ]
