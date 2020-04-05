/****************************************************************************
** Meta object code from reading C++ file 'dialog_serialretrieve.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dialog_serialretrieve.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_serialretrieve.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogSerialRetrieve_t {
    QByteArrayData data[17];
    char stringdata0[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogSerialRetrieve_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogSerialRetrieve_t qt_meta_stringdata_DialogSerialRetrieve = {
    {
QT_MOC_LITERAL(0, 0, 20), // "DialogSerialRetrieve"
QT_MOC_LITERAL(1, 21, 9), // "Retrieved"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7), // "Rwrited"
QT_MOC_LITERAL(4, 40, 10), // "serialOpen"
QT_MOC_LITERAL(5, 51, 10), // "serialRead"
QT_MOC_LITERAL(6, 62, 11), // "serialClose"
QT_MOC_LITERAL(7, 74, 11), // "handleError"
QT_MOC_LITERAL(8, 86, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(9, 115, 5), // "error"
QT_MOC_LITERAL(10, 121, 20), // "on_pbConnect_clicked"
QT_MOC_LITERAL(11, 142, 21), // "on_pbRetrieve_clicked"
QT_MOC_LITERAL(12, 164, 20), // "on_pbRewrite_clicked"
QT_MOC_LITERAL(13, 185, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(14, 206, 16), // "QAbstractButton*"
QT_MOC_LITERAL(15, 223, 6), // "button"
QT_MOC_LITERAL(16, 230, 12) // "updateLabels"

    },
    "DialogSerialRetrieve\0Retrieved\0\0Rwrited\0"
    "serialOpen\0serialRead\0serialClose\0"
    "handleError\0QSerialPort::SerialPortError\0"
    "error\0on_pbConnect_clicked\0"
    "on_pbRetrieve_clicked\0on_pbRewrite_clicked\0"
    "on_buttonBox_clicked\0QAbstractButton*\0"
    "button\0updateLabels"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogSerialRetrieve[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,
      13,    1,   80,    2, 0x08 /* Private */,
      16,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,

       0        // eod
};

void DialogSerialRetrieve::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogSerialRetrieve *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Retrieved(); break;
        case 1: _t->Rwrited(); break;
        case 2: { bool _r = _t->serialOpen();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->serialRead(); break;
        case 4: _t->serialClose(); break;
        case 5: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 6: _t->on_pbConnect_clicked(); break;
        case 7: _t->on_pbRetrieve_clicked(); break;
        case 8: _t->on_pbRewrite_clicked(); break;
        case 9: _t->on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 10: _t->updateLabels(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DialogSerialRetrieve::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogSerialRetrieve::Retrieved)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DialogSerialRetrieve::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogSerialRetrieve::Rwrited)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DialogSerialRetrieve::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogSerialRetrieve.data,
    qt_meta_data_DialogSerialRetrieve,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogSerialRetrieve::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogSerialRetrieve::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogSerialRetrieve.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogSerialRetrieve::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void DialogSerialRetrieve::Retrieved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DialogSerialRetrieve::Rwrited()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
