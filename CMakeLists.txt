project(frontend)
cmake_minimum_required (VERSION 3.22)

 

#############################################
#               Build frontend.exe           #
#############################################

file(GLOB_RECURSE SRC_FRONTEND ${CMAKE_SOURCE_DIR}/frontend/*.cpp)
include_directories(${CMAKE_SOURCE_DIR}/frontend/)

add_executable(frontend ${SRC_FRONTEND})


#############################################
#            Link our libraries             #
#############################################
#target_link_libraries(frontend libPSI_Tests)
target_link_libraries(frontend libOPRF)
target_link_libraries(frontend libOTe)