include(./hwidgetlibrary.pri)
QT       += core widgets


TEMPLATE = lib
CONFIG(debug, debug|release){
    DESTDIR = ../../bin/
    TARGET = hWidgetLibrary_d
} else {
    DESTDIR = ../../bin/
    TARGET = hWidgetLibrary
}

INCLUDEPATH += ../../include/interface/
