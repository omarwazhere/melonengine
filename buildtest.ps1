$files = @(Get-ChildItem -Path "src/*.cpp" -Exclude "main.cpp").FullName
$files += (Get-Item "test/foo_test.cpp").FullName
g++ -std=c++23 -Iinclude $files -o build/test.exe