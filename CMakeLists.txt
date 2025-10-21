cmake_minimum_required(VERSION 3.16)
project(Rdk_BasicLib LANGUAGES CXX)

set(TARGET_NAME Rdk-BasicLib.qt)

add_library(${TARGET_NAME} STATIC)

target_include_directories(${TARGET_NAME}
  PUBLIC
    ${CMAKE_SOURCE_DIR}/Rdk/Deploy/Include
    ${CMAKE_SOURCE_DIR}/Libraries/Rdk-BasicLib/Core
    ${CMAKE_SOURCE_DIR}/Rdk/Core/Engine
    ${CMAKE_SOURCE_DIR}/Rdk/Core/System
)

file(GLOB BASIC_SOURCES
  ${CMAKE_SOURCE_DIR}/Libraries/Rdk-BasicLib/Core/*.cpp
)

if (UNIX)
  list(FILTER BASIC_SOURCES EXCLUDE REGEX "/Libraries/Rdk-BasicLib/Core/UFileDataset\\.cpp$")
  list(FILTER BASIC_SOURCES EXCLUDE REGEX "/Libraries/Rdk-BasicLib/Core/UMatrixSourceFile\\.cpp$")
  list(FILTER BASIC_SOURCES EXCLUDE REGEX "/Libraries/Rdk-BasicLib/Core/UMatrixSourceFileSep\\.cpp$")
  list(FILTER BASIC_SOURCES EXCLUDE REGEX "/Libraries/Rdk-BasicLib/Core/UFileIO\\.cpp$")
  list(FILTER BASIC_SOURCES EXCLUDE REGEX "/Libraries/Rdk-BasicLib/Core/UIOTextConverter\\.cpp$")
endif()

target_sources(${TARGET_NAME}
  PRIVATE ${BASIC_SOURCES}
)

target_compile_definitions(${TARGET_NAME} PUBLIC RDK_LIB_CVS_REVISION=0 RDK_QT)

find_package(Qt5 REQUIRED COMPONENTS Core)
target_link_libraries(${TARGET_NAME} PUBLIC Qt5::Core Threads::Threads rdk.static.qt)
