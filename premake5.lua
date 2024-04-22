include "deps/Dependencies.lua"

workspace "Lila Project"
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
    include "testbed/build.lua"
group ""