include(./HLogManage.pri)
QT       += core

CONFIG += c++11
TEMPLATE = lib
CONFIG(debug, debug|release){
    DESTDIR = ../../bin/
    TARGET = hLogManage_d
} else {
    DESTDIR = ../../bin/
    TARGET = hLogManage
}

INCLUDEPATH += ../../include/interface/

