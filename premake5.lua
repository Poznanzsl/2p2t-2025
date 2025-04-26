workspace "OneVOneGame"
    architecture "x64"
    startproject "Client"

    configurations { "Debug", "Release" }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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

        links {
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
        "vendor/enet/include",
        "shared",
        "client/client/src"
    }

    links {
        "ENet",
        "ws2_32.lib",
        "winmm.lib"
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
        "vendor/enet/include",
        "shared"
    }

    links {
        "ENet",
        "ws2_32.lib",
        "winmm.lib"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
