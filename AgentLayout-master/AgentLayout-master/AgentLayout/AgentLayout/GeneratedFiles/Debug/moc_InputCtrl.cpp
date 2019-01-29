/****************************************************************************
** Meta object code from reading C++ file 'InputCtrl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../InputCtrl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InputCtrl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InputCtrl_t {
    QByteArrayData data[11];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InputCtrl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InputCtrl_t qt_meta_stringdata_InputCtrl = {
    {
QT_MOC_LITERAL(0, 0, 9), // "InputCtrl"
QT_MOC_LITERAL(1, 10, 10), // "ShowLayout"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "scale"
QT_MOC_LITERAL(4, 28, 4), // "mode"
QT_MOC_LITERAL(5, 33, 5), // "param"
QT_MOC_LITERAL(6, 39, 9), // "WriteFile"
QT_MOC_LITERAL(7, 49, 17), // "ShowLayoutClicked"
QT_MOC_LITERAL(8, 67, 10), // "ModeSwitch"
QT_MOC_LITERAL(9, 78, 11), // "ChangeScale"
QT_MOC_LITERAL(10, 90, 3) // "val"

    },
    "InputCtrl\0ShowLayout\0\0scale\0mode\0param\0"
    "WriteFile\0ShowLayoutClicked\0ModeSwitch\0"
    "ChangeScale\0val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InputCtrl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,
       6,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   47,    2, 0x08 /* Private */,
       8,    0,   48,    2, 0x08 /* Private */,
       9,    1,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Int, QMetaType::Float,    3,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void InputCtrl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InputCtrl *_t = static_cast<InputCtrl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowLayout((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 1: _t->WriteFile(); break;
        case 2: _t->ShowLayoutClicked(); break;
        case 3: _t->ModeSwitch(); break;
        case 4: _t->ChangeScale((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InputCtrl::*)(float , int , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputCtrl::ShowLayout)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (InputCtrl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputCtrl::WriteFile)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject InputCtrl::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_InputCtrl.data,
    qt_meta_data_InputCtrl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InputCtrl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InputCtrl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InputCtrl.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int InputCtrl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void InputCtrl::ShowLayout(float _t1, int _t2, float _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InputCtrl::WriteFile()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
