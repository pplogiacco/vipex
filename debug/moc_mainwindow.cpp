/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[316];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "fileOpen"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "fileSave"
QT_MOC_LITERAL(4, 30, 10), // "fileSaveAs"
QT_MOC_LITERAL(5, 41, 5), // "about"
QT_MOC_LITERAL(6, 47, 10), // "myplcClean"
QT_MOC_LITERAL(7, 58, 7), // "refresh"
QT_MOC_LITERAL(8, 66, 8), // "editItem"
QT_MOC_LITERAL(9, 75, 22), // "viewModulesContextMenu"
QT_MOC_LITERAL(10, 98, 27), // "on_actionRetrieve_triggered"
QT_MOC_LITERAL(11, 126, 7), // "checked"
QT_MOC_LITERAL(12, 134, 32), // "on_actionSerialConnect_triggered"
QT_MOC_LITERAL(13, 167, 17), // "showStatusMessage"
QT_MOC_LITERAL(14, 185, 7), // "message"
QT_MOC_LITERAL(15, 193, 21), // "cbxSerialPort_refresh"
QT_MOC_LITERAL(16, 215, 19), // "deviceInfos_refresh"
QT_MOC_LITERAL(17, 235, 4), // "save"
QT_MOC_LITERAL(18, 240, 28), // "on_actionAddModule_triggered"
QT_MOC_LITERAL(19, 269, 28), // "on_viewModules_doubleClicked"
QT_MOC_LITERAL(20, 298, 11), // "QModelIndex"
QT_MOC_LITERAL(21, 310, 5) // "index"

    },
    "MainWindow\0fileOpen\0\0fileSave\0fileSaveAs\0"
    "about\0myplcClean\0refresh\0editItem\0"
    "viewModulesContextMenu\0"
    "on_actionRetrieve_triggered\0checked\0"
    "on_actionSerialConnect_triggered\0"
    "showStatusMessage\0message\0"
    "cbxSerialPort_refresh\0deviceInfos_refresh\0"
    "save\0on_actionAddModule_triggered\0"
    "on_viewModules_doubleClicked\0QModelIndex\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x0a /* Public */,
       5,    0,   97,    2, 0x0a /* Public */,
       6,    0,   98,    2, 0x0a /* Public */,
       7,    0,   99,    2, 0x0a /* Public */,
       8,    0,  100,    2, 0x0a /* Public */,
       9,    1,  101,    2, 0x0a /* Public */,
      10,    1,  104,    2, 0x08 /* Private */,
      12,    1,  107,    2, 0x08 /* Private */,
      13,    1,  110,    2, 0x08 /* Private */,
      15,    0,  113,    2, 0x08 /* Private */,
      16,    0,  114,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,
      18,    1,  116,    2, 0x08 /* Private */,
      19,    1,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, 0x80000000 | 20,   21,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fileOpen(); break;
        case 1: _t->fileSave(); break;
        case 2: _t->fileSaveAs(); break;
        case 3: _t->about(); break;
        case 4: _t->myplcClean(); break;
        case 5: _t->refresh(); break;
        case 6: _t->editItem(); break;
        case 7: _t->viewModulesContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 8: _t->on_actionRetrieve_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_actionSerialConnect_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->showStatusMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->cbxSerialPort_refresh(); break;
        case 12: _t->deviceInfos_refresh(); break;
        case 13: _t->save(); break;
        case 14: _t->on_actionAddModule_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_viewModules_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
