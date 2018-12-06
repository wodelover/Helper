/****************************************************************************
** Meta object code from reading C++ file 'face.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Helper/Face/face.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'face.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Face_t {
    QByteArrayData data[36];
    char stringdata0[460];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Face_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Face_t qt_meta_stringdata_Face = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Face"
QT_MOC_LITERAL(1, 5, 16), // "faceAppIDChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "appID"
QT_MOC_LITERAL(4, 29, 14), // "faceKeyChanged"
QT_MOC_LITERAL(5, 44, 3), // "key"
QT_MOC_LITERAL(6, 48, 12), // "setFaceAppID"
QT_MOC_LITERAL(7, 61, 10), // "setFaceKey"
QT_MOC_LITERAL(8, 72, 9), // "faceAppID"
QT_MOC_LITERAL(9, 82, 7), // "faceKey"
QT_MOC_LITERAL(10, 90, 24), // "VerifyAirFaceOperaterKey"
QT_MOC_LITERAL(11, 115, 14), // "InitFaceEngine"
QT_MOC_LITERAL(12, 130, 29), // "AirFaceOperater::DetectedMode"
QT_MOC_LITERAL(13, 160, 4), // "mode"
QT_MOC_LITERAL(14, 165, 31), // "AirFaceOperater::OrientPriority"
QT_MOC_LITERAL(15, 197, 8), // "priority"
QT_MOC_LITERAL(16, 206, 13), // "FaceDetection"
QT_MOC_LITERAL(17, 220, 33), // "vector<AirFaceOperater::FaceR..."
QT_MOC_LITERAL(18, 254, 4), // "path"
QT_MOC_LITERAL(19, 259, 4), // "Mat&"
QT_MOC_LITERAL(20, 264, 3), // "img"
QT_MOC_LITERAL(21, 268, 7), // "QImage&"
QT_MOC_LITERAL(22, 276, 14), // "FaceComparison"
QT_MOC_LITERAL(23, 291, 7), // "srcPath"
QT_MOC_LITERAL(24, 299, 7), // "dstPath"
QT_MOC_LITERAL(25, 307, 13), // "mutilpCompare"
QT_MOC_LITERAL(26, 321, 6), // "srcImg"
QT_MOC_LITERAL(27, 328, 6), // "dstImg"
QT_MOC_LITERAL(28, 335, 7), // "GetAges"
QT_MOC_LITERAL(29, 343, 11), // "vector<int>"
QT_MOC_LITERAL(30, 355, 7), // "imgPath"
QT_MOC_LITERAL(31, 363, 9), // "GetGender"
QT_MOC_LITERAL(32, 373, 10), // "Get3DAngle"
QT_MOC_LITERAL(33, 384, 34), // "vector<AirFaceOperater::FaceA..."
QT_MOC_LITERAL(34, 419, 18), // "GetFaceVersionInfo"
QT_MOC_LITERAL(35, 438, 21) // "QMap<QString,QString>"

    },
    "Face\0faceAppIDChanged\0\0appID\0"
    "faceKeyChanged\0key\0setFaceAppID\0"
    "setFaceKey\0faceAppID\0faceKey\0"
    "VerifyAirFaceOperaterKey\0InitFaceEngine\0"
    "AirFaceOperater::DetectedMode\0mode\0"
    "AirFaceOperater::OrientPriority\0"
    "priority\0FaceDetection\0"
    "vector<AirFaceOperater::FaceRect>\0"
    "path\0Mat&\0img\0QImage&\0FaceComparison\0"
    "srcPath\0dstPath\0mutilpCompare\0srcImg\0"
    "dstImg\0GetAges\0vector<int>\0imgPath\0"
    "GetGender\0Get3DAngle\0"
    "vector<AirFaceOperater::FaceAngle>\0"
    "GetFaceVersionInfo\0QMap<QString,QString>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Face[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       2,  256, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  159,    2, 0x06 /* Public */,
       4,    1,  162,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    1,  165,    2, 0x02 /* Public */,
       7,    1,  168,    2, 0x02 /* Public */,
       8,    0,  171,    2, 0x02 /* Public */,
       9,    0,  172,    2, 0x02 /* Public */,
      10,    0,  173,    2, 0x02 /* Public */,
      11,    2,  174,    2, 0x02 /* Public */,
      11,    1,  179,    2, 0x22 /* Public | MethodCloned */,
      11,    0,  182,    2, 0x22 /* Public | MethodCloned */,
      16,    1,  183,    2, 0x02 /* Public */,
      16,    1,  186,    2, 0x02 /* Public */,
      16,    1,  189,    2, 0x02 /* Public */,
      22,    3,  192,    2, 0x02 /* Public */,
      22,    2,  199,    2, 0x22 /* Public | MethodCloned */,
      22,    3,  204,    2, 0x02 /* Public */,
      22,    2,  211,    2, 0x22 /* Public | MethodCloned */,
      22,    3,  216,    2, 0x02 /* Public */,
      22,    2,  223,    2, 0x22 /* Public | MethodCloned */,
      28,    1,  228,    2, 0x02 /* Public */,
      28,    1,  231,    2, 0x02 /* Public */,
      28,    1,  234,    2, 0x02 /* Public */,
      31,    1,  237,    2, 0x02 /* Public */,
      31,    1,  240,    2, 0x02 /* Public */,
      31,    1,  243,    2, 0x02 /* Public */,
      32,    1,  246,    2, 0x02 /* Public */,
      32,    1,  249,    2, 0x02 /* Public */,
      32,    1,  252,    2, 0x02 /* Public */,
      34,    0,  255,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::Bool, 0x80000000 | 12, 0x80000000 | 14,   13,   15,
    QMetaType::Bool, 0x80000000 | 12,   13,
    QMetaType::Bool,
    0x80000000 | 17, QMetaType::QString,   18,
    0x80000000 | 17, 0x80000000 | 19,   20,
    0x80000000 | 17, 0x80000000 | 21,   20,
    QMetaType::Float, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   23,   24,   25,
    QMetaType::Float, QMetaType::QString, QMetaType::QString,   23,   24,
    QMetaType::Float, 0x80000000 | 19, 0x80000000 | 19, QMetaType::Bool,   26,   27,   25,
    QMetaType::Float, 0x80000000 | 19, 0x80000000 | 19,   26,   27,
    QMetaType::Float, 0x80000000 | 21, 0x80000000 | 21, QMetaType::Bool,   26,   27,   25,
    QMetaType::Float, 0x80000000 | 21, 0x80000000 | 21,   26,   27,
    0x80000000 | 29, QMetaType::QString,   30,
    0x80000000 | 29, 0x80000000 | 19,   20,
    0x80000000 | 29, 0x80000000 | 21,   20,
    0x80000000 | 29, QMetaType::QString,   30,
    0x80000000 | 29, 0x80000000 | 19,   20,
    0x80000000 | 29, 0x80000000 | 21,   20,
    0x80000000 | 33, QMetaType::QString,   30,
    0x80000000 | 33, 0x80000000 | 19,   20,
    0x80000000 | 33, 0x80000000 | 21,   20,
    0x80000000 | 35,

 // properties: name, type, flags
       8, QMetaType::QString, 0x00495103,
       9, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void Face::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Face *_t = static_cast<Face *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->faceAppIDChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->faceKeyChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setFaceAppID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setFaceKey((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: { QString _r = _t->faceAppID();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->faceKey();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->VerifyAirFaceOperaterKey();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->InitFaceEngine((*reinterpret_cast< AirFaceOperater::DetectedMode(*)>(_a[1])),(*reinterpret_cast< AirFaceOperater::OrientPriority(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->InitFaceEngine((*reinterpret_cast< AirFaceOperater::DetectedMode(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->InitFaceEngine();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { vector<AirFaceOperater::FaceRect> _r = _t->FaceDetection((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<AirFaceOperater::FaceRect>*>(_a[0]) = std::move(_r); }  break;
        case 11: { vector<AirFaceOperater::FaceRect> _r = _t->FaceDetection((*reinterpret_cast< Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<AirFaceOperater::FaceRect>*>(_a[0]) = std::move(_r); }  break;
        case 12: { vector<AirFaceOperater::FaceRect> _r = _t->FaceDetection((*reinterpret_cast< QImage(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<AirFaceOperater::FaceRect>*>(_a[0]) = std::move(_r); }  break;
        case 13: { float _r = _t->FaceComparison((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 14: { float _r = _t->FaceComparison((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 15: { float _r = _t->FaceComparison((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 16: { float _r = _t->FaceComparison((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 17: { float _r = _t->FaceComparison((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 18: { float _r = _t->FaceComparison((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 19: { vector<int> _r = _t->GetAges((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 20: { vector<int> _r = _t->GetAges((*reinterpret_cast< Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 21: { vector<int> _r = _t->GetAges((*reinterpret_cast< QImage(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 22: { vector<int> _r = _t->GetGender((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 23: { vector<int> _r = _t->GetGender((*reinterpret_cast< Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 24: { vector<int> _r = _t->GetGender((*reinterpret_cast< QImage(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 25: { vector<AirFaceOperater::FaceAngle> _r = _t->Get3DAngle((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<AirFaceOperater::FaceAngle>*>(_a[0]) = std::move(_r); }  break;
        case 26: { vector<AirFaceOperater::FaceAngle> _r = _t->Get3DAngle((*reinterpret_cast< Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<AirFaceOperater::FaceAngle>*>(_a[0]) = std::move(_r); }  break;
        case 27: { vector<AirFaceOperater::FaceAngle> _r = _t->Get3DAngle((*reinterpret_cast< QImage(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<AirFaceOperater::FaceAngle>*>(_a[0]) = std::move(_r); }  break;
        case 28: { QMap<QString,QString> _r = _t->GetFaceVersionInfo();
            if (_a[0]) *reinterpret_cast< QMap<QString,QString>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Face::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Face::faceAppIDChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Face::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Face::faceKeyChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Face *_t = static_cast<Face *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->faceAppID(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->faceKey(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Face *_t = static_cast<Face *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFaceAppID(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setFaceKey(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Face::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Face.data,
      qt_meta_data_Face,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Face::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Face::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Face.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Face::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 29;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Face::faceAppIDChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Face::faceKeyChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
