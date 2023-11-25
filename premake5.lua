include "Dependencies.lua"

workspace "Lila"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Lila"

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Dependencies"
	include "Lila/vendor/glad"
	include "Lila/vendor/glfw"
group ""

group "Lila Engine"
	include "Lila/build.lua"
group ""