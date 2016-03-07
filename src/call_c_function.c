#include <stdio.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int add(lua_State *L){
  int a = lua_tointeger(L,1);
  int b = lua_tointeger(L,2);

  int r = a+b;

  lua_pushinteger(L, r);
  return 1; // number of return value
}

int main(int argc, char *argv[]){
  const char *fn = "call_c_function.lua";
  lua_State *L = luaL_newstate();

  luaL_openlibs(L);

  lua_register(L, "add", add);
  
  luaL_dofile(L, fn);

  lua_close(L);

  return 0;
}
