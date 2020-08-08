/****************************************************************************
** Meta object code from reading C++ file 'dialog_serialsync.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dialog_serialsync.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_serialsync.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_SerialSync_t {
    QByteArrayData data[20];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_SerialSync_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_SerialSync_t qt_meta_stringdata_Dialog_SerialSync = {
    {
QT_MOC_LITERAL(0, 0, 17), // "Dialog_SerialSync"
QT_MOC_LITERAL(1, 18, 9), // "connected"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "vs_pkt_t"
QT_MOC_LITERAL(4, 38, 3), // "pkt"
QT_MOC_LITERAL(5, 42, 12), // "myplcChanged"
QT_MOC_LITERAL(6, 55, 11), // "serialBegin"
QT_MOC_LITERAL(7, 67, 3), // "com"
QT_MOC_LITERAL(8, 71, 9), // "serialEnd"
QT_MOC_LITERAL(9, 81, 11), // "serialError"
QT_MOC_LITERAL(10, 93, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(11, 122, 5), // "error"
QT_MOC_LITERAL(12, 128, 19), // "serialProtocolError"
QT_MOC_LITERAL(13, 148, 12), // "updateLabels"
QT_MOC_LITERAL(14, 161, 9), // "vs_info_t"
QT_MOC_LITERAL(15, 171, 5), // "infos"
QT_MOC_LITERAL(16, 177, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(17, 198, 16), // "QAbstractButton*"
QT_MOC_LITERAL(18, 215, 6), // "button"
QT_MOC_LITERAL(19, 222, 9) // "onReceive"

    },
    "Dialog_SerialSync\0connected\0\0vs_pkt_t\0"
    "pkt\0myplcChanged\0serialBegin\0com\0"
    "serialEnd\0serialError\0"
    "QSerialPort::SerialPortError\0error\0"
    "serialProtocolError\0updateLabels\0"
    "vs_info_t\0infos\0on_buttonBox_clicked\0"
    "QAbstractButton*\0button\0onReceive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog_SerialSync[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   63,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x0a /* Public */,
       9,    1,   67,    2, 0x0a /* Public */,
      12,    1,   70,    2, 0x0a /* Public */,
      13,    1,   73,    2, 0x0a /* Public */,
      16,    1,   76,    2, 0x0a /* Public */,
      19,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,

       0        // eod
};

void Dialog_SerialSync::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog_SerialSync *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected((*reinterpret_cast< const vs_pkt_t(*)>(_a[1]))); break;
        case 1: _t->myplcChanged(); break;
        case 2: _t->serialBegin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->serialEnd(); break;
        case 4: _t->serialError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 5: _t->serialProtocolError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->updateLabels((*reinterpret_cast< const vs_info_t(*)>(_a[1]))); break;
        case 7: _t->on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 8: _t->onReceive(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
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
            using _t = void (Dialog_SerialSync::*)(const vs_pkt_t & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_SerialSync::connected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Dialog_SerialSync::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_SerialSync::myplcChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog_SerialSync::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog_SerialSync.data,
    qt_meta_data_Dialog_SerialSync,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog_SerialSync::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_SerialSync::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_SerialSync.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog_SerialSync::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Dialog_SerialSync::connected(const vs_pkt_t & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dialog_SerialSync::myplcChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
