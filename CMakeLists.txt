cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(myapp LANGUAGES C)

set(lua_path
    lua
)

file(GLOB_RECURSE lua_sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${lua_path}/src/*.c )

list(REMOVE_ITEM lua_sources
  ${lua_path}/src/lua.c
  ${lua_path}/src/luac.c
)

set(src
    src/main.c
)

include_directories( ${lua_path}/src )
add_executable(my_app ${src} ${lua_sources})
target_link_libraries(my_app m)
