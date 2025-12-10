@echo off
if not exist "build" mkdir build
if not exist "data" mkdir data
if not exist "output" mkdir output

echo Compilation...
gcc -Wall -Wextra -std=c99 -Iinclude src/*.c -o build/gestion_reservations.exe

if %errorlevel%==0 (
    echo Compilation reussie!
) else (
    echo Erreur de compilation!
    pause
    exit /b 1
)