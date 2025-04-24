workspace "OneVOneGame"
    architecture "x64"
    startproject "Server"

    configurations { "Debug", "Release" }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    IncludeDir = {}
    IncludeDir["ENet"] = "vendor/enet/include"
    IncludeDir["Shared"] = "shared"

    project "ENet"
        kind "StaticLib"
        language "C"
        staticruntime "on"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files {
            "vendor/enet/**.c",
            "vendor/enet/**.h"
        }

        includedirs {
            "vendor/enet/include"
        }

        filter "system:windows"
            systemversion "latest"

        filter "configurations:Debug"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            runtime "Release"
            optimize "on"

project "Client"
    location "client"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "client/**.h",
        "client/**.cpp"
    }

    includedirs {
        "%{IncludeDir.ENet}",
        "%{IncludeDir.Shared}"
    }

    links {
        "ENet"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"

project "Server"
    location "server"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "server/**.h",
        "server/**.cpp"
    }

    includedirs {
        "%{IncludeDir.ENet}",
        "%{IncludeDir.Shared}"
    }

    links {
        "ENet"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
