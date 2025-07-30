HEADERS += \
    hwindowapi.h

SOURCES += \
    hwindowapi.cpp
QT       += core widgets
CONFIG += c++11
INCLUDEPATH += ../../../include/

TEMPLATE = lib
CONFIG(debug, debug|release){
    DESTDIR = ../../../bin/
    TARGET = hWindowApi_d
} else {
    DESTDIR = ../../../bin/
    TARGET = hWindowApi
}

FORMS +=
