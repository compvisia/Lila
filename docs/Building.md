# Building

## Windows

### Prerequisites

* Visual Studio 2022

### Building

Go inside the `scripts` folder and run the `build-vs2022.bat` file.<br>
Then open the Lila.sln file and build it using Visual Studio.<br>

### Running

You can just hit run in Visual Studio or alternatively go to `bin/windows-x86_64/Debug/Testbed` and run `Testbed.exe` using the terminal

## Linux

### Prerequisites

* make
* gcc/clang
* xorg-dev

### Building

Open up a terminal and navigate to the Lila directory.
Then run `chmod +x scripts/build-make.sh` to make the script runnable.<br>
After that run `bash scripts/build-make.sh`.<br>

### Running

And then just run `./bin/linux-x86_64/Debug/Testbed/Testbed`.

## General Knowledge

### When to run the script

After creating, deleting or renaming a file you must run the script again.