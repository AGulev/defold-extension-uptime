#define EXTENSION_NAME UpTime
#define LIB_NAME "UpTime"
#define MODULE_NAME "uptime"

#define DLIB_LOG_DOMAIN LIB_NAME
#include <dmsdk/sdk.h>
#include "UpTime.h"

#if defined(DM_PLATFORM_IOS) || defined(DM_PLATFORM_ANDROID) || defined(DM_PLATFORM_OSX)

dmExtension::Result AppInitializeUpTime(dmExtension::AppParams* params)
{
  dmLogInfo("Registered extension UpTime");
  return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeUpTime(dmExtension::AppParams* params)
{
  return dmExtension::RESULT_OK;
}

static int GetUpTime(lua_State* L) {
  uint32_t upTime = UpTime_get();
  lua_pushnumber(L, upTime);
  return 1;
}

static const luaL_reg Module_methods[] =
{
  {"get", GetUpTime},
  {0,0}
};

static void LuaInit(lua_State* L)
{
  DM_LUA_STACK_CHECK(L, 0);
  luaL_register(L, MODULE_NAME, Module_methods);
  lua_pop(L, 1);
}

dmExtension::Result InitializeUpTime(dmExtension::Params* params)
{
  LuaInit(params->m_L);
  return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, AppInitializeUpTime, AppFinalizeUpTime, InitializeUpTime, 0, 0, 0)

#else

dmExtension::Result AppInitializeUpTime(dmExtension::AppParams* params)
{
  dmLogInfo("Registered extension UpTime (null)");
  return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeUpTime(dmExtension::AppParams* params)
{
  return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, AppInitializeUpTime, AppFinalizeUpTime, 0, 0, 0, 0)
#endif