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

include_directories( ${lua_path}/src )
add_executable(hello src/hello.c ${lua_sources})
add_executable(call_lua_function src/call_lua_function.c ${lua_sources})
target_link_libraries(hello m)
target_link_libraries(call_lua_function m)
