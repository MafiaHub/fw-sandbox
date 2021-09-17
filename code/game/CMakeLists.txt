set(SANDBOX_SRC_FILES
    main.cpp
    player.cpp
    scenery.cpp
    frame.cpp
)

add_executable(SandboxGame ${SANDBOX_SRC_FILES})
target_include_directories(SandboxGame PRIVATE .)
target_link_libraries(SandboxGame Framework FrameworkClient raylib)
