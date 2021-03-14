-- premake5.lua

workspace "Hearth"
	configurations { "Debug", "Release" }

project "Hearth"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}"

	files { "src/**" }
	includedirs { "include" }
	cppdialect "C++17"

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
		
	filter "configurations:Release"
		defines { "NODEBUG" }
		optimize "On"
