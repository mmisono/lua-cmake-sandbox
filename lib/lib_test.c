#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>


int lib_test(lua_State* L){
    lua_pushstring(L,"hello");
    return 1;
}


