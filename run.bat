@echo off
if not exist "build\gestion_reservations.exe" (
    call compile.bat
    if %errorlevel% neq 0 exit /b 1
)

cd data
..\build\gestion_reservations.exe
cd ..