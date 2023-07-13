########################################################################################################################
### NPSI LIBRARY MAIN
########################################################################################################################
project( HelloMPSI )
cmake_minimum_required(VERSION 3.5.1)
set( CMAKE_CXX_STANDARD 11 )
option(JS_ONLY "Compiles to native JS (No WASM)" OFF)
add_definitions(-std=c++11 -O3)
include_directories(lib)
########################################################################################################################
### PROJECT DESCRIPTION AND META INFO
########################################################################################################################


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/app")
add_executable(testnpsi ${SOURCES})


# Here you can add -s flag during linking



########################################################################################################################
### DECLARE PROJECT
########################################################################################################################
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

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/app")
add_executable(testnpsi ${SOURCES})


#############################################
#               Build app          #
#############################################


if(JS_ONLY)
	message(STATUS "Setting compilation target to native JavaScript")
	set_target_properties(testnpsi PROPERTIES LINK_FLAGS "-s WASM=0 -s EXPORTED_FUNCTIONS='[_party3]'")

else(JS_ONLY)
	message(STATUS "Setting compilation target to WASM")
	set(CMAKE_EXECUTABLE_SUFFIX ".wasm.js")
	set_target_properties(testnpsi PROPERTIES LINK_FLAGS "-s WASM=1 -s EXPORTED_FUNCTIONS='[_party3]'")
endif(JS_ONLY)