/****************************************************************************
** Meta object code from reading C++ file 'hstatuswidgetplugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hstatuswidgetplugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hstatuswidgetplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HStatusWidgetPlugin_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HStatusWidgetPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HStatusWidgetPlugin_t qt_meta_stringdata_HStatusWidgetPlugin = {
    {
QT_MOC_LITERAL(0, 0, 19) // "HStatusWidgetPlugin"

    },
    "HStatusWidgetPlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HStatusWidgetPlugin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void HStatusWidgetPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject HStatusWidgetPlugin::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HStatusWidgetPlugin.data,
    qt_meta_data_HStatusWidgetPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HStatusWidgetPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HStatusWidgetPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HStatusWidgetPlugin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "HWidgetPluginInterface"))
        return static_cast< HWidgetPluginInterface*>(this);
    if (!strcmp(_clname, "org.qt-project.HWidgetPluginInterface"))
        return static_cast< HWidgetPluginInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int HStatusWidgetPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x28,  'o',  'r',  'g',  '.',  'q', 
    't',  '-',  'p',  'r',  'o',  'j',  'e',  'c', 
    't',  '.',  'Q',  't',  '.',  'H',  'W',  'i', 
    'd',  'g',  'e',  't',  'P',  'l',  'u',  'g', 
    'i',  'n',  'I',  'n',  't',  'e',  'r',  'f', 
    'a',  'c',  'e', 
    // "className"
    0x03,  0x73,  'H',  'S',  't',  'a',  't',  'u', 
    's',  'W',  'i',  'd',  'g',  'e',  't',  'P', 
    'l',  'u',  'g',  'i',  'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(HStatusWidgetPlugin, HStatusWidgetPlugin)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
