CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(projectbuildplugin)
TEMPLATE    = lib
CONFIG += c++11
HEADERS     = projectbuildplugin.h \
    categoryedit.h \
    componentedit.h \
    datatypeedit.h \
    export.h \
    exportfile.h \
    structedit.h \
    projectbuild.h
SOURCES     = projectbuildplugin.cpp \
    categoryedit.cpp \
    componentedit.cpp \
    datatypeedit.cpp \
    export.cpp \
    exportfile.cpp \
    structedit.cpp \
    projectbuild.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

DESTDIR =   ../../../bin/sysPlugin/function/

INCLUDEPATH += ../../../include/
INCLUDEPATH += ../../../include/define/
INCLUDEPATH += ../../../include/interface/
INCLUDEPATH += ../../api/HUiHelper/QtAwesome/
INCLUDEPATH += ../../api/HUiHelper/HQss/
INCLUDEPATH += ../../HConfigManage/
INCLUDEPATH += ../../api/HWindowApi/
INCLUDEPATH += ../../HPluginManage/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../bin/ -lhUiHelper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../bin/ -lhUiHelper_d
else:unix: CONFIG(release, debug|release) LIBS += -L$$PWD/../../../bin/ -lhUiHelper
else:unix: CONFIG(debug, debug|release) LIBS += -L$$PWD/../../../bin/ -lhUiHelper_d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../bin/ -lhConfigManage
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../bin/ -lhConfigManage_d
else:unix: CONFIG(release, debug|release) LIBS += -L$$PWD/../../../bin/ -lhConfigManage
else:unix: CONFIG(debug, debug|release) LIBS += -L$$PWD/../../../bin/ -lhConfigManage_d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../bin/ -lhWindowApi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../bin/ -lhWindowApi_d
else:unix: CONFIG(release, debug|release) LIBS += -L$$PWD/../../../bin/ -lhWindowApi
else:unix: CONFIG(debug, debug|release) LIBS += -L$$PWD/../../../bin/ -lhWindowApi_d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../bin/ -lhWidgetLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../bin/ -lhWidgetLibrary_d
else:unix: CONFIG(release, debug|release) LIBS += -L$$PWD/../../../bin/ -lhWidgetLibrary
else:unix: CONFIG(debug, debug|release) LIBS += -L$$PWD/../../../bin/ -lhWidgetLibrary_d


greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(projectbuild.pri)

FORMS += \
    categoryedit.ui \
    componentedit.ui \
    datatypeedit.ui \
    export.ui \
    structedit.ui \
    projectbuild.ui

QT += sql \
    printsupport
