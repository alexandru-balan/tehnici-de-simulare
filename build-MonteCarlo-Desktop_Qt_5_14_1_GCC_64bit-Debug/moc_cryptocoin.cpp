/****************************************************************************
** Meta object code from reading C++ file 'cryptocoin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../MonteCarlo/cryptocoin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cryptocoin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CryptoCoin_t {
    QByteArrayData data[14];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CryptoCoin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CryptoCoin_t qt_meta_stringdata_CryptoCoin = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CryptoCoin"
QT_MOC_LITERAL(1, 11, 11), // "nameChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 19), // "abbreviationChanged"
QT_MOC_LITERAL(4, 44, 19), // "value_in_usdChanged"
QT_MOC_LITERAL(5, 64, 15), // "mod_rateChanged"
QT_MOC_LITERAL(6, 80, 16), // "final_sumChanged"
QT_MOC_LITERAL(7, 97, 8), // "simulate"
QT_MOC_LITERAL(8, 106, 14), // "number_of_days"
QT_MOC_LITERAL(9, 121, 4), // "name"
QT_MOC_LITERAL(10, 126, 12), // "abbreviation"
QT_MOC_LITERAL(11, 139, 12), // "value_in_usd"
QT_MOC_LITERAL(12, 152, 8), // "mod_rate"
QT_MOC_LITERAL(13, 161, 9) // "final_sum"

    },
    "CryptoCoin\0nameChanged\0\0abbreviationChanged\0"
    "value_in_usdChanged\0mod_rateChanged\0"
    "final_sumChanged\0simulate\0number_of_days\0"
    "name\0abbreviation\0value_in_usd\0mod_rate\0"
    "final_sum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CryptoCoin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       5,   52, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    1,   49,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    8,

 // properties: name, type, flags
       9, QMetaType::QString, 0x00495103,
      10, QMetaType::QString, 0x00495103,
      11, QMetaType::Double, 0x00495103,
      12, QMetaType::Double, 0x00495103,
      13, QMetaType::Double, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void CryptoCoin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CryptoCoin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nameChanged(); break;
        case 1: _t->abbreviationChanged(); break;
        case 2: _t->value_in_usdChanged(); break;
        case 3: _t->mod_rateChanged(); break;
        case 4: _t->final_sumChanged(); break;
        case 5: _t->simulate((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CryptoCoin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CryptoCoin::nameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CryptoCoin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CryptoCoin::abbreviationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CryptoCoin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CryptoCoin::value_in_usdChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CryptoCoin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CryptoCoin::mod_rateChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CryptoCoin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CryptoCoin::final_sumChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CryptoCoin *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->abbreviation(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->value_in_usd(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->mod_rate(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->final_sum(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CryptoCoin *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setAbbreviation(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setValue_in_usd(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setMod_rate(*reinterpret_cast< double*>(_v)); break;
        case 4: _t->setFinal_sum(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CryptoCoin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CryptoCoin.data,
    qt_meta_data_CryptoCoin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CryptoCoin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CryptoCoin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CryptoCoin.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CryptoCoin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CryptoCoin::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CryptoCoin::abbreviationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CryptoCoin::value_in_usdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CryptoCoin::mod_rateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CryptoCoin::final_sumChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
