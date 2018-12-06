/****************************************************************************
** Meta object code from reading C++ file 'logger.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Helper/Logger/logger.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Logger_t {
    QByteArrayData data[13];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Logger_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Logger_t qt_meta_stringdata_Logger = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Logger"
QT_MOC_LITERAL(1, 7, 5), // "logOn"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 6), // "logOff"
QT_MOC_LITERAL(4, 21, 3), // "log"
QT_MOC_LITERAL(5, 25, 7), // "LogType"
QT_MOC_LITERAL(6, 33, 4), // "type"
QT_MOC_LITERAL(7, 38, 3), // "msg"
QT_MOC_LITERAL(8, 42, 1), // "d"
QT_MOC_LITERAL(9, 44, 1), // "i"
QT_MOC_LITERAL(10, 46, 1), // "w"
QT_MOC_LITERAL(11, 48, 1), // "e"
QT_MOC_LITERAL(12, 50, 10) // "getLogPath"

    },
    "Logger\0logOn\0\0logOff\0log\0LogType\0type\0"
    "msg\0d\0i\0w\0e\0getLogPath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Logger[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x02 /* Public */,
       3,    0,   55,    2, 0x02 /* Public */,
       4,    2,   56,    2, 0x02 /* Public */,
       8,    1,   61,    2, 0x02 /* Public */,
       9,    1,   64,    2, 0x02 /* Public */,
      10,    1,   67,    2, 0x02 /* Public */,
      11,    1,   70,    2, 0x02 /* Public */,
      12,    0,   73,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QVariant,    7,
    QMetaType::Void, QMetaType::QVariant,    7,
    QMetaType::Void, QMetaType::QVariant,    7,
    QMetaType::Void, QMetaType::QVariant,    7,
    QMetaType::QString,

       0        // eod
};

void Logger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Logger *_t = static_cast<Logger *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->logOn(); break;
        case 1: _t->logOff(); break;
        case 2: _t->log((*reinterpret_cast< LogType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->d((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 4: _t->i((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 5: _t->w((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 6: _t->e((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 7: { QString _r = _t->getLogPath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Logger::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Logger.data,
      qt_meta_data_Logger,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Logger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Logger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Logger.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Logger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
