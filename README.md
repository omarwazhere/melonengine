# melonEngine

A lightweight C++ project focused on building a simple 2D world and entity system for experimentation, prototyping, and learning game-engine concepts.

> Warning: melonEngine is still in very early development. The codebase, APIs, architecture, and gameplay/simulation behavior are expected to change significantly as the project evolves. It is not yet stable, production-ready, or fully tested.

## Overview

melonEngine is a small engine-style prototype built around a few core ideas:

- A world container with size and render distance
- Entity objects with positions, symbols, and collision/state data
- Moving entities and static objects built from a shared base class
- Simple rendering of a world buffer to the terminal
- Basic simulation helpers for creating and managing entities

The project is useful as a learning project and a starting point for exploring:

- object-oriented design in C++
- entity/world systems
- render loops and camera-style viewport logic
- simple game architecture patterns
- early prototype iteration and testing

## Current Status

melonEngine is currently in an experimental and unstable phase.

This means:

- major refactors are expected
- APIs may change without notice
- engine behavior may be inconsistent
- features are still being designed, tested, and revised
- there may be bugs, rough edges, or incomplete systems

This project is best treated as a prototype and a learning sandbox rather than a finished engine.

### Helper utilities
- setup and world initialization
- entity spawning helpers
- world tick/update hooks
- solid-entity collision checks

## Project Structure

```text
melonEngine/
├── .gitignore
├── .vscode/
├── LICENSE
├── README.md
├── build/
├── build.ps1
├── buildtest.ps1
├── docs/
│   ├── help.txt
│   └── info.txt
├── include/
│   ├── entity.hpp
│   ├── globals.hpp
│   ├── helpers.hpp
│   ├── melonscript.hpp
│   ├── types.hpp
│   └── world.hpp
├── src/
│   ├── constructors.cpp
│   ├── entity.cpp
│   ├── helpers.cpp
│   ├── main.cpp
│   ├── melon/
│   │   └── melonlib.hpp
│   ├── melonscript/
│   └── world.cpp
├── test/
│   └── foo_test.cpp
└── ...
```

## Build

The project currently builds with GCC using the provided script:

```powershell
./build.ps1
```

Or manually:

```bash
g++ -std=c++23 src/*.cpp -o build/test.exe
```

## Testing and Stability

This project is still under active testing and experimentation. Expect the following:

- incomplete validation coverage
- possible runtime issues
- structural changes as the engine grows
- evolving internal APIs as features mature

Use it for learning, experimentation, and prototyping, but do not assume it is stable enough for production use or long-term compatibility.

## Contributing

Contributions are welcome in principle, but right now the project is still early and new, and I have ideas in mind where contributing may cause problems.

## License

This project is under the MIT license.

## Final Notes

- melonEngine is a personal, experimental C++ engine project in its infancy. It is a place to explore ideas, build fundamentals, and test prototypes. Huge changes are still coming, and the project should be considered early-stage software under active development and testing.

- No third-party sofware were used, although early commits used sfml.

- Contributions are not very welcome -currently-

- All code you see is my own, you may use it of course, but with credit.
- This project is mostly just made for fun and learning, not for commerical use.  