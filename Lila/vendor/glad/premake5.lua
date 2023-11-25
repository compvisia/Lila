project "glad"
	kind "StaticLib"
	language "C"
	staticruntime "off"
	warnings "off"

	targetdir ("bin/" .. OutputDir .. "/%{prj.name}")
	objdir ("bin/obj/" .. OutputDir .. "/%{prj.name}")

	files
	{
		"include/glad/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c"
	}

	includedirs {
		"include"
	}

	filter "system:linux"
		pic "On"

		systemversion "latest"

	filter "system:macosx"
		pic "On"

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "speed"
