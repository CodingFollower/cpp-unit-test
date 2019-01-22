@echo off

"C:\Program Files\CMake\bin\cmake.exe" -S . -B build -G "Visual Studio 10 2010"
if %ERRORLEVEL% == 0 (
    echo "build success"
) else (
    echo "build failed"
)