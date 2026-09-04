/****************************************************************************
** Meta object code from reading C++ file 'SimulationClock.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/core/SimulationClock.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SimulationClock.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSimulationClockENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSimulationClockENDCLASS = QtMocHelpers::stringData(
    "SimulationClock",
    "QML.Element",
    "auto",
    "speedChanged",
    "",
    "elapsedChanged",
    "runningChanged",
    "tickCountChanged",
    "tick",
    "onTimer",
    "start",
    "stop",
    "toggle",
    "reset",
    "speed",
    "elapsed",
    "running",
    "tickCount"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSimulationClockENDCLASS_t {
    uint offsetsAndSizes[36];
    char stringdata0[16];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[13];
    char stringdata4[1];
    char stringdata5[15];
    char stringdata6[15];
    char stringdata7[17];
    char stringdata8[5];
    char stringdata9[8];
    char stringdata10[6];
    char stringdata11[5];
    char stringdata12[7];
    char stringdata13[6];
    char stringdata14[6];
    char stringdata15[8];
    char stringdata16[8];
    char stringdata17[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSimulationClockENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSimulationClockENDCLASS_t qt_meta_stringdata_CLASSSimulationClockENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "SimulationClock"
        QT_MOC_LITERAL(16, 11),  // "QML.Element"
        QT_MOC_LITERAL(28, 4),  // "auto"
        QT_MOC_LITERAL(33, 12),  // "speedChanged"
        QT_MOC_LITERAL(46, 0),  // ""
        QT_MOC_LITERAL(47, 14),  // "elapsedChanged"
        QT_MOC_LITERAL(62, 14),  // "runningChanged"
        QT_MOC_LITERAL(77, 16),  // "tickCountChanged"
        QT_MOC_LITERAL(94, 4),  // "tick"
        QT_MOC_LITERAL(99, 7),  // "onTimer"
        QT_MOC_LITERAL(107, 5),  // "start"
        QT_MOC_LITERAL(113, 4),  // "stop"
        QT_MOC_LITERAL(118, 6),  // "toggle"
        QT_MOC_LITERAL(125, 5),  // "reset"
        QT_MOC_LITERAL(131, 5),  // "speed"
        QT_MOC_LITERAL(137, 7),  // "elapsed"
        QT_MOC_LITERAL(145, 7),  // "running"
        QT_MOC_LITERAL(153, 9)   // "tickCount"
    },
    "SimulationClock",
    "QML.Element",
    "auto",
    "speedChanged",
    "",
    "elapsedChanged",
    "runningChanged",
    "tickCountChanged",
    "tick",
    "onTimer",
    "start",
    "stop",
    "toggle",
    "reset",
    "speed",
    "elapsed",
    "running",
    "tickCount"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSimulationClockENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
      10,   16, // methods
       4,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   76,    4, 0x06,    5 /* Public */,
       5,    0,   77,    4, 0x06,    6 /* Public */,
       6,    0,   78,    4, 0x06,    7 /* Public */,
       7,    0,   79,    4, 0x06,    8 /* Public */,
       8,    0,   80,    4, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   81,    4, 0x08,   10 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,   82,    4, 0x02,   11 /* Public */,
      11,    0,   83,    4, 0x02,   12 /* Public */,
      12,    0,   84,    4, 0x02,   13 /* Public */,
      13,    0,   85,    4, 0x02,   14 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      14, QMetaType::Double, 0x00015103, uint(0), 0,
      15, QMetaType::Double, 0x00015001, uint(1), 0,
      16, QMetaType::Bool, 0x00015001, uint(2), 0,
      17, QMetaType::Int, 0x00015001, uint(3), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject SimulationClock::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSimulationClockENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSimulationClockENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'speed'
        double,
        // property 'elapsed'
        double,
        // property 'running'
        bool,
        // property 'tickCount'
        int,
        // Q_OBJECT / Q_GADGET
        SimulationClock,
        // method 'speedChanged'
        void,
        // method 'elapsedChanged'
        void,
        // method 'runningChanged'
        void,
        // method 'tickCountChanged'
        void,
        // method 'tick'
        void,
        // method 'onTimer'
        void,
        // method 'start'
        void,
        // method 'stop'
        void,
        // method 'toggle'
        void,
        // method 'reset'
        void
    >,
    nullptr
} };

void SimulationClock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SimulationClock *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->speedChanged(); break;
        case 1: _t->elapsedChanged(); break;
        case 2: _t->runningChanged(); break;
        case 3: _t->tickCountChanged(); break;
        case 4: _t->tick(); break;
        case 5: _t->onTimer(); break;
        case 6: _t->start(); break;
        case 7: _t->stop(); break;
        case 8: _t->toggle(); break;
        case 9: _t->reset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SimulationClock::*)();
            if (_t _q_method = &SimulationClock::speedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SimulationClock::*)();
            if (_t _q_method = &SimulationClock::elapsedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SimulationClock::*)();
            if (_t _q_method = &SimulationClock::runningChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SimulationClock::*)();
            if (_t _q_method = &SimulationClock::tickCountChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SimulationClock::*)();
            if (_t _q_method = &SimulationClock::tick; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SimulationClock *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< double*>(_v) = _t->speed(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->elapsed(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isRunning(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->tickCount(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SimulationClock *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSpeed(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *SimulationClock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimulationClock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSimulationClockENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SimulationClock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SimulationClock::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SimulationClock::elapsedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SimulationClock::runningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SimulationClock::tickCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SimulationClock::tick()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
