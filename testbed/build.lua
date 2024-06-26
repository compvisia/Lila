project "Testbed"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "off"

   files { "src/**.h", "src/**.cpp" }

   includedirs {
        "%{wks.location}/Lila/src",
        "%{IncludeDir.glad}",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.stb}"
   }

   links {
        "Lila",
        "glad",
        "glfw"
   }

   if _OPTIONS["coverage"] then
      buildoptions { "-fprofile-arcs", "-ftest-coverage" }
      links { "gcov" }
   end

   if _OPTIONS["headless"] then
    defines { "LILA_HEADLESS_CONTEXT" }
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