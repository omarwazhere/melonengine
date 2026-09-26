# melonEngine

A silly hobby 'game engine', with another silly 'programming language'

> NOTE: the engine doesn't have any realeases till now.. as both the interpreter and the engine is in very early development. Not even pre alpha, its just a hobby small project made from home by a hobbyist :)

## Working on
- fixing issues
- adding functions to the interpreter
- cleaning the project
- adding features to the engine and melonscript

## Project Structure

```text
melonEngine/
├── .git/
├── .gitignore
├── .vscode/
├── build/
│   ├── build.exe
│   └── test.exe
├── build.ps1
├── buildtest.ps1
├── include/
│   ├── docs.hpp
│   ├── entity.hpp
│   ├── globals.hpp
│   ├── helpers.hpp
│   ├── melonscript/
│   │   ├── bytecode.hpp
│   │   ├── lexer.hpp
│   │   └── vm.hpp
│   ├── types.hpp
│   └── world.hpp
├── LICENSE
├── README.md
├── src/
│   ├── constructors.cpp
│   ├── entity.cpp
│   ├── helpers.cpp
│   ├── main.cpp
│   ├── melon/
│   │   └── melonlib.hpp
│   ├── melonscript/
│   │   ├── lexer.cpp
│   │   └── vm.cpp
│   └── world.cpp
├── test/
│   └── foo_test.cpp
└── ...
```

## Build

The project currently builds with GCC using:

```powershell
./build.ps1
```

Or manually:

```powershell
g++ -std=c++23 src/*.cpp -o build/build.exe
```

Or, if you want to test the engine directly using its C++ library:

```powershell
./buildtest.ps1
```

Or manually:

```powershell
$files = @(Get-ChildItem -Path "src/*.cpp" -Exclude "main.cpp").FullName
$files += (Get-Item "test/your_test.cpp").FullName
g++ -std=c++23 -Iinclude $files -o build/test.exe
```

## Contributing

Right now the project is still early and new, and I have ideas in mind where contributing may cause problems.

## License

This project is under the MIT license.

## Notes

- melonEngine is a personal, experimental C++ engine project. Huge changes are still coming, no promises, and the project should be a very small hobby project.

- No third-party sofware were used, although very early commits used sfml.

- Contributions are not very welcome -currently-

- All code you see is my own, you may use it of course, no need for credit (but I would appreciate it).

- This project is mostly just made for fun and learning, not for commerical use.