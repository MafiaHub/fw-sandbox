
include_directories(../vendors/wicked/WickedEngine ${CMAKE_SOURCE_DIR}/code/framework)

if (WIN32)
add_subdirectory(game)
endif ()

add_subdirectory(server)
