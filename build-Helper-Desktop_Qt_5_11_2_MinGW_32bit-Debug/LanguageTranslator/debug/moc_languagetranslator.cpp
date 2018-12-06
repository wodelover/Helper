/****************************************************************************
** Meta object code from reading C++ file 'languagetranslator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Helper/LanguageTranslator/languagetranslator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'languagetranslator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LanguageTranslator_t {
    QByteArrayData data[27];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LanguageTranslator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LanguageTranslator_t qt_meta_stringdata_LanguageTranslator = {
    {
QT_MOC_LITERAL(0, 0, 18), // "LanguageTranslator"
QT_MOC_LITERAL(1, 19, 22), // "initLanguageTranslator"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 16), // "QGuiApplication&"
QT_MOC_LITERAL(4, 60, 3), // "app"
QT_MOC_LITERAL(5, 64, 22), // "QQmlApplicationEngine&"
QT_MOC_LITERAL(6, 87, 6), // "engine"
QT_MOC_LITERAL(7, 94, 11), // "setLanguage"
QT_MOC_LITERAL(8, 106, 32), // "LanguageTranslator::LanguageType"
QT_MOC_LITERAL(9, 139, 12), // "languageType"
QT_MOC_LITERAL(10, 152, 10), // "getAppPath"
QT_MOC_LITERAL(11, 163, 12), // "LanguageType"
QT_MOC_LITERAL(12, 176, 5), // "ZH_CN"
QT_MOC_LITERAL(13, 182, 5), // "ZH_HK"
QT_MOC_LITERAL(14, 188, 5), // "EN_US"
QT_MOC_LITERAL(15, 194, 5), // "AR_AE"
QT_MOC_LITERAL(16, 200, 5), // "AR_EG"
QT_MOC_LITERAL(17, 206, 5), // "BE_BY"
QT_MOC_LITERAL(18, 212, 5), // "DA_DK"
QT_MOC_LITERAL(19, 218, 5), // "DE_AT"
QT_MOC_LITERAL(20, 224, 5), // "DE_DE"
QT_MOC_LITERAL(21, 230, 5), // "ES_ES"
QT_MOC_LITERAL(22, 236, 5), // "FR_FR"
QT_MOC_LITERAL(23, 242, 5), // "IT_IT"
QT_MOC_LITERAL(24, 248, 5), // "JA_JA"
QT_MOC_LITERAL(25, 254, 5), // "TH_TH"
QT_MOC_LITERAL(26, 260, 5) // "UK_UA"

    },
    "LanguageTranslator\0initLanguageTranslator\0"
    "\0QGuiApplication&\0app\0QQmlApplicationEngine&\0"
    "engine\0setLanguage\0LanguageTranslator::LanguageType\0"
    "languageType\0getAppPath\0LanguageType\0"
    "ZH_CN\0ZH_HK\0EN_US\0AR_AE\0AR_EG\0BE_BY\0"
    "DA_DK\0DE_AT\0DE_DE\0ES_ES\0FR_FR\0IT_IT\0"
    "JA_JA\0TH_TH\0UK_UA"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LanguageTranslator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       1,   38, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x02 /* Public */,
       7,    1,   34,    2, 0x02 /* Public */,
      10,    0,   37,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::QString,

 // enums: name, flags, count, data
      11, 0x0,   15,   42,

 // enum data: key, value
      12, uint(LanguageTranslator::ZH_CN),
      13, uint(LanguageTranslator::ZH_HK),
      14, uint(LanguageTranslator::EN_US),
      15, uint(LanguageTranslator::AR_AE),
      16, uint(LanguageTranslator::AR_EG),
      17, uint(LanguageTranslator::BE_BY),
      18, uint(LanguageTranslator::DA_DK),
      19, uint(LanguageTranslator::DE_AT),
      20, uint(LanguageTranslator::DE_DE),
      21, uint(LanguageTranslator::ES_ES),
      22, uint(LanguageTranslator::FR_FR),
      23, uint(LanguageTranslator::IT_IT),
      24, uint(LanguageTranslator::JA_JA),
      25, uint(LanguageTranslator::TH_TH),
      26, uint(LanguageTranslator::UK_UA),

       0        // eod
};

void LanguageTranslator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LanguageTranslator *_t = static_cast<LanguageTranslator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initLanguageTranslator((*reinterpret_cast< QGuiApplication(*)>(_a[1])),(*reinterpret_cast< QQmlApplicationEngine(*)>(_a[2]))); break;
        case 1: _t->setLanguage((*reinterpret_cast< LanguageTranslator::LanguageType(*)>(_a[1]))); break;
        case 2: { QString _r = _t->getAppPath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LanguageTranslator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LanguageTranslator.data,
      qt_meta_data_LanguageTranslator,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LanguageTranslator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LanguageTranslator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LanguageTranslator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int LanguageTranslator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
