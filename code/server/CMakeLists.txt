set(SANDBOX_SERVER_SRC_FILES
    main.cpp
    server.cpp

    ${CMAKE_BINARY_DIR}/sandbox_version.cpp
)

add_executable(SandboxServer ${SANDBOX_SERVER_SRC_FILES})
target_include_directories(SandboxServer PRIVATE .)
target_link_libraries(SandboxServer Framework FrameworkServer)
