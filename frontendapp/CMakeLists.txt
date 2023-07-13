########################################################################################################################
### NPSI LIBRARY MAIN
########################################################################################################################
project( HelloMPSI )
cmake_minimum_required(VERSION 3.5.1)
option(JS_ONLY "Compiles to native JS (No WASM)" OFF)
add_definitions(-std=c++11 -O3)
include_directories(lib)
########################################################################################################################
### PROJECT DESCRIPTION AND META INFO
########################################################################################################################

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/app")

set( CMAKE_CXX_STANDARD 11 )
set(NPSI_PROJECT_NAME        "npsi")
set(NPSI_PROJECT_DESCRIPTION "A simple norie project written in C++")
set(NPSI_AUTHOR_DOMAIN       "https://github.com/eshf/MultipartyPSI")
set(NPSI_VERSION_MAJOR       "0")
set(NPSI_VERSION_MINOR       "0")
set(NPSI_VERSION_PATCH       "1")

add_definitions("-s EXPORTED_RUNTIME_METHODS='[\"ccall\",\"cwrap\"]'")
add_definitions("-s EXTRA_EXPORTED_RUNTIME_METHODS='[\"ccall\",\"cwrap\"]'")
add_definitions("-s EXPORTED_FUNCTIONS='[\"_party3\"]'")
# Here you can add -s flag during linking
set_target_properties(web_mealy_compiler PROPERTIES LINK_FLAGS "-s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall','cwrap']")

set(NPSI_VERSION
    "${NPSI_VERSION_MAJOR}.${NPSI_VERSION_MINOR}.${NPSI_VERSION_PATCH}")
set(NPSI_NAME_VERSION
    "${NPSI_PROJECT_NAME} v${NPSI_VERSION} (${NPSI_VERSION_REVISION})")


########################################################################################################################
### DECLARE PROJECT
########################################################################################################################



#############################################
#               Build app          #
#############################################
# "*" wildcard added to file types to include all files in the directory (recursive search for all file extensions in current folder and subdirectories)
file(GLOB SOURCES backend/*.cpp)
file(GLOB SOURCES backend/*.h)
file(GLOB SOURCES backend/*.a)
file(GLOB SOURCES backend/*.hpp)
file(GLOB SOURCES backend/*.sh)
file(GLOB SOURCES backend/*.sln)
file(GLOB SOURCES backend/*.txt)
file(GLOB SOURCES backend/*.json)
file(GLOB SOURCES backend/*.json)
file(GLOB SOURCES backend/*.txt)
file(GLOB SOURCES backend/*.c)
file(GLOB SOURCES backend/*.get)
file(GLOB SOURCES backend/*.bin)

if(JS_ONLY)
	message(STATUS "Setting compilation target to native JavaScript")
	set_target_properties(a PROPERTIES LINK_FLAGS "-s WASM=0 -s EXPORTED_FUNCTIONS='[_party3]'")

else(JS_ONLY)
	message(STATUS "Setting compilation target to WASM")
	set(CMAKE_EXECUTABLE_SUFFIX ".wasm.js")
	set_target_properties(a PROPERTIES LINK_FLAGS "-s WASM=1 -s EXPORTED_FUNCTIONS='[_party3]'")
endif(JS_ONLY)