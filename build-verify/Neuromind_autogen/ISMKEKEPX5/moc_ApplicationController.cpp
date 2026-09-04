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
    "QML.Element",
    "auto",
    "QML.Singleton",
    "true",
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
    uint offsetsAndSizes[128];
    char stringdata0[22];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[14];
    char stringdata4[5];
    char stringdata5[14];
    char stringdata6[1];
    char stringdata7[17];
    char stringdata8[23];
    char stringdata9[13];
    char stringdata10[15];
    char stringdata11[16];
    char stringdata12[16];
    char stringdata13[16];
    char stringdata14[22];
    char stringdata15[14];
    char stringdata16[16];
    char stringdata17[9];
    char stringdata18[11];
    char stringdata19[21];
    char stringdata20[9];
    char stringdata21[5];
    char stringdata22[14];
    char stringdata23[8];
    char stringdata24[17];
    char stringdata25[11];
    char stringdata26[18];
    char stringdata27[13];
    char stringdata28[15];
    char stringdata29[16];
    char stringdata30[7];
    char stringdata31[16];
    char stringdata32[13];
    char stringdata33[12];
    char stringdata34[15];
    char stringdata35[13];
    char stringdata36[13];
    char stringdata37[8];
    char stringdata38[17];
    char stringdata39[15];
    char stringdata40[14];
    char stringdata41[16];
    char stringdata42[10];
    char stringdata43[5];
    char stringdata44[10];
    char stringdata45[6];
    char stringdata46[17];
    char stringdata47[7];
    char stringdata48[8];
    char stringdata49[9];
    char stringdata50[12];
    char stringdata51[16];
    char stringdata52[12];
    char stringdata53[13];
    char stringdata54[18];
    char stringdata55[16];
    char stringdata56[8];
    char stringdata57[9];
    char stringdata58[9];
    char stringdata59[9];
    char stringdata60[17];
    char stringdata61[12];
    char stringdata62[17];
    char stringdata63[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSApplicationControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSApplicationControllerENDCLASS_t qt_meta_stringdata_CLASSApplicationControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "ApplicationController"
        QT_MOC_LITERAL(22, 11),  // "QML.Element"
        QT_MOC_LITERAL(34, 4),  // "auto"
        QT_MOC_LITERAL(39, 13),  // "QML.Singleton"
        QT_MOC_LITERAL(53, 4),  // "true"
        QT_MOC_LITERAL(58, 13),  // "onlineChanged"
        QT_MOC_LITERAL(72, 0),  // ""
        QT_MOC_LITERAL(73, 16),  // "dreamModeChanged"
        QT_MOC_LITERAL(90, 22),  // "simulationSpeedChanged"
        QT_MOC_LITERAL(113, 12),  // "statsChanged"
        QT_MOC_LITERAL(126, 14),  // "neuronsChanged"
        QT_MOC_LITERAL(141, 15),  // "synapsesChanged"
        QT_MOC_LITERAL(157, 15),  // "emotionsChanged"
        QT_MOC_LITERAL(173, 15),  // "memoriesChanged"
        QT_MOC_LITERAL(189, 21),  // "selectedNeuronChanged"
        QT_MOC_LITERAL(211, 13),  // "pausedChanged"
        QT_MOC_LITERAL(225, 15),  // "neuronActivated"
        QT_MOC_LITERAL(241, 8),  // "neuronId"
        QT_MOC_LITERAL(250, 10),  // "activation"
        QT_MOC_LITERAL(261, 20),  // "dreamMemoryActivated"
        QT_MOC_LITERAL(282, 8),  // "memoryId"
        QT_MOC_LITERAL(291, 4),  // "name"
        QT_MOC_LITERAL(296, 13),  // "errorOccurred"
        QT_MOC_LITERAL(310, 7),  // "message"
        QT_MOC_LITERAL(318, 16),  // "onSimulationTick"
        QT_MOC_LITERAL(335, 10),  // "initialize"
        QT_MOC_LITERAL(346, 17),  // "createDemoNetwork"
        QT_MOC_LITERAL(364, 12),  // "selectNeuron"
        QT_MOC_LITERAL(377, 14),  // "deselectNeuron"
        QT_MOC_LITERAL(392, 15),  // "stimulateNeuron"
        QT_MOC_LITERAL(408, 6),  // "amount"
        QT_MOC_LITERAL(415, 15),  // "stimulateRandom"
        QT_MOC_LITERAL(431, 12),  // "createMemory"
        QT_MOC_LITERAL(444, 11),  // "description"
        QT_MOC_LITERAL(456, 14),  // "activateMemory"
        QT_MOC_LITERAL(471, 12),  // "deleteMemory"
        QT_MOC_LITERAL(484, 12),  // "renameMemory"
        QT_MOC_LITERAL(497, 7),  // "newName"
        QT_MOC_LITERAL(505, 16),  // "getMemoryDetails"
        QT_MOC_LITERAL(522, 14),  // "enterDreamMode"
        QT_MOC_LITERAL(537, 13),  // "exitDreamMode"
        QT_MOC_LITERAL(551, 15),  // "resetSimulation"
        QT_MOC_LITERAL(567, 9),  // "saveBrain"
        QT_MOC_LITERAL(577, 4),  // "path"
        QT_MOC_LITERAL(582, 9),  // "loadBrain"
        QT_MOC_LITERAL(592, 5),  // "clock"
        QT_MOC_LITERAL(598, 16),  // "SimulationClock*"
        QT_MOC_LITERAL(615, 6),  // "logger"
        QT_MOC_LITERAL(622, 7),  // "Logger*"
        QT_MOC_LITERAL(630, 8),  // "isOnline"
        QT_MOC_LITERAL(639, 11),  // "isDreamMode"
        QT_MOC_LITERAL(651, 15),  // "simulationSpeed"
        QT_MOC_LITERAL(667, 11),  // "neuronCount"
        QT_MOC_LITERAL(679, 12),  // "synapseCount"
        QT_MOC_LITERAL(692, 17),  // "activeNeuronCount"
        QT_MOC_LITERAL(710, 15),  // "networkActivity"
        QT_MOC_LITERAL(726, 7),  // "neurons"
        QT_MOC_LITERAL(734, 8),  // "synapses"
        QT_MOC_LITERAL(743, 8),  // "emotions"
        QT_MOC_LITERAL(752, 8),  // "memories"
        QT_MOC_LITERAL(761, 16),  // "selectedNeuronId"
        QT_MOC_LITERAL(778, 11),  // "memoryCount"
        QT_MOC_LITERAL(790, 16),  // "dreamMemoryCount"
        QT_MOC_LITERAL(807, 8)   // "isPaused"
    },
    "ApplicationController",
    "QML.Element",
    "auto",
    "QML.Singleton",
    "true",
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
       2,   14, // classinfo
      30,   18, // methods
      17,  264, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,  198,    6, 0x06,   18 /* Public */,
       7,    0,  199,    6, 0x06,   19 /* Public */,
       8,    0,  200,    6, 0x06,   20 /* Public */,
       9,    0,  201,    6, 0x06,   21 /* Public */,
      10,    0,  202,    6, 0x06,   22 /* Public */,
      11,    0,  203,    6, 0x06,   23 /* Public */,
      12,    0,  204,    6, 0x06,   24 /* Public */,
      13,    0,  205,    6, 0x06,   25 /* Public */,
      14,    0,  206,    6, 0x06,   26 /* Public */,
      15,    0,  207,    6, 0x06,   27 /* Public */,
      16,    2,  208,    6, 0x06,   28 /* Public */,
      19,    2,  213,    6, 0x06,   31 /* Public */,
      22,    1,  218,    6, 0x06,   34 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      24,    0,  221,    6, 0x08,   36 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      25,    0,  222,    6, 0x02,   37 /* Public */,
      26,    0,  223,    6, 0x02,   38 /* Public */,
      27,    1,  224,    6, 0x02,   39 /* Public */,
      28,    0,  227,    6, 0x02,   41 /* Public */,
      29,    2,  228,    6, 0x02,   42 /* Public */,
      31,    1,  233,    6, 0x02,   45 /* Public */,
      32,    2,  236,    6, 0x02,   47 /* Public */,
      34,    1,  241,    6, 0x02,   50 /* Public */,
      35,    1,  244,    6, 0x02,   52 /* Public */,
      36,    2,  247,    6, 0x02,   54 /* Public */,
      38,    1,  252,    6, 0x102,   57 /* Public | MethodIsConst  */,
      39,    0,  255,    6, 0x02,   59 /* Public */,
      40,    0,  256,    6, 0x02,   60 /* Public */,
      41,    0,  257,    6, 0x02,   61 /* Public */,
      42,    1,  258,    6, 0x02,   62 /* Public */,
      44,    1,  261,    6, 0x02,   64 /* Public */,

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
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   20,   21,
    QMetaType::Void, QMetaType::QString,   23,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   17,   30,
    QMetaType::Void, QMetaType::Double,   30,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   21,   33,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   20,   37,
    QMetaType::QVariantMap, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   43,
    QMetaType::Void, QMetaType::QString,   43,

 // properties: name, type, flags
      45, 0x80000000 | 46, 0x00015409, uint(-1), 0,
      47, 0x80000000 | 48, 0x00015409, uint(-1), 0,
      49, QMetaType::Bool, 0x00015001, uint(0), 0,
      50, QMetaType::Bool, 0x00015001, uint(1), 0,
      51, QMetaType::Double, 0x00015103, uint(2), 0,
      52, QMetaType::Int, 0x00015001, uint(3), 0,
      53, QMetaType::Int, 0x00015001, uint(3), 0,
      54, QMetaType::Int, 0x00015001, uint(3), 0,
      55, QMetaType::Double, 0x00015001, uint(3), 0,
      56, QMetaType::QVariantList, 0x00015001, uint(4), 0,
      57, QMetaType::QVariantList, 0x00015001, uint(5), 0,
      58, QMetaType::QVariantList, 0x00015001, uint(6), 0,
      59, QMetaType::QVariantList, 0x00015001, uint(7), 0,
      60, QMetaType::Int, 0x00015001, uint(8), 0,
      61, QMetaType::Int, 0x00015001, uint(7), 0,
      62, QMetaType::Int, 0x00015001, uint(1), 0,
      63, QMetaType::Bool, 0x00015001, uint(9), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject ApplicationController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSApplicationControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSApplicationControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'clock'
        SimulationClock*,
        // property 'logger'
        Logger*,
        // property 'isOnline'
        bool,
        // property 'isDreamMode'
        bool,
        // property 'simulationSpeed'
        double,
        // property 'neuronCount'
        int,
        // property 'synapseCount'
        int,
        // property 'activeNeuronCount'
        int,
        // property 'networkActivity'
        double,
        // property 'neurons'
        QVariantList,
        // property 'synapses'
        QVariantList,
        // property 'emotions'
        QVariantList,
        // property 'memories'
        QVariantList,
        // property 'selectedNeuronId'
        int,
        // property 'memoryCount'
        int,
        // property 'dreamMemoryCount'
        int,
        // property 'isPaused'
        bool,
        // Q_OBJECT / Q_GADGET
        ApplicationController,
        // method 'onlineChanged'
        void,
        // method 'dreamModeChanged'
        void,
        // method 'simulationSpeedChanged'
        void,
        // method 'statsChanged'
        void,
        // method 'neuronsChanged'
        void,
        // method 'synapsesChanged'
        void,
        // method 'emotionsChanged'
        void,
        // method 'memoriesChanged'
        void,
        // method 'selectedNeuronChanged'
        void,
        // method 'pausedChanged'
        void,
        // method 'neuronActivated'
        void,
        int,
        double,
        // method 'dreamMemoryActivated'
        void,
        int,
        const QString &,
        // method 'errorOccurred'
        void,
        const QString &,
        // method 'onSimulationTick'
        void,
        // method 'initialize'
        void,
        // method 'createDemoNetwork'
        void,
        // method 'selectNeuron'
        void,
        int,
        // method 'deselectNeuron'
        void,
        // method 'stimulateNeuron'
        void,
        int,
        double,
        // method 'stimulateRandom'
        void,
        double,
        // method 'createMemory'
        void,
        const QString &,
        const QString &,
        // method 'activateMemory'
        void,
        int,
        // method 'deleteMemory'
        void,
        int,
        // method 'renameMemory'
        void,
        int,
        const QString &,
        // method 'getMemoryDetails'
        QVariantMap,
        int,
        // method 'enterDreamMode'
        void,
        // method 'exitDreamMode'
        void,
        // method 'resetSimulation'
        void,
        // method 'saveBrain'
        void,
        const QString &,
        // method 'loadBrain'
        void,
        const QString &
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
