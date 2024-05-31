project "Lila"
   kind "StaticLib"
   language "C++"
   cppdialect "C++17"
   staticruntime "off"

   files { "src/**.h", "src/**.cpp" }

   includedirs {
        "src",
        "%{IncludeDir.glad}",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.stb}"
   }

   links {
        "glad",
        "glfw"
   }

   if _OPTIONS["coverage"] then
    buildoptions { "-fprofile-arcs", "-ftest-coverage" }
    links { "gcov" }
   end
   targetdir ("../bin/" .. OutputDir .. "/%{prj.name}")
   objdir ("../bin/obj/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"

    filter "system:linux"
        links {
            "dl",
            "pthread"
        }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"