/****************************************************************************
** Meta object code from reading C++ file 'hwindowapi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hwindowapi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hwindowapi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HWindowApi_t {
    QByteArrayData data[14];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HWindowApi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HWindowApi_t qt_meta_stringdata_HWindowApi = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HWindowApi"
QT_MOC_LITERAL(1, 11, 16), // "titleItemClicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "name"
QT_MOC_LITERAL(4, 34, 14), // "clickTitleItem"
QT_MOC_LITERAL(5, 49, 8), // "itemName"
QT_MOC_LITERAL(6, 58, 11), // "openProject"
QT_MOC_LITERAL(7, 70, 9), // "projectId"
QT_MOC_LITERAL(8, 80, 14), // "refreshCatgory"
QT_MOC_LITERAL(9, 95, 15), // "refreshProtocol"
QT_MOC_LITERAL(10, 111, 18), // "structFileSelected"
QT_MOC_LITERAL(11, 130, 8), // "fileName"
QT_MOC_LITERAL(12, 139, 16), // "_STRUCT_VECTOR_T"
QT_MOC_LITERAL(13, 156, 8) // "fileInfo"

    },
    "HWindowApi\0titleItemClicked\0\0name\0"
    "clickTitleItem\0itemName\0openProject\0"
    "projectId\0refreshCatgory\0refreshProtocol\0"
    "structFileSelected\0fileName\0"
    "_STRUCT_VECTOR_T\0fileInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HWindowApi[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,
       8,    0,   53,    2, 0x06 /* Public */,
       9,    0,   54,    2, 0x06 /* Public */,
      10,    2,   55,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 12,   11,   13,

       0        // eod
};

void HWindowApi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HWindowApi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->titleItemClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->clickTitleItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->openProject((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->refreshCatgory(); break;
        case 4: _t->refreshProtocol(); break;
        case 5: _t->structFileSelected((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const _STRUCT_VECTOR_T(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HWindowApi::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HWindowApi::titleItemClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HWindowApi::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HWindowApi::clickTitleItem)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HWindowApi::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HWindowApi::openProject)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (HWindowApi::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HWindowApi::refreshCatgory)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (HWindowApi::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HWindowApi::refreshProtocol)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (HWindowApi::*)(const QString & , const _STRUCT_VECTOR_T & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HWindowApi::structFileSelected)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HWindowApi::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HWindowApi.data,
    qt_meta_data_HWindowApi,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HWindowApi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HWindowApi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HWindowApi.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HWindowApi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void HWindowApi::titleItemClicked(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HWindowApi::clickTitleItem(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HWindowApi::openProject(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void HWindowApi::refreshCatgory()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void HWindowApi::refreshProtocol()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void HWindowApi::structFileSelected(const QString & _t1, const _STRUCT_VECTOR_T & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
