/****************************************************************************
** Meta object code from reading C++ file 'NeuralNetworkItem.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/visualization/NeuralNetworkItem.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NeuralNetworkItem.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSNeuralNetworkItemENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSNeuralNetworkItemENDCLASS = QtMocHelpers::stringData(
    "NeuralNetworkItem",
    "QML.Element",
    "auto",
    "neuronsChanged",
    "",
    "synapsesChanged",
    "viewChanged",
    "selectionChanged",
    "neuronAt",
    "x",
    "y",
    "neurons",
    "synapses",
    "zoom",
    "offsetX",
    "offsetY",
    "selectedNeuronId",
    "hoveredNeuronId"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSNeuralNetworkItemENDCLASS_t {
    uint offsetsAndSizes[36];
    char stringdata0[18];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[15];
    char stringdata4[1];
    char stringdata5[16];
    char stringdata6[12];
    char stringdata7[17];
    char stringdata8[9];
    char stringdata9[2];
    char stringdata10[2];
    char stringdata11[8];
    char stringdata12[9];
    char stringdata13[5];
    char stringdata14[8];
    char stringdata15[8];
    char stringdata16[17];
    char stringdata17[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSNeuralNetworkItemENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSNeuralNetworkItemENDCLASS_t qt_meta_stringdata_CLASSNeuralNetworkItemENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17),  // "NeuralNetworkItem"
        QT_MOC_LITERAL(18, 11),  // "QML.Element"
        QT_MOC_LITERAL(30, 4),  // "auto"
        QT_MOC_LITERAL(35, 14),  // "neuronsChanged"
        QT_MOC_LITERAL(50, 0),  // ""
        QT_MOC_LITERAL(51, 15),  // "synapsesChanged"
        QT_MOC_LITERAL(67, 11),  // "viewChanged"
        QT_MOC_LITERAL(79, 16),  // "selectionChanged"
        QT_MOC_LITERAL(96, 8),  // "neuronAt"
        QT_MOC_LITERAL(105, 1),  // "x"
        QT_MOC_LITERAL(107, 1),  // "y"
        QT_MOC_LITERAL(109, 7),  // "neurons"
        QT_MOC_LITERAL(117, 8),  // "synapses"
        QT_MOC_LITERAL(126, 4),  // "zoom"
        QT_MOC_LITERAL(131, 7),  // "offsetX"
        QT_MOC_LITERAL(139, 7),  // "offsetY"
        QT_MOC_LITERAL(147, 16),  // "selectedNeuronId"
        QT_MOC_LITERAL(164, 15)   // "hoveredNeuronId"
    },
    "NeuralNetworkItem",
    "QML.Element",
    "auto",
    "neuronsChanged",
    "",
    "synapsesChanged",
    "viewChanged",
    "selectionChanged",
    "neuronAt",
    "x",
    "y",
    "neurons",
    "synapses",
    "zoom",
    "offsetX",
    "offsetY",
    "selectedNeuronId",
    "hoveredNeuronId"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSNeuralNetworkItemENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
       5,   16, // methods
       7,   55, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   46,    4, 0x06,    8 /* Public */,
       5,    0,   47,    4, 0x06,    9 /* Public */,
       6,    0,   48,    4, 0x06,   10 /* Public */,
       7,    0,   49,    4, 0x06,   11 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,   50,    4, 0x102,   12 /* Public | MethodIsConst  */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int, QMetaType::QReal, QMetaType::QReal,    9,   10,

 // properties: name, type, flags
      11, QMetaType::QVariantList, 0x00015103, uint(0), 0,
      12, QMetaType::QVariantList, 0x00015103, uint(1), 0,
      13, QMetaType::QReal, 0x00015103, uint(2), 0,
      14, QMetaType::QReal, 0x00015103, uint(2), 0,
      15, QMetaType::QReal, 0x00015103, uint(2), 0,
      16, QMetaType::Int, 0x00015103, uint(3), 0,
      17, QMetaType::Int, 0x00015103, uint(3), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject NeuralNetworkItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_CLASSNeuralNetworkItemENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSNeuralNetworkItemENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'neurons'
        QVariantList,
        // property 'synapses'
        QVariantList,
        // property 'zoom'
        qreal,
        // property 'offsetX'
        qreal,
        // property 'offsetY'
        qreal,
        // property 'selectedNeuronId'
        int,
        // property 'hoveredNeuronId'
        int,
        // Q_OBJECT / Q_GADGET
        NeuralNetworkItem,
        // method 'neuronsChanged'
        void,
        // method 'synapsesChanged'
        void,
        // method 'viewChanged'
        void,
        // method 'selectionChanged'
        void,
        // method 'neuronAt'
        int,
        qreal,
        qreal
    >,
    nullptr
} };

void NeuralNetworkItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NeuralNetworkItem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->neuronsChanged(); break;
        case 1: _t->synapsesChanged(); break;
        case 2: _t->viewChanged(); break;
        case 3: _t->selectionChanged(); break;
        case 4: { int _r = _t->neuronAt((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NeuralNetworkItem::*)();
            if (_t _q_method = &NeuralNetworkItem::neuronsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NeuralNetworkItem::*)();
            if (_t _q_method = &NeuralNetworkItem::synapsesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NeuralNetworkItem::*)();
            if (_t _q_method = &NeuralNetworkItem::viewChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NeuralNetworkItem::*)();
            if (_t _q_method = &NeuralNetworkItem::selectionChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<NeuralNetworkItem *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantList*>(_v) = _t->neurons(); break;
        case 1: *reinterpret_cast< QVariantList*>(_v) = _t->synapses(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = _t->zoom(); break;
        case 3: *reinterpret_cast< qreal*>(_v) = _t->offsetX(); break;
        case 4: *reinterpret_cast< qreal*>(_v) = _t->offsetY(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->selectedNeuronId(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->hoveredNeuronId(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<NeuralNetworkItem *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setNeurons(*reinterpret_cast< QVariantList*>(_v)); break;
        case 1: _t->setSynapses(*reinterpret_cast< QVariantList*>(_v)); break;
        case 2: _t->setZoom(*reinterpret_cast< qreal*>(_v)); break;
        case 3: _t->setOffsetX(*reinterpret_cast< qreal*>(_v)); break;
        case 4: _t->setOffsetY(*reinterpret_cast< qreal*>(_v)); break;
        case 5: _t->setSelectedNeuronId(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setHoveredNeuronId(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *NeuralNetworkItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NeuralNetworkItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSNeuralNetworkItemENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int NeuralNetworkItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void NeuralNetworkItem::neuronsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void NeuralNetworkItem::synapsesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void NeuralNetworkItem::viewChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void NeuralNetworkItem::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
