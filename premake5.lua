include "Dependencies.lua"

workspace "Lila"
   linkgroups "On"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Editor"
   warnings "Off"

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Dependencies"
   include "Lila/vendor/glad"
   include "Lila/vendor/glfw"
   include "Lila/vendor/imgui"
group ""

group "Lila Engine"
   include "Lila/build.lua"
   include "LilaEditor/build.lua"
group ""