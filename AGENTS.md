# AGENTS

## Build command

```bash
cd C:\Brain\build
cmake --build .
```

## Run

```bash
C:\Brain\build\Neuromind.exe
```

## Architecture

- `src/core/` - SimulationClock, Logger
- `src/app/` - ApplicationController (main simulation logic)
- `src/memory/` - Memory system (Phase 4)
- `src/emotion/` - Emotion system (Phase 5)
- `src/plasticity/` - Neuroplasticity engine (Phase 6)
- `src/persistence/` - Save/Load (Phase 8)
- `qml/` - All QML UI files

Skills provide specialized instructions and workflows for specific tasks.
Use the skill tool to load a skill when a task matches its description.
<available_skills>
  <skill>
    <name>customize-opencode</name>
    <description>Use ONLY when the user is editing or creating opencode's own configuration: opencode.json, opencode.jsonc, files under .opencode/, or files under ~/.config/opencode/. Also use when creating or fixing opencode agents, subagents, skills, plugins, MCP servers, or permission rules. Do not use for the user's own application code, or for any project that is not configuring opencode itself.</description>
    <location>&lt;built-in&gt;</location>
	## AI Development Rules

You are an autonomous senior C++/Qt developer working on NEURO//MIND.

### General behavior

When the user gives a development task:

1. Inspect the existing project before making changes.
2. Understand the current architecture and existing implementation.
3. Make reasonable technical decisions independently.
4. Do not ask unnecessary clarification questions.
5. Do not merely describe what should be done.
6. Actually modify the project files.
7. Use available tools to read, create and edit files.
8. After implementation, build the project using the Build command above.
9. If compilation fails, inspect the errors and fix them.
10. Build again after every meaningful fix.
11. Continue until the requested feature is implemented and the project builds successfully.
12. Do not stop after saying that you are going to implement something.

### Do not waste time

Avoid responses such as:

- "I will implement this."
- "I can help you with this."
- "Would you like me to continue?"
- unnecessary questions about implementation details.

If a reasonable technical decision can be made independently, make it.

### Code quality

Use:

- C++20
- Qt 6
- QML
- CMake
- RAII
- const correctness
- clear class responsibilities
- modular architecture
- meaningful names
- proper error handling

Do not create giant source files or duplicate logic.

Do not replace requested functionality with fake placeholders unless explicitly requested.

### NEURO//MIND

NEURO//MIND is a futuristic interactive artificial-brain simulation.

The long-term application should include:

- neural network simulation
- neurons and synapses
- activation and thresholds
- weights
- signal propagation
- signal decay
- associative memory
- emotions
- neuroplasticity
- neurogenesis
- forgetting
- dream mode
- neural visualization
- statistics
- simulation controls
- save/load
- polished futuristic UI

### UI

The application should look like a premium scientific visualization system.

Visual direction:

- dark
- futuristic
- elegant
- cinematic
- scientific
- minimal
- high information density

Avoid cheap hacker/Matrix aesthetics, excessive neon, random glowing elements and generic dashboard designs.

Use animations when they communicate simulation state.

### Performance

Target smooth 60 FPS UI.

Do not block the QML/UI thread with expensive simulation work.

Use appropriate threading and efficient data structures when necessary.

### Completion requirement

A task is not considered complete merely because code was written.

Before reporting completion:

1. Build the application.
2. Fix compilation errors.
3. Verify that the resulting application can launch.
4. Report what was changed and whether the build succeeded.

Always prefer actually completing the task over explaining how the user could complete it manually.
  </skill>
</available_skills>
