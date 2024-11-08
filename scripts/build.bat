@echo off

set BUILD_DIR="buildWin"

if not exist Lila (
    echo You must run the script in the root folder!
    EXIT /B -1
)

cd Lila
if not exist src (
    cd ../
    echo You must run the script in the root folder!
    EXIT /B -1
)
cd ../

cmake -S . -B %BUILD_DIR%

echo ====================
echo Lila setup finished!

cd %BUILD_DIR%

@echo on

msbuild /m LilaEngine.sln

@echo off
echo ====================
echo Lila build finished!

"./Debug/LilaEngine.exe"

cd ..