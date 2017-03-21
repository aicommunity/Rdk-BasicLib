cmake_minimum_required (VERSION 2.8)
project(Rdk-BasicLib)

# Put all the archive targets into ${PROJECT_NAME}/Lib/

set(A_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../../Bin/Platform/Linux/Libs/")
file(MAKE_DIRECTORY ${A_OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${A_OUTPUT_DIR})

# Compiler options

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

# Source files

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../Core/")
set(SOURCE_FILES
	"${SOURCE_DIR}/UBCLLibrary.cpp"
	"${SOURCE_DIR}/UModel.cpp")
	
# Headers
	
include_directories(${SOURCE_DIR})

# Create target file

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})


