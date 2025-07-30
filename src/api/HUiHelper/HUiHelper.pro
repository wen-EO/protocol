include(./QtAwesome/QtAwesome.pri)
include(./HQss/hqss.pri)
QT       += core widgets

CONFIG += c++11
TEMPLATE = lib
CONFIG(debug, debug|release){
    DESTDIR = ../../../bin/
    TARGET = hUiHelper_d
} else {
    DESTDIR = ../../../bin/
    TARGET = hUiHelper
}
