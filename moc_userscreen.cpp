/****************************************************************************
** Meta object code from reading C++ file 'userscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "userscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserScreen_t {
    QByteArrayData data[11];
    char stringdata[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UserScreen_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UserScreen_t qt_meta_stringdata_UserScreen = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 7),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 7),
QT_MOC_LITERAL(4, 28, 6),
QT_MOC_LITERAL(5, 35, 7),
QT_MOC_LITERAL(6, 43, 1),
QT_MOC_LITERAL(7, 45, 7),
QT_MOC_LITERAL(8, 53, 23),
QT_MOC_LITERAL(9, 77, 21),
QT_MOC_LITERAL(10, 99, 11)
    },
    "UserScreen\0stopCap\0\0respond\0imShow\0"
    "cv::Mat\0m\0sendPic\0on_pushButton_2_clicked\0"
    "on_pushButton_clicked\0captureStop\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x0a,
       4,    1,   51,    2, 0x0a,
       7,    0,   54,    2, 0x0a,
       8,    0,   55,    2, 0x08,
       9,    0,   56,    2, 0x08,
      10,    0,   57,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserScreen *_t = static_cast<UserScreen *>(_o);
        switch (_id) {
        case 0: _t->stopCap(); break;
        case 1: _t->respond(); break;
        case 2: _t->imShow((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 3: _t->sendPic(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->captureStop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UserScreen::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UserScreen::stopCap)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject UserScreen::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UserScreen.data,
      qt_meta_data_UserScreen,  qt_static_metacall, 0, 0}
};


const QMetaObject *UserScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserScreen.stringdata))
        return static_cast<void*>(const_cast< UserScreen*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UserScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void UserScreen::stopCap()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
