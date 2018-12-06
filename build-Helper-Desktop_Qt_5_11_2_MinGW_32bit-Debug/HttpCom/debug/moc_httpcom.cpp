/****************************************************************************
** Meta object code from reading C++ file 'httpcom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Helper/HttpCom/httpcom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpcom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpCom_t {
    QByteArrayData data[19];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpCom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpCom_t qt_meta_stringdata_HttpCom = {
    {
QT_MOC_LITERAL(0, 0, 7), // "HttpCom"
QT_MOC_LITERAL(1, 8, 21), // "hasDataComeFromServer"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "data"
QT_MOC_LITERAL(4, 36, 12), // "requestError"
QT_MOC_LITERAL(5, 49, 9), // "errorCode"
QT_MOC_LITERAL(6, 59, 15), // "requestFinished"
QT_MOC_LITERAL(7, 75, 9), // "slotError"
QT_MOC_LITERAL(8, 85, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(9, 113, 7), // "errCode"
QT_MOC_LITERAL(10, 121, 22), // "sendDataToServerByPost"
QT_MOC_LITERAL(11, 144, 3), // "url"
QT_MOC_LITERAL(12, 148, 22), // "getDataFromServerByGet"
QT_MOC_LITERAL(13, 171, 19), // "setRequestRawHeader"
QT_MOC_LITERAL(14, 191, 3), // "key"
QT_MOC_LITERAL(15, 195, 5), // "value"
QT_MOC_LITERAL(16, 201, 16), // "setRequestHeader"
QT_MOC_LITERAL(17, 218, 29), // "QNetworkRequest::KnownHeaders"
QT_MOC_LITERAL(18, 248, 6) // "header"

    },
    "HttpCom\0hasDataComeFromServer\0\0data\0"
    "requestError\0errorCode\0requestFinished\0"
    "slotError\0QNetworkReply::NetworkError\0"
    "errCode\0sendDataToServerByPost\0url\0"
    "getDataFromServerByGet\0setRequestRawHeader\0"
    "key\0value\0setRequestHeader\0"
    "QNetworkRequest::KnownHeaders\0header"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpCom[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   70,    2, 0x08 /* Private */,
       7,    1,   71,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      10,    2,   74,    2, 0x02 /* Public */,
      10,    2,   79,    2, 0x02 /* Public */,
      12,    1,   84,    2, 0x02 /* Public */,
      12,    1,   87,    2, 0x02 /* Public */,
      13,    2,   90,    2, 0x02 /* Public */,
      16,    2,   95,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

 // methods: parameters
    QMetaType::Void, QMetaType::QUrl, QMetaType::QByteArray,   11,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray,   11,    3,
    QMetaType::Void, QMetaType::QUrl,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,   14,   15,
    QMetaType::Void, 0x80000000 | 17, QMetaType::QVariant,   18,   15,

       0        // eod
};

void HttpCom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HttpCom *_t = static_cast<HttpCom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hasDataComeFromServer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->requestError((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->requestFinished(); break;
        case 3: _t->slotError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 4: _t->sendDataToServerByPost((*reinterpret_cast< QUrl(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 5: _t->sendDataToServerByPost((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 6: _t->getDataFromServerByGet((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 7: _t->getDataFromServerByGet((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setRequestRawHeader((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 9: _t->setRequestHeader((*reinterpret_cast< QNetworkRequest::KnownHeaders(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HttpCom::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpCom::hasDataComeFromServer)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HttpCom::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpCom::requestError)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HttpCom::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HttpCom.data,
      qt_meta_data_HttpCom,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HttpCom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpCom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpCom.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpCom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void HttpCom::hasDataComeFromServer(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HttpCom::requestError(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
