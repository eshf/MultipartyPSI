########################################################################################################################
### NPSI LIBRARY MAIN
########################################################################################################################

cmake_minimum_required(VERSION 3.2)

########################################################################################################################
### PROJECT DESCRIPTION AND META INFO
########################################################################################################################

set(NPSI_PROJECT_NAME        "npsi")
set(NPSI_PROJECT_DESCRIPTION "A simple norie project written in C++")
set(NPSI_AUTHOR_DOMAIN       "https://github.com/eshf/npsi")
set(NPSI_VERSION_MAJOR       "0")
set(NPSI_VERSION_MINOR       "0")
set(NPSI_VERSION_PATCH       "1")

set(NPSI_VERSION
    "${NPSI_VERSION_MAJOR}.${NPSI_VERSION_MINOR}.${NPSI_VERSION_PATCH}")
set(NPSI_NAME_VERSION
    "${NPSI_PROJECT_NAME} v${NPSI_VERSION} (${NPSI_VERSION_REVISION})")

########################################################################################################################
### DECLARE PROJECT
########################################################################################################################

project(${NPSI_PROJECT_NAME})

set(NPSI_SRC_DIR ${PROJECT_SOURCE_DIR}/multipartypsi)


#############################################
#               Build frontend.exe           #
#############################################

file(GLOB_RECURSE SRC_FRONTEND ${CMAKE_SOURCE_DIR}/multipartypsi/frontend/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/multipartypsi/frontend/)

add_executable(frontend.exe ${SRC_FRONTEND})


#############################################
#            Link our libraries             #
#############################################
#target_link_libraries(frontend.exe libPSI_Tests)
target_link_libraries(frontend.exe libOPRF)
target_link_libraries(frontend.exe libOTe)
