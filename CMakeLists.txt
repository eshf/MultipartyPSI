project(MultipartyPSI)
cmake_minimum_required (VERSION 3.9.1)


#############################################
#               Build app                   #
#############################################

 
file (GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/*.h ${PROJECT_SOURCE_DIR}/*.hpp ${PROJECT_SOURCE_DIR}/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})

#############################################
#            Link our libraries             #
#############################################
#target_link_libraries(frontend libPSI_Tests)
target_link_libraries(MultipartyPSI libOPRF)
target_link_libraries(MultipartyPSI libOTe)