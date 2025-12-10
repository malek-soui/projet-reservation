@echo off
echo ====================================
echo  Lancement du programme
echo ====================================

REM Vérifier si l'exécutable existe
if not exist "build\gestion_reservations.exe" (
    echo L'exécutable n'existe pas. Compilation en cours...
    call compile.bat
    if %errorlevel% neq 0 exit /b 1
)

REM Se déplacer dans le dossier data pour l'exécution
cd data
echo Lancement du programme...
echo.
..\build\gestion_reservations.exe

echo.
echo Programme terminé.
cd ..
pause