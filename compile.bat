@echo off
echo ====================================
echo  Compilation du projet Gestion Reservations
echo ====================================

REM Création des dossiers si ils n'existent pas
if not exist "build" mkdir build
if not exist "data" mkdir data
if not exist "output" mkdir output

echo Compilation en cours...
gcc -Wall -Wextra -std=c99 -Iinclude src/*.c -o build/gestion_reservations.exe

if %errorlevel%==0 (
    echo.
    echo ✓ Compilation réussie!
    echo L'exécutable est dans: build/gestion_reservations.exe
    echo.
    echo Pour lancer le programme:
    echo   cd data
    echo   ..\build\gestion_reservations.exe
    echo.
) else (
    echo.
    echo ✗ Erreur de compilation!
    echo Vérifiez le code source.
    echo.
)

pause