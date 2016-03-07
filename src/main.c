#include <stdio.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main(int argc, char *argv[]){
  const char *fn = "hello.lua";
  lua_State *lua = luaL_newstate();

  luaL_openlibs(lua);

  printf("%d\n", luaL_dofile(lua, fn));

  return 0;
}
