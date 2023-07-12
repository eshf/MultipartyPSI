<<<<<<< HEAD

#project(libOTe)

file(GLOB_RECURSE SRCS *.cpp)

include_directories(${CMAKE_SOURCE_DIR}/libOTe)

add_library(libOTe ${SRCS})

target_link_libraries(libOTe cryptoTools)
=======

#project(libOTe)

file(GLOB_RECURSE SRCS *.cpp)

include_directories(${CMAKE_SOURCE_DIR}/libOTe)

add_library(libOTe ${SRCS})

target_link_libraries(libOTe cryptoTools)
>>>>>>> 3c6e9e06 (Merge pull request #9 from eshf/norieworks)
