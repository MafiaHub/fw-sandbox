include(UpdateGitHash)

update_git_version(SANDBOX "${CMAKE_CURRENT_SOURCE_DIR}/shared/version.cpp.in" "${CMAKE_BINARY_DIR}/sandbox_version.cpp")

include_directories(../vendors/wicked/WickedEngine ${CMAKE_SOURCE_DIR}/code/framework)

if (WIN32)
add_subdirectory(game)
endif ()

add_subdirectory(server)
