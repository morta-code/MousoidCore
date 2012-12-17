#-------------------------------------------------
#
# Project created by QtCreator 2012-11-11T07:27:42
#
#-------------------------------------------------

QT       += network
QT       -= gui

TARGET = MousoidCore
TEMPLATE = lib

DEFINES += MOUSOIDCORE_LIBRARY

SOURCES += mousoidcore.cpp \
    ethernet.cpp \
    commandemitter.cpp

HEADERS += mousoidcore.hpp\
        MousoidCore_global.hpp \
    ethernet.hpp \
    mousoid_constants.hpp \
    commandemitter.hpp

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE179D7D2
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = MousoidCore.dll
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
}

VERSION = 1.0.0
