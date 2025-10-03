@echo off
echo     __    ______    ___       ____  __  ________    ____
echo    / /   /  _/ /   /   ^|     / __ )/ / / /  _/ /   / __ \
echo   / /    / // /   / /^| ^|    / __  / / / // // /   / / / /
echo  / /____/ // /___/ ___ ^|   / /_/ / /_/ // // /___/ /_/ /
echo /_____/___/_____/_/  ^|_^|  /_____/\____/___/_____/_____/
echo.

if not exist Lila (
    echo You must run the script from the root folder!
    EXIT /B 1
)

cd Lila
if not exist src (
    cd ../
    echo You must run the script from the root folder!
    EXIT /B 1
)
cd ../

set BUILD_DIR="BuildWindows"

cmake -S . -B %BUILD_DIR%

echo ========================
echo Lila setup finished!

cd %BUILD_DIR%

@echo on

msbuild /m LilaEngine.sln

@echo off

echo ========================
echo Lila build finished!

"./Debug/LilaEngine.exe"

cd ..

echo ========================
echo Lila succesfully ran!
