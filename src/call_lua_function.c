#include <stdio.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main(int argc, char *argv[]){
  const char *fn = "add.lua";
  lua_State *L = luaL_newstate();

  luaL_openlibs(L);
  luaL_dofile(L, fn);

  lua_getglobal(L, "lua_add");
  lua_pushnumber(L, 12);
  lua_pushnumber(L, 23);

  lua_call(L,2,1);

  int n = lua_tointeger(L,-1);
  lua_pop(L,1);

  printf("%d\n",n);

  lua_close(L);

  return 0;
}
