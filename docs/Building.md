# Building

## Windows

### Prerequisites

* Visual Studio 2022

### Building

#### Using Visual Studio

1. Navigate to the `scripts` folder and run the `build-vs2022.bat` file.
2. Open the `Lila.sln` file and build it using Visual Studio.

#### Using MSBuild

1. Navigate to the `scripts` folder and run the `build-msbuild.bat` file.

### Running

* Press the run button in Visual Studio.
* Or alternatively navigate to `bin/windows-x86_64/Debug/Testbed` and run `Testbed.exe`.

## Linux

### Prerequisites

* make
* gcc/clang
* xorg-dev

### Building

1. Open up a terminal and navigate to the Lila directory.
2. Execute the script by running `bash scripts/build-make.sh`.

### Running

Run the following command in the terminal:
```sh
./bin/linux-x86_64/Debug/Testbed/Testbed
```

## General Knowledge

### When to run the script

After each file you created, deleted, or renamed, unless you are using Visual Studio or a similar IDE.

After pulling most of the time you need to run it regardless of what IDE you use.