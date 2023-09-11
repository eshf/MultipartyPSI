########################################################################################################################
# NPSI build stage
########################################################################################################################
FROM ubuntu:22.04 AS MultipartyPSI

RUN apk add g++ make python

EXPOSE 8080

RUN mkdir /MultipartyPSI

WORKDIR /MultipartyPSI/npsi

COPY /MultipartyPSI/npsi ./MultipartyPSI/npsi
COPY CMakeLists.txt .

RUN cmake -DCMAKE_BUILD_TYPE=Release .. && \
    cmake --build . --parallel 8

COPY . /MultipartyPSI

RUN npm install
CMD ["npm", "start"]
########################################################################################################################
# npsi image
########################################################################################################################


