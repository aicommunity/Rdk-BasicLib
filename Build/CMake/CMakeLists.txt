cmake_minimum_required(VERSION 3.0)
project(Rdk-BasicLib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(QT_NO_GUI ON)

add_library(Rdk-BasicLib STATIC)

include_directories(${CMAKE_SOURCE_DIR}/../../../../Rdk/Deploy/Include)

set(SOURCES
    ../../Core/UBCLLibrary.cpp
    ../../Core/UIO.cpp
    ../../Core/UIOConverter.cpp
    ../../Core/UIOLibrary.cpp
    ../../Core/UMatrixSource.cpp
    ../../Core/UMatrixSourceDataFile.cpp
    ../../Core/UMatrixSourceTimeSeries.cpp
    ../../Core/UModel.cpp
    ../../Core/UNoise.cpp
    ../../Core/UNoiseGen.cpp
    ../../Core/UScalarSource.cpp
    ../../Core/UStatistic.cpp
    ../../Core/UFileDataset.cpp
    ../../Core/UMatrixSourceFile.cpp
    ../../Core/UMatrixSourceFileSep.cpp
)

set(HEADERS
    ../../Core/UBCLLibrary.h
    ../../Core/UIO.h
    ../../Core/UIOConverter.h
    ../../Core/UIOLibrary.h
    ../../Core/UMatrixSource.h
    ../../Core/UMatrixSourceDataFile.h
    ../../Core/UMatrixSourceTimeSeries.h
    ../../Core/UModel.h
    ../../Core/UNoise.h
    ../../Core/UNoiseGen.h
    ../../Core/UScalarSource.h
    ../../Core/UStatistic.h
    ../../Core/UFileDataset.h
    ../../Core/UMatrixSourceFile.h
    ../../Core/UMatrixSourceFileSep.h
)

target_sources(Rdk-BasicLib PRIVATE ${SOURCES} ${HEADERS})

set(VERSION 0)
add_definitions(-DRDK_LIB_CVS_REVISION=${VERSION})

if(UNIX)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../../../../Bin/Platform/Linux/Lib.Qt)
elseif(WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../../../../Bin/Platform/Win/Lib.Qt)
endif()
