cmake_minimum_required(VERSION 3.20)

project(Neuromind VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick QuickControls2 Core Gui)
qt_policy(SET QTP0001 NEW)

set(SOURCES
    src/main.cpp
    src/app/ApplicationController.cpp
    src/core/SimulationClock.cpp
    src/core/Logger.cpp
    src/visualization/NeuralNetworkItem.cpp
)

set(HEADERS
    src/app/ApplicationController.h
    src/core/SimulationClock.h
    src/core/Logger.h
    src/visualization/NeuralNetworkItem.h
)

qt_add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

qt_add_qml_module(${PROJECT_NAME}
    URI NeuroMind
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        qml/StartupScreen.qml
        qml/MainWindow.qml
        qml/components/GlowPanel.qml
        qml/components/NeonButton.qml
        qml/components/StatusIndicator.qml
        qml/components/AnimatedNumber.qml
        qml/dashboard/DashboardPanel.qml
        qml/brain/BrainVisualization.qml
        qml/memory/MemoryPanel.qml
        qml/emotions/EmotionPanel.qml
        qml/dream/DreamPanel.qml
        qml/settings/SettingsPanel.qml
        qml/settings/LogPanel.qml
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Core
    Qt6::Gui
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/app
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core
    ${CMAKE_CURRENT_SOURCE_DIR}/src/memory
    ${CMAKE_CURRENT_SOURCE_DIR}/src/emotion
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plasticity
    ${CMAKE_CURRENT_SOURCE_DIR}/src/persistence
    ${CMAKE_CURRENT_SOURCE_DIR}/src/visualization
)

if(MINGW)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
endif()
