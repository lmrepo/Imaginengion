project "SangSang"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Imaginengion/vendor/spdlog/include",
		"%{wks.location}/Imaginengion/src",
		"%{wks.location}/Imaginengion/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}"
	}

	links
	{
		"Imaginengion"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "IMAGINE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "IMAGINE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "IMAGINE_DIST"
		runtime "Release"
		optimize "on"