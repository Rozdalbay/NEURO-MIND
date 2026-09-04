/****************************************************************************
** Meta object code from reading C++ file 'ApplicationController.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/app/ApplicationController.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ApplicationController.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSApplicationControllerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSApplicationControllerENDCLASS = QtMocHelpers::stringData(
    "ApplicationController",
    "onlineChanged",
    "",
    "dreamModeChanged",
    "simulationSpeedChanged",
    "statsChanged",
    "neuronsChanged",
    "synapsesChanged",
    "emotionsChanged",
    "memoriesChanged",
    "selectedNeuronChanged",
    "pausedChanged",
    "neuronActivated",
    "neuronId",
    "activation",
    "dreamMemoryActivated",
    "memoryId",
    "name",
    "errorOccurred",
    "message",
    "onSimulationTick",
    "initialize",
    "createDemoNetwork",
    "selectNeuron",
    "deselectNeuron",
    "stimulateNeuron",
    "amount",
    "stimulateRandom",
    "createMemory",
    "description",
    "activateMemory",
    "deleteMemory",
    "renameMemory",
    "newName",
    "getMemoryDetails",
    "enterDreamMode",
    "exitDreamMode",
    "resetSimulation",
    "saveBrain",
    "path",
    "loadBrain",
    "clock",
    "SimulationClock*",
    "logger",
    "Logger*",
    "isOnline",
    "isDreamMode",
    "simulationSpeed",
    "neuronCount",
    "synapseCount",
    "activeNeuronCount",
    "networkActivity",
    "neurons",
    "synapses",
    "emotions",
    "memories",
    "selectedNeuronId",
    "memoryCount",
    "dreamMemoryCount",
    "isPaused"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSApplicationControllerENDCLASS_t {
    uint offsetsAndSizes[120];
    char stringdata0[22];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[23];
    char stringdata5[13];
    char stringdata6[15];
    char stringdata7[16];
    char stringdata8[16];
    char stringdata9[16];
    char stringdata10[22];
    char stringdata11[14];
    char stringdata12[16];
    char stringdata13[9];
    char stringdata14[11];
    char stringdata15[21];
    char stringdata16[9];
    char stringdata17[5];
    char stringdata18[14];
    char stringdata19[8];
    char stringdata20[17];
    char stringdata21[11];
    char stringdata22[18];
    char stringdata23[13];
    char stringdata24[15];
    char stringdata25[16];
    char stringdata26[7];
    char stringdata27[16];
    char stringdata28[13];
    char stringdata29[12];
    char stringdata30[15];
    char stringdata31[13];
    char stringdata32[13];
    char stringdata33[8];
    char stringdata34[17];
    char stringdata35[15];
    char stringdata36[14];
    char stringdata37[16];
    char stringdata38[10];
    char stringdata39[5];
    char stringdata40[10];
    char stringdata41[6];
    char stringdata42[17];
    char stringdata43[7];
    char stringdata44[8];
    char stringdata45[9];
    char stringdata46[12];
    char stringdata47[16];
    char stringdata48[12];
    char stringdata49[13];
    char stringdata50[18];
    char stringdata51[16];
    char stringdata52[8];
    char stringdata53[9];
    char stringdata54[9];
    char stringdata55[9];
    char stringdata56[17];
    char stringdata57[12];
    char stringdata58[17];
    char stringdata59[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSApplicationControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSApplicationControllerENDCLASS_t qt_meta_stringdata_CLASSApplicationControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "ApplicationController"
        QT_MOC_LITERAL(22, 13),  // "onlineChanged"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 16),  // "dreamModeChanged"
        QT_MOC_LITERAL(54, 22),  // "simulationSpeedChanged"
        QT_MOC_LITERAL(77, 12),  // "statsChanged"
        QT_MOC_LITERAL(90, 14),  // "neuronsChanged"
        QT_MOC_LITERAL(105, 15),  // "synapsesChanged"
        QT_MOC_LITERAL(121, 15),  // "emotionsChanged"
        QT_MOC_LITERAL(137, 15),  // "memoriesChanged"
        QT_MOC_LITERAL(153, 21),  // "selectedNeuronChanged"
        QT_MOC_LITERAL(175, 13),  // "pausedChanged"
        QT_MOC_LITERAL(189, 15),  // "neuronActivated"
        QT_MOC_LITERAL(205, 8),  // "neuronId"
        QT_MOC_LITERAL(214, 10),  // "activation"
        QT_MOC_LITERAL(225, 20),  // "dreamMemoryActivated"
        QT_MOC_LITERAL(246, 8),  // "memoryId"
        QT_MOC_LITERAL(255, 4),  // "name"
        QT_MOC_LITERAL(260, 13),  // "errorOccurred"
        QT_MOC_LITERAL(274, 7),  // "message"
        QT_MOC_LITERAL(282, 16),  // "onSimulationTick"
        QT_MOC_LITERAL(299, 10),  // "initialize"
        QT_MOC_LITERAL(310, 17),  // "createDemoNetwork"
        QT_MOC_LITERAL(328, 12),  // "selectNeuron"
        QT_MOC_LITERAL(341, 14),  // "deselectNeuron"
        QT_MOC_LITERAL(356, 15),  // "stimulateNeuron"
        QT_MOC_LITERAL(372, 6),  // "amount"
        QT_MOC_LITERAL(379, 15),  // "stimulateRandom"
        QT_MOC_LITERAL(395, 12),  // "createMemory"
        QT_MOC_LITERAL(408, 11),  // "description"
        QT_MOC_LITERAL(420, 14),  // "activateMemory"
        QT_MOC_LITERAL(435, 12),  // "deleteMemory"
        QT_MOC_LITERAL(448, 12),  // "renameMemory"
        QT_MOC_LITERAL(461, 7),  // "newName"
        QT_MOC_LITERAL(469, 16),  // "getMemoryDetails"
        QT_MOC_LITERAL(486, 14),  // "enterDreamMode"
        QT_MOC_LITERAL(501, 13),  // "exitDreamMode"
        QT_MOC_LITERAL(515, 15),  // "resetSimulation"
        QT_MOC_LITERAL(531, 9),  // "saveBrain"
        QT_MOC_LITERAL(541, 4),  // "path"
        QT_MOC_LITERAL(546, 9),  // "loadBrain"
        QT_MOC_LITERAL(556, 5),  // "clock"
        QT_MOC_LITERAL(562, 16),  // "SimulationClock*"
        QT_MOC_LITERAL(579, 6),  // "logger"
        QT_MOC_LITERAL(586, 7),  // "Logger*"
        QT_MOC_LITERAL(594, 8),  // "isOnline"
        QT_MOC_LITERAL(603, 11),  // "isDreamMode"
        QT_MOC_LITERAL(615, 15),  // "simulationSpeed"
        QT_MOC_LITERAL(631, 11),  // "neuronCount"
        QT_MOC_LITERAL(643, 12),  // "synapseCount"
        QT_MOC_LITERAL(656, 17),  // "activeNeuronCount"
        QT_MOC_LITERAL(674, 15),  // "networkActivity"
        QT_MOC_LITERAL(690, 7),  // "neurons"
        QT_MOC_LITERAL(698, 8),  // "synapses"
        QT_MOC_LITERAL(707, 8),  // "emotions"
        QT_MOC_LITERAL(716, 8),  // "memories"
        QT_MOC_LITERAL(725, 16),  // "selectedNeuronId"
        QT_MOC_LITERAL(742, 11),  // "memoryCount"
        QT_MOC_LITERAL(754, 16),  // "dreamMemoryCount"
        QT_MOC_LITERAL(771, 8)   // "isPaused"
    },
    "ApplicationController",
    "onlineChanged",
    "",
    "dreamModeChanged",
    "simulationSpeedChanged",
    "statsChanged",
    "neuronsChanged",
    "synapsesChanged",
    "emotionsChanged",
    "memoriesChanged",
    "selectedNeuronChanged",
    "pausedChanged",
    "neuronActivated",
    "neuronId",
    "activation",
    "dreamMemoryActivated",
    "memoryId",
    "name",
    "errorOccurred",
    "message",
    "onSimulationTick",
    "initialize",
    "createDemoNetwork",
    "selectNeuron",
    "deselectNeuron",
    "stimulateNeuron",
    "amount",
    "stimulateRandom",
    "createMemory",
    "description",
    "activateMemory",
    "deleteMemory",
    "renameMemory",
    "newName",
    "getMemoryDetails",
    "enterDreamMode",
    "exitDreamMode",
    "resetSimulation",
    "saveBrain",
    "path",
    "loadBrain",
    "clock",
    "SimulationClock*",
    "logger",
    "Logger*",
    "isOnline",
    "isDreamMode",
    "simulationSpeed",
    "neuronCount",
    "synapseCount",
    "activeNeuronCount",
    "networkActivity",
    "neurons",
    "synapses",
    "emotions",
    "memories",
    "selectedNeuronId",
    "memoryCount",
    "dreamMemoryCount",
    "isPaused"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSApplicationControllerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
      17,  260, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  194,    2, 0x06,   18 /* Public */,
       3,    0,  195,    2, 0x06,   19 /* Public */,
       4,    0,  196,    2, 0x06,   20 /* Public */,
       5,    0,  197,    2, 0x06,   21 /* Public */,
       6,    0,  198,    2, 0x06,   22 /* Public */,
       7,    0,  199,    2, 0x06,   23 /* Public */,
       8,    0,  200,    2, 0x06,   24 /* Public */,
       9,    0,  201,    2, 0x06,   25 /* Public */,
      10,    0,  202,    2, 0x06,   26 /* Public */,
      11,    0,  203,    2, 0x06,   27 /* Public */,
      12,    2,  204,    2, 0x06,   28 /* Public */,
      15,    2,  209,    2, 0x06,   31 /* Public */,
      18,    1,  214,    2, 0x06,   34 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      20,    0,  217,    2, 0x08,   36 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      21,    0,  218,    2, 0x02,   37 /* Public */,
      22,    0,  219,    2, 0x02,   38 /* Public */,
      23,    1,  220,    2, 0x02,   39 /* Public */,
      24,    0,  223,    2, 0x02,   41 /* Public */,
      25,    2,  224,    2, 0x02,   42 /* Public */,
      27,    1,  229,    2, 0x02,   45 /* Public */,
      28,    2,  232,    2, 0x02,   47 /* Public */,
      30,    1,  237,    2, 0x02,   50 /* Public */,
      31,    1,  240,    2, 0x02,   52 /* Public */,
      32,    2,  243,    2, 0x02,   54 /* Public */,
      34,    1,  248,    2, 0x102,   57 /* Public | MethodIsConst  */,
      35,    0,  251,    2, 0x02,   59 /* Public */,
      36,    0,  252,    2, 0x02,   60 /* Public */,
      37,    0,  253,    2, 0x02,   61 /* Public */,
      38,    1,  254,    2, 0x02,   62 /* Public */,
      40,    1,  257,    2, 0x02,   64 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   16,   17,
    QMetaType::Void, QMetaType::QString,   19,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   13,   26,
    QMetaType::Void, QMetaType::Double,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   17,   29,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   16,   33,
    QMetaType::QVariantMap, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void, QMetaType::QString,   39,

 // properties: name, type, flags
      41, 0x80000000 | 42, 0x00015409, uint(-1), 0,
      43, 0x80000000 | 44, 0x00015409, uint(-1), 0,
      45, QMetaType::Bool, 0x00015001, uint(0), 0,
      46, QMetaType::Bool, 0x00015001, uint(1), 0,
      47, QMetaType::Double, 0x00015103, uint(2), 0,
      48, QMetaType::Int, 0x00015001, uint(3), 0,
      49, QMetaType::Int, 0x00015001, uint(3), 0,
      50, QMetaType::Int, 0x00015001, uint(3), 0,
      51, QMetaType::Double, 0x00015001, uint(3), 0,
      52, QMetaType::QVariantList, 0x00015001, uint(4), 0,
      53, QMetaType::QVariantList, 0x00015001, uint(5), 0,
      54, QMetaType::QVariantList, 0x00015001, uint(6), 0,
      55, QMetaType::QVariantList, 0x00015001, uint(7), 0,
      56, QMetaType::Int, 0x00015001, uint(8), 0,
      57, QMetaType::Int, 0x00015001, uint(7), 0,
      58, QMetaType::Int, 0x00015001, uint(1), 0,
      59, QMetaType::Bool, 0x00015001, uint(9), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject ApplicationController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSApplicationControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSApplicationControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSApplicationControllerENDCLASS_t,
        // property 'clock'
        QtPrivate::TypeAndForceComplete<SimulationClock*, std::true_type>,
        // property 'logger'
        QtPrivate::TypeAndForceComplete<Logger*, std::true_type>,
        // property 'isOnline'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'isDreamMode'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'simulationSpeed'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'neuronCount'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'synapseCount'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'activeNeuronCount'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'networkActivity'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'neurons'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'synapses'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'emotions'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'memories'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'selectedNeuronId'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'memoryCount'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'dreamMemoryCount'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'isPaused'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ApplicationController, std::true_type>,
        // method 'onlineChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dreamModeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'simulationSpeedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'statsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'neuronsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'synapsesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'emotionsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'memoriesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectedNeuronChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pausedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'neuronActivated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'dreamMemoryActivated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'errorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onSimulationTick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initialize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createDemoNetwork'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectNeuron'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'deselectNeuron'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stimulateNeuron'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'stimulateRandom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'createMemory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'activateMemory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'deleteMemory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'renameMemory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'getMemoryDetails'
        QtPrivate::TypeAndForceComplete<QVariantMap, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'enterDreamMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'exitDreamMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetSimulation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveBrain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'loadBrain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void ApplicationController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ApplicationController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onlineChanged(); break;
        case 1: _t->dreamModeChanged(); break;
        case 2: _t->simulationSpeedChanged(); break;
        case 3: _t->statsChanged(); break;
        case 4: _t->neuronsChanged(); break;
        case 5: _t->synapsesChanged(); break;
        case 6: _t->emotionsChanged(); break;
        case 7: _t->memoriesChanged(); break;
        case 8: _t->selectedNeuronChanged(); break;
        case 9: _t->pausedChanged(); break;
        case 10: _t->neuronActivated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 11: _t->dreamMemoryActivated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 12: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->onSimulationTick(); break;
        case 14: _t->initialize(); break;
        case 15: _t->createDemoNetwork(); break;
        case 16: _t->selectNeuron((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->deselectNeuron(); break;
        case 18: _t->stimulateNeuron((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 19: _t->stimulateRandom((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 20: _t->createMemory((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 21: _t->activateMemory((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->deleteMemory((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->renameMemory((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 24: { QVariantMap _r = _t->getMemoryDetails((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->enterDreamMode(); break;
        case 26: _t->exitDreamMode(); break;
        case 27: _t->resetSimulation(); break;
        case 28: _t->saveBrain((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->loadBrain((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ApplicationController::*)();
            if (_t _q_method = &ApplicationController::onlineChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ApplicationController::*)();
            if (_t _q_method = &ApplicationController::dreamModeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ApplicationController::*)();
            if (_t _q_method = &ApplicationController::simulationSpeedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ApplicationController::*)();
            if (_t _q_method = &ApplicationController::statsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ApplicationController::*)();
            if (_t _q_method = &ApplicationController::neuronsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ApplicationController::*)();
            if (_t _q_method = &ApplicationController::synapsesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ApplicationController::*)();
            if (_t _q_method = &ApplicationController::emotionsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ApplicationController::*)();
            if (_t _q_method = &ApplicationController::memoriesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ApplicationController::*)();
            if (_t _q_method = &ApplicationController::selectedNeuronChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ApplicationController::*)();
            if (_t _q_method = &ApplicationController::pausedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ApplicationController::*)(int , double );
            if (_t _q_method = &ApplicationController::neuronActivated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (ApplicationController::*)(int , const QString & );
            if (_t _q_method = &ApplicationController::dreamMemoryActivated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (ApplicationController::*)(const QString & );
            if (_t _q_method = &ApplicationController::errorOccurred; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Logger* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SimulationClock* >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ApplicationController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< SimulationClock**>(_v) = _t->clock(); break;
        case 1: *reinterpret_cast< Logger**>(_v) = _t->logger(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isOnline(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->isDreamMode(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->simulationSpeed(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->neuronCount(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->synapseCount(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->activeNeuronCount(); break;
        case 8: *reinterpret_cast< double*>(_v) = _t->networkActivity(); break;
        case 9: *reinterpret_cast< QVariantList*>(_v) = _t->neurons(); break;
        case 10: *reinterpret_cast< QVariantList*>(_v) = _t->synapses(); break;
        case 11: *reinterpret_cast< QVariantList*>(_v) = _t->emotions(); break;
        case 12: *reinterpret_cast< QVariantList*>(_v) = _t->memories(); break;
        case 13: *reinterpret_cast< int*>(_v) = _t->selectedNeuronId(); break;
        case 14: *reinterpret_cast< int*>(_v) = _t->memoryCount(); break;
        case 15: *reinterpret_cast< int*>(_v) = _t->dreamMemoryCount(); break;
        case 16: *reinterpret_cast< bool*>(_v) = _t->isPaused(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ApplicationController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 4: _t->setSimulationSpeed(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *ApplicationController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApplicationController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSApplicationControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ApplicationController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 30;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void ApplicationController::onlineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ApplicationController::dreamModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ApplicationController::simulationSpeedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ApplicationController::statsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ApplicationController::neuronsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ApplicationController::synapsesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ApplicationController::emotionsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ApplicationController::memoriesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void ApplicationController::selectedNeuronChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void ApplicationController::pausedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void ApplicationController::neuronActivated(int _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void ApplicationController::dreamMemoryActivated(int _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ApplicationController::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_WARNING_POP
