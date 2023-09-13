########################################################################################################################
### NPSI LIBRARY MAIN
########################################################################################################################
project(testnpsi)
cmake_minimum_required(VERSION 3.9.1)
option(JS_ONLY "Compiles to native JS (No WASM)" OFF)
add_definitions(-std=c++11 -O3)

    
set(CMAKE_CXX_STANDARD 14)
file(GLOB SOURCES *.cpp)
add_executable(testnpsi *.cpp)

########################################################################################################################
### DECLARE PROJECT
########################################################################################################################
# "*" wildcard added to file types to include all files in the directory (recursive search for all file extensions in current folder and subdirectories)




#############################################
#               Build app          #
#############################################

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/testnpsi")


if(JS_ONLY)
	message(STATUS "Setting compilation target to native JavaScript")
	set_target_properties(testnpsi PROPERTIES LINK_FLAGS "-s WASM=0 -s EXPORTED_FUNCTIONS='[_party3]'")

else(JS_ONLY)
	message(STATUS "Setting compilation target to WASM")
	set(CMAKE_EXECUTABLE_SUFFIX ".wasm.js")
	set_target_properties(testnpsi PROPERTIES LINK_FLAGS "-s WASM=1 -s EXPORTED_FUNCTIONS='[_party3]'")
endif(JS_ONLY)