@echo off
if not exist "build" mkdir build
if not exist "data" mkdir data
if not exist "output" mkdir output

gcc -Wall -Wextra -std=c99 -Iinclude src/*.c -o build/gestion_reservations.exe >nul 2>&1

if %errorlevel%==0 (
    cd data
    ..\build\gestion_reservations.exe
    cd ..
) else (
    echo Erreur compilation
    pause
)