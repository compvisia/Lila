include "deps/Dependencies.lua"

newoption {
    trigger = "coverage",
    description = "Generates a coverage report using gcov"
}

newoption {
    trigger = "headless",
    description = "Turns all graphics related things off"
}

workspace "Lila"
    linkgroups "On"
    warnings "Off"

    architecture "x64"
    startproject "Testbed"

    configurations { "Debug", "Release" }
    
OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Dependencies"
    include "deps/glad"
    include "deps/glfw"
group ""

group "Lila engine"
    include "Lila/build.lua"
group ""

group "Testing"
    include "testbed/build.lua"
group ""