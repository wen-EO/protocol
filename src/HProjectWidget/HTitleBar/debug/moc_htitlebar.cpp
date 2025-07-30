/****************************************************************************
** Meta object code from reading C++ file 'htitlebar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../htitlebar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'htitlebar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HTitleBar_t {
    QByteArrayData data[9];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HTitleBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HTitleBar_t qt_meta_stringdata_HTitleBar = {
    {
QT_MOC_LITERAL(0, 0, 9), // "HTitleBar"
QT_MOC_LITERAL(1, 10, 22), // "on_btnMenu_Min_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 22), // "on_btnMenu_Max_clicked"
QT_MOC_LITERAL(4, 57, 24), // "on_btnMenu_Close_clicked"
QT_MOC_LITERAL(5, 82, 11), // "itemClicked"
QT_MOC_LITERAL(6, 94, 11), // "changeStyle"
QT_MOC_LITERAL(7, 106, 14), // "getItemClicked"
QT_MOC_LITERAL(8, 121, 4) // "name"

    },
    "HTitleBar\0on_btnMenu_Min_clicked\0\0"
    "on_btnMenu_Max_clicked\0on_btnMenu_Close_clicked\0"
    "itemClicked\0changeStyle\0getItemClicked\0"
    "name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HTitleBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void HTitleBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HTitleBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnMenu_Min_clicked(); break;
        case 1: _t->on_btnMenu_Max_clicked(); break;
        case 2: _t->on_btnMenu_Close_clicked(); break;
        case 3: _t->itemClicked(); break;
        case 4: _t->changeStyle(); break;
        case 5: _t->getItemClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HTitleBar::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_HTitleBar.data,
    qt_meta_data_HTitleBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HTitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HTitleBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HTitleBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HTitleBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
