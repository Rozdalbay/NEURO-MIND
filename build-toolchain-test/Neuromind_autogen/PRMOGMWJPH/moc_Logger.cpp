/****************************************************************************
** Meta object code from reading C++ file 'Logger.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/core/Logger.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Logger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSLoggerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSLoggerENDCLASS = QtMocHelpers::stringData(
    "Logger",
    "QML.Element",
    "auto",
    "logTextChanged",
    "",
    "log",
    "message",
    "Level",
    "level",
    "clear",
    "logText",
    "logCount",
    "Debug",
    "Info",
    "Warning",
    "Error"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSLoggerENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[7];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[15];
    char stringdata4[1];
    char stringdata5[4];
    char stringdata6[8];
    char stringdata7[6];
    char stringdata8[6];
    char stringdata9[6];
    char stringdata10[8];
    char stringdata11[9];
    char stringdata12[6];
    char stringdata13[5];
    char stringdata14[8];
    char stringdata15[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSLoggerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSLoggerENDCLASS_t qt_meta_stringdata_CLASSLoggerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Logger"
        QT_MOC_LITERAL(7, 11),  // "QML.Element"
        QT_MOC_LITERAL(19, 4),  // "auto"
        QT_MOC_LITERAL(24, 14),  // "logTextChanged"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 3),  // "log"
        QT_MOC_LITERAL(44, 7),  // "message"
        QT_MOC_LITERAL(52, 5),  // "Level"
        QT_MOC_LITERAL(58, 5),  // "level"
        QT_MOC_LITERAL(64, 5),  // "clear"
        QT_MOC_LITERAL(70, 7),  // "logText"
        QT_MOC_LITERAL(78, 8),  // "logCount"
        QT_MOC_LITERAL(87, 5),  // "Debug"
        QT_MOC_LITERAL(93, 4),  // "Info"
        QT_MOC_LITERAL(98, 7),  // "Warning"
        QT_MOC_LITERAL(106, 5)   // "Error"
    },
    "Logger",
    "QML.Element",
    "auto",
    "logTextChanged",
    "",
    "log",
    "message",
    "Level",
    "level",
    "clear",
    "logText",
    "logCount",
    "Debug",
    "Info",
    "Warning",
    "Error"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSLoggerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
       4,   16, // methods
       2,   50, // properties
       1,   60, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   40,    4, 0x06,    4 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       5,    2,   41,    4, 0x02,    5 /* Public */,
       5,    1,   46,    4, 0x22,    8 /* Public | MethodCloned */,
       9,    0,   49,    4, 0x02,   10 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    6,    8,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::QString, 0x00015001, uint(0), 0,
      11, QMetaType::Int, 0x00015001, uint(0), 0,

 // enums: name, alias, flags, count, data
       7,    7, 0x2,    4,   65,

 // enum data: key, value
      12, uint(Logger::Level::Debug),
      13, uint(Logger::Level::Info),
      14, uint(Logger::Level::Warning),
      15, uint(Logger::Level::Error),

       0        // eod
};

Q_CONSTINIT const QMetaObject Logger::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSLoggerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSLoggerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'logText'
        QString,
        // property 'logCount'
        int,
        // enum 'Level'
        Logger::Level,
        // Q_OBJECT / Q_GADGET
        Logger,
        // method 'logTextChanged'
        void,
        // method 'log'
        void,
        const QString &,
        Level,
        // method 'log'
        void,
        const QString &,
        // method 'clear'
        void
    >,
    nullptr
} };

void Logger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Logger *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->logTextChanged(); break;
        case 1: _t->log((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Level>>(_a[2]))); break;
        case 2: _t->log((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Logger::*)();
            if (_t _q_method = &Logger::logTextChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Logger *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->logText(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->logCount(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Logger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Logger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSLoggerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Logger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Logger::logTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
