QT       += core widgets


TEMPLATE = lib
CONFIG(debug, debug|release){
    DESTDIR = ../../bin/
    TARGET = hConfigManage_d
} else {
    DESTDIR = ../../bin/
    TARGET = hConfigManage
}

INCLUDEPATH += ../../include/interface/

HEADERS += \
    hconfigmanage.h

SOURCES += \
    hconfigmanage.cpp
