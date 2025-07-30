/****************************************************************************
** Meta object code from reading C++ file 'mywizard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mywizard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywizard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyWizard_t {
    QByteArrayData data[11];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyWizard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyWizard_t qt_meta_stringdata_MyWizard = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyWizard"
QT_MOC_LITERAL(1, 9, 32), // "on_pushButton_selectPath_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 30), // "on_wizard_finishButton_clicked"
QT_MOC_LITERAL(4, 74, 19), // "validateCurrentPage"
QT_MOC_LITERAL(5, 94, 14), // "copyFileToPath"
QT_MOC_LITERAL(6, 109, 9), // "sourceDir"
QT_MOC_LITERAL(7, 119, 5), // "toDir"
QT_MOC_LITERAL(8, 125, 16), // "coverFileIfExist"
QT_MOC_LITERAL(9, 142, 18), // "copyDirectoryFiles"
QT_MOC_LITERAL(10, 161, 7) // "fromDir"

    },
    "MyWizard\0on_pushButton_selectPath_clicked\0"
    "\0on_wizard_finishButton_clicked\0"
    "validateCurrentPage\0copyFileToPath\0"
    "sourceDir\0toDir\0coverFileIfExist\0"
    "copyDirectoryFiles\0fromDir"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyWizard[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    3,   42,    2, 0x08 /* Private */,
       9,    3,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    6,    7,    8,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   10,    7,    8,

       0        // eod
};

void MyWizard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyWizard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_selectPath_clicked(); break;
        case 1: _t->on_wizard_finishButton_clicked(); break;
        case 2: { bool _r = _t->validateCurrentPage();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->copyFileToPath((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->copyDirectoryFiles((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyWizard::staticMetaObject = { {
    &QWizard::staticMetaObject,
    qt_meta_stringdata_MyWizard.data,
    qt_meta_data_MyWizard,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyWizard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyWizard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyWizard.stringdata0))
        return static_cast<void*>(this);
    return QWizard::qt_metacast(_clname);
}

int MyWizard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizard::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
