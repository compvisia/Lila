if [[ ! -d "Lila" ]]; then
    echo You must run the script in the root folder!
    exit 1
fi

cd Lila
if [[ ! -d "src" ]]; then
    cd ../
    echo You must run the script in the root folder!
    exit 1
fi
cd ../

BUILD_DIR="buildLinux"

cmake -S . -B $BUILD_DIR -D GLFW_BUILD_WAYLAND=OFF

echo ====================
echo Lila setup finished!

cd $BUILD_DIR

make

echo ====================
echo Lila build finished!

"./LilaEngine"