include "deps/Dependencies.lua"

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

workspace "Lila"
    linkgroups "On"
    warnings "Off"

    architecture "x64"
    startproject "Testbed"

    configurations { "Debug", "Release" }
    
group "Dependencies"
    include "deps/glad"
    include "deps/glfw"
group ""

group "Lila"
    include "Lila/build.lua"
    include "testbed/build.lua"
group ""