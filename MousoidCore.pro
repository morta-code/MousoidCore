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
    commandemitter.cpp \
    bluetooth.cpp

HEADERS += mousoidcore.hpp\
        MousoidCore_global.hpp \
    ethernet.hpp \
    mousoid_constants.hpp \
    commandemitter.hpp \
    bluetooth.hpp

linux-g++ | linux-g++-64 | linux-g++-32 {
    LIBS += -lX11 \
            -lXtst
    SOURCES += commandemitter_x11.cpp
    HEADERS += commandemitter_x11.hpp
}
windows {
    LIBS += -lUser32
    SOURCES += commandemitter_win.cpp
    HEADERS += commandemitter_win.hpp
}

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

OTHER_FILES += \
    README.md \
    LICENSE.md
