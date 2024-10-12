#-------------------------------------------------
#
# Project created by QtCreator 2012-11-11T15:17:55
#
#-------------------------------------------------

QT       -= gui

TARGET = Rdk-BasicLib.qt
TEMPLATE = lib
CONFIG += staticlib

include($$PWD/../../../../Rdk/Build/Lib/Qt/RdkDefines.pri)

INCLUDEPATH += $$PWD/../../../../Rdk/Deploy/Include

VERSION = 0 # $$system(hg parents --template '{rev}')
DEFINES += RDK_LIB_CVS_REVISION=$$VERSION

unix {
    DESTDIR = $$PWD/../../../../Bin/Platform/Linux/Lib.Qt
}

windows {
    DESTDIR = $$PWD/../../../../Bin/Platform/Win/Lib.Qt
}

windows {

HEADERS += \
    ../../Core/UFileDataset.h \
    ../../Core/UMatrixSourceFile.h \
    ../../Core/UMatrixSourceFileSep.h

SOURCES += \
    ../../Core/UFileDataset.cpp \
    ../../Core/UMatrixSourceFile.cpp \
    ../../Core/UMatrixSourceFileSep.cpp
}

HEADERS += \
    ../../Core/UBCLLibrary.h \
    ../../Core/UIO.h \
    ../../Core/UIOConverter.h \
    ../../Core/UIOLibrary.h \
    ../../Core/UMatrixSource.h \
    ../../Core/UMatrixSourceDataFile.h \
    ../../Core/UMatrixSourceTimeSeries.h \
    ../../Core/UModel.h \
    ../../Core/UNoise.h \
    ../../Core/UNoiseGen.h \
    ../../Core/UScalarSource.h \
    ../../Core/UStatistic.h

SOURCES += \
    ../../Core/UBCLLibrary.cpp \
    ../../Core/UIO.cpp \
    ../../Core/UIOConverter.cpp \
    ../../Core/UIOLibrary.cpp \
    ../../Core/UMatrixSource.cpp \
    ../../Core/UMatrixSourceDataFile.cpp \
    ../../Core/UMatrixSourceTimeSeries.cpp \
    ../../Core/UModel.cpp \
    ../../Core/UNoise.cpp \
    ../../Core/UNoiseGen.cpp \
    ../../Core/UScalarSource.cpp \
    ../../Core/UStatistic.cpp
