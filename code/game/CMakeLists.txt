set(SANDBOX_SRC_FILES
    main.cpp
)

add_executable(SandboxGame WIN32 ${SANDBOX_SRC_FILES})
target_include_directories(SandboxGame PRIVATE .)
target_link_libraries(SandboxGame Framework FrameworkClient WickedEngine)

# Copy the shader library next to the executable
add_custom_command(
		TARGET SandboxGame POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/../../vendors/wicked/WickedEngine/dxil.dll ${CMAKE_BINARY_DIR}/bin
		COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/../../vendors/wicked/WickedEngine/dxcompiler.dll ${CMAKE_BINARY_DIR}/bin
		COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_CURRENT_SOURCE_DIR}/../../vendors/wicked/WickedEngine/shaders ${CMAKE_BINARY_DIR}/bin/shaders
)
