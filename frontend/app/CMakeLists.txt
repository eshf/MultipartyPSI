########################################################################################################################
### NPSI LIBRARY MAIN
########################################################################################################################

cmake_minimum_required(VERSION 3.22)

########################################################################################################################
### PROJECT DESCRIPTION AND META INFO
########################################################################################################################
project( HelloMPSI )
set(NPSI_PROJECT_NAME        "npsi")
set(NPSI_PROJECT_DESCRIPTION "A simple norie project written in C++")
set(NPSI_AUTHOR_DOMAIN       "https://github.com/eshf/MultipartyPSI")
set(NPSI_VERSION_MAJOR       "0")
set(NPSI_VERSION_MINOR       "0")
set(NPSI_VERSION_PATCH       "1")

set( CMAKE_CXX_STANDARD 11 )



set(NPSI_VERSION
    "${NPSI_VERSION_MAJOR}.${NPSI_VERSION_MINOR}.${NPSI_VERSION_PATCH}")
set(NPSI_NAME_VERSION
    "${NPSI_PROJECT_NAME} v${NPSI_VERSION} (${NPSI_VERSION_REVISION})")

# add -s flag during compiling object files
add_definitions("-s EXPORTED_RUNTIME_METHODS='[\"ccall\",\"cwrap\"]'")
add_definitions("-s EXTRA_EXPORTED_RUNTIME_METHODS='[\"ccall\",\"cwrap\"]'")
add_definitions("-s EXPORTED_FUNCTIONS='[\"_party3\"]'")
# add -s flag during linking
set_target_properties(web_mealy_compiler PROPERTIES LINK_FLAGS "-s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall','cwrap']")

########################################################################################################################
### DECLARE PROJECT
########################################################################################################################



#############################################
#               Build app          #
#############################################
# "*" wildcard added to file types to include all files in the directory (recursive search for all file extensions in current folder and subdirectories)
file(GLOB sourceFiles CONFIGURE_DEPENDS
"*.h"
"*.cpp"
"*.sh"
"*.sln"
"*.json"
"*.txt"
"*.js"
"*.h"
"*.gch"
"include/lib/*.a"
"include/libOPRF/libOPRF.dir/Hashing/**"
"include/libOPRF/libOPRF.dir/OPPRF/**"
"include/libOPRF/OPPRF/*.cpp"
"include/libOPRF/OPPRF/*.h"
"include/libOTe/Base/*.h"
"include/libOTe/Base/*.cpp"
"include/libOTe/NChooseK/*.cpp"
"include/libOTe/NChooseK/*.h"
"include/libOTe/NChooseOne/*.cpp"
"include/libOTe/NChooseOne/*.h"
"include/libOTe/Tools/*.bin"
"include/libOTe/Tools/*.txt"
"include/libOTe/Tools/*.cpp"
"include/libOTe/Tools/*.h"
"include/libOTe/Tools/*.cpp"
"include/libOTe/TwoChooseOne/*.h"
"include/libOTe/TwoChooseOne/*.cpp"
"include/NTL/*.h"
"thirdparty/linux/miracl/miracl/include/*.h"
"thirdparty/linux/miracl/miracl/source/*.c"
"thirdparty/linux/miracl/miracl/source/**"
"thirdparty/linux/miracl/miracl/source/p1363/*.c"
"thirdparty/linux/miracl/miracl/source/p1363/*.h"
"thirdparty/linux/miracl/miracl_osmt/include/**"
"thirdparty/linux/miracl/miracl_osmt/source/curve/pairing/*.cpp"
"thirdparty/linux/miracl/miracl_osmt/source/curve/pairing/*.txt"
"thirdparty/linux/miracl/miracl_osmt/source/curve/pairing/*.c"
"thirdparty/linux/miracl/miracl_osmt/source/curve/pairing/*.h"
"thirdparty/linux/miracl/miracl_osmt/source/curve/*.cpp"
"thirdparty/linux/miracl/miracl_osmt/source/curve/*.txt"
"thirdparty/linux/miracl/miracl_osmt/source/curve/*.h"
"thirdparty/linux/miracl/miracl_osmt/source/p1363/*.c"
"thirdparty/linux/miracl/miracl_osmt/source/p1363/*.h"
"thirdparty/linux/ntl/doc/**"
"thirdparty/linux/ntl/include/NTL/*.h"
"thirdparty/linux/ntl/include/NTL/*.h"
"frontend/*.cpp"
"frontend/*.h"
"frontend/*.txt"
"cryptoTools/Common/*.h"
"cryptoTools/Common/*.cpp"
"cryptoTools/Crypto/*.cpp"
"cryptoTools/Crypto/*.h"
"cryptoTools/Crypto/*.hpp"
"cryptoTools/asm/**"
"cryptoTools/Network/*.cpp"
"cryptoTools/Network/*.h"
"cryptoTools/Network/*.txt"
"libPSI_Tests/*.cpp"
"libPSI_Tests/*.h"
"libPSI_Tests/*.txt"
"libPSI_TestsVS/*.cpp"
"libPSI_TestsVS/*.cpp"
""
)

add_executable(mpsiApp ${sourceFiles})