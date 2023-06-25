set(SANDBOX_SERVER_SRC_FILES
    src/main.cpp
    
    src/core/server.cpp
    src/core/modules/human.cpp
    src/core/modules/vehicle.cpp

    ${CMAKE_BINARY_DIR}/sandbox_version.cpp
)

add_executable(SandboxServer ${SANDBOX_SERVER_SRC_FILES})
target_include_directories(SandboxServer PRIVATE src)
target_link_libraries(SandboxServer Framework FrameworkServer)
