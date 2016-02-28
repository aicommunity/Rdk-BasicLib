#-------------------------------------------------
#
# Project created by QtCreator 2012-11-11T15:17:55
#
#-------------------------------------------------

QT       -= gui

TARGET = Rdk-BasicLib.qt
TEMPLATE = lib
CONFIG += staticlib

DEFINES += LIBRDK_LIBRARY_EXPORT
DEFINES += RDK_UNICODE_RUN
DEFINES += RDK_QT

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE975DFAE
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = librdk.qt.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
    DESTDIR = $$PWD/../../../../Bin/Platform/Unix/Lib.Qt
}

windows {
    DESTDIR = $$PWD/../../../../Bin/Platform/Win/Lib.Qt
}

HEADERS += \
    ../../Core/UBCLLibrary.h \
    ../../Core/UModel.h

SOURCES += \
    ../../Core/UBCLLibrary.cpp \
    ../../Core/UModel.cpp
