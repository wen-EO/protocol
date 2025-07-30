CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(hstatuswidgetplugin)
TEMPLATE    = lib

HEADERS     = hstatuswidgetplugin.h \

SOURCES     = hstatuswidgetplugin.cpp \

RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

DESTDIR =   ../../../bin/sysPlugin/function/

INCLUDEPATH += ../../../include/define/
INCLUDEPATH += ../../../include/interface/
INCLUDEPATH += ../../api/HUiHelper/QtAwesome/
INCLUDEPATH += ../../HConfigManage/
INCLUDEPATH += ../../api/HWindowApi/

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(hstatuswidget.pri)

