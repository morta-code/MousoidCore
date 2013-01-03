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

QMAKE_CXXFLAGS_RELEASE += -O4
QMAKE_CFLAGS_RELEASE += -O4

SOURCES += mousoidcore.cpp \
    ethernet.cpp

HEADERS += mousoidcore.hpp\
        MousoidCore_global.hpp \
    ethernet.hpp \
    mousoid_constants.hpp \
    commandemitter.hpp

linux-g++ | linux-g++-64 | linux-g++-32 {
    LIBS += -lX11 \
            -lXtst
    SOURCES += commandemitter_x11.cpp
    HEADERS += commandemitter_x11.hpp
    QMAKE_CXXFLAGS += "-std=c++11"
}
windows {
    LIBS += -lUser32
    SOURCES += commandemitter_win.cpp
    HEADERS += commandemitter_win.hpp

}

CONFIG(debug, debug|release) {
     mac: TARGET = $$join(TARGET,,,_debug)
     win32: TARGET = $$join(TARGET,,,d)
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
