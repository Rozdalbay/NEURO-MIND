file(REMOVE_RECURSE
  "NeuroMind/qml/Main.qml"
  "NeuroMind/qml/MainWindow.qml"
  "NeuroMind/qml/StartupScreen.qml"
  "NeuroMind/qml/brain/BrainVisualization.qml"
  "NeuroMind/qml/components/AnimatedNumber.qml"
  "NeuroMind/qml/components/GlowPanel.qml"
  "NeuroMind/qml/components/NeonButton.qml"
  "NeuroMind/qml/components/StatusIndicator.qml"
  "NeuroMind/qml/dashboard/DashboardPanel.qml"
  "NeuroMind/qml/dream/DreamPanel.qml"
  "NeuroMind/qml/emotions/EmotionPanel.qml"
  "NeuroMind/qml/memory/MemoryPanel.qml"
  "NeuroMind/qml/settings/LogPanel.qml"
  "NeuroMind/qml/settings/SettingsPanel.qml"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/Neuromind_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
