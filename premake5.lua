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
            "client/client/**.h",
            "client/client/**.cpp"
        }

        includedirs {
            "vendor/enet/include",
            "client/vendor/SFML/include",
            "shared",
            "client/client/src",
        }

        libdirs {
            "client/vendor/SFML/lib"
        }

        links {
            "ENet",
            "sfml-graphics-d",
            "sfml-window-d",
            "sfml-system-d",
            "ws2_32.lib",
            "winmm.lib"
        }

        filter "system:windows"
            systemversion "latest"

        
        filter "configurations:Debug"
            runtime "Debug"
            symbols "on"
            links {
                "sfml-graphics-d",
                "sfml-window-d",
                "sfml-system-d",
                "sfml-audio-d"
            }
            postbuildcommands {
                '{COPY} "%{wks.location}/client/vendor/SFML/bin/sfml-graphics-d-3.dll" "%{cfg.targetdir}"',
                '{COPY} "%{wks.location}/client/vendor/SFML/bin/sfml-window-d-3.dll" "%{cfg.targetdir}"',
                '{COPY} "%{wks.location}/client/vendor/SFML/bin/sfml-system-d-3.dll" "%{cfg.targetdir}"',
                '{COPY} "%{wks.location}/client/vendor/SFML/bin/sfml-audio-d-3.dll" "%{cfg.targetdir}"'
            }
    
        filter "configurations:Release"
            runtime "Release"
            optimize "on"
            links {
                "sfml-graphics",
                "sfml-window",
                "sfml-system",
                "sfml-audio"
            }
            postbuildcommands {
                '{COPY} "%{wks.location}/client/vendor/SFML/bin/sfml-graphics-3.dll" "%{cfg.targetdir}"',
                '{COPY} "%{wks.location}/client/vendor/SFML/bin/sfml-window-3.dll" "%{cfg.targetdir}"',
                '{COPY} "%{wks.location}/client/vendor/SFML/bin/sfml-system-3.dll" "%{cfg.targetdir}"',
                '{COPY} "%{wks.location}/client/vendor/SFML/bin/sfml-audio-3.dll" "%{cfg.targetdir}"'
            }

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
            "ENet"
        }

        filter "system:windows"
            systemversion "latest"
            links {"ws2_32.lib", "winmm.lib" }

        filter "system:linux"
            links { "pthread", "m" }
            toolset "gcc"
            buildoptions { "-std=c++17" }

        filter "configurations:Debug"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            runtime "Release"
            optimize "on"
