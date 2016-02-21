#include "PluginInMobiLua.hpp"
#include "PluginInMobi/PluginInMobi.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/sdkbox.h"



int lua_PluginInMobiLua_PluginInMobi_removeIdType(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginInMobi::SBIMSDKIdType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginInMobi:removeIdType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_removeIdType'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::removeIdType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:removeIdType",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_removeIdType'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setRefreshInterval(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginInMobi:setRefreshInterval");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setRefreshInterval'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setRefreshInterval(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setRefreshInterval",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setRefreshInterval'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setInterstitialKeywords(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginInMobi:setInterstitialKeywords");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setInterstitialKeywords'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setInterstitialKeywords(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setInterstitialKeywords",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setInterstitialKeywords'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_showInterstitial(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            sdkbox::PluginInMobi::SBIMInterstitialAnimationType arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginInMobi:showInterstitial");
            if (!ok) { break; }
            sdkbox::PluginInMobi::showInterstitial(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            sdkbox::PluginInMobi::showInterstitial();
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginInMobi:showInterstitial");
            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginInMobi:showInterstitial");
            if (!ok) { break; }
            sdkbox::PluginInMobi::showInterstitial(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "sdkbox.PluginInMobi:showInterstitial",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_showInterstitial'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_addIdForType(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        sdkbox::PluginInMobi::SBIMSDKIdType arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginInMobi:addIdForType");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginInMobi:addIdForType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_addIdForType'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::addIdForType(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:addIdForType",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_addIdForType'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setLocation(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "sdkbox.PluginInMobi:setLocation");
            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "sdkbox.PluginInMobi:setLocation");
            if (!ok) { break; }
            sdkbox::PluginInMobi::setLocation(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginInMobi:setLocation");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginInMobi:setLocation");
            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2, "sdkbox.PluginInMobi:setLocation");
            if (!ok) { break; }
            sdkbox::PluginInMobi::setLocation(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "sdkbox.PluginInMobi:setLocation",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setLocation'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setIncome(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        unsigned int arg0;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "sdkbox.PluginInMobi:setIncome");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setIncome'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setIncome(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setIncome",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setIncome'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setAgeGroup(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginInMobi::SBIMSDKAgeGroup arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginInMobi:setAgeGroup");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setAgeGroup'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setAgeGroup(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setAgeGroup",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setAgeGroup'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setBannerKeywords(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginInMobi:setBannerKeywords");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setBannerKeywords'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setBannerKeywords(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setBannerKeywords",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setBannerKeywords'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setHouseholdIncome(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginInMobi::SBIMSDKHouseholdIncome arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginInMobi:setHouseholdIncome");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setHouseholdIncome'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setHouseholdIncome(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setHouseholdIncome",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setHouseholdIncome'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setInterests(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginInMobi:setInterests");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setInterests'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setInterests(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setInterests",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setInterests'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setLogLevel(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginInMobi::SBIMSDKLogLevel arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginInMobi:setLogLevel");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setLogLevel'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setLogLevel(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setLogLevel",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setLogLevel'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginInMobi::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_loadInterstitial(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_loadInterstitial'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::loadInterstitial();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:loadInterstitial",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_loadInterstitial'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_disableHardwareAccelerationForInterstitial(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_disableHardwareAccelerationForInterstitial'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::disableHardwareAccelerationForInterstitial();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:disableHardwareAccelerationForInterstitial",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_disableHardwareAccelerationForInterstitial'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setNationality(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginInMobi:setNationality");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setNationality'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setNationality(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setNationality",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setNationality'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setLanguage(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginInMobi:setLanguage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setLanguage'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setLanguage(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setLanguage",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setLanguage'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setGender(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginInMobi::SBIMSDKGender arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginInMobi:setGender");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setGender'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setGender(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setGender",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setGender'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setYearOfBirth(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginInMobi:setYearOfBirth");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setYearOfBirth'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setYearOfBirth(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setYearOfBirth",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setYearOfBirth'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setBannerAnimationType(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginInMobi::SBIMBannerAnimationType arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginInMobi:setBannerAnimationType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setBannerAnimationType'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setBannerAnimationType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setBannerAnimationType",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setBannerAnimationType'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setAreaCode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginInMobi:setAreaCode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setAreaCode'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setAreaCode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setAreaCode",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setAreaCode'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setAge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginInMobi:setAge");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setAge'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setAge(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setAge",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setAge'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_shouldAutoRefresh(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginInMobi:shouldAutoRefresh");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_shouldAutoRefresh'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::shouldAutoRefresh(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:shouldAutoRefresh",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_shouldAutoRefresh'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_getVersion(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_getVersion'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginInMobi::getVersion();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:getVersion",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_getVersion'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setPostalCode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginInMobi:setPostalCode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setPostalCode'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setPostalCode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setPostalCode",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setPostalCode'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_isInterstitialReady(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_isInterstitialReady'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginInMobi::isInterstitialReady();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:isInterstitialReady",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_isInterstitialReady'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_disableHardwareAccelerationForBanner(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_disableHardwareAccelerationForBanner'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::disableHardwareAccelerationForBanner();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:disableHardwareAccelerationForBanner",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_disableHardwareAccelerationForBanner'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setEthnicity(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginInMobi::SBIMSDKEthnicity arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginInMobi:setEthnicity");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setEthnicity'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setEthnicity(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setEthnicity",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setEthnicity'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_loadBanner(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_loadBanner'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::loadBanner();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:loadBanner",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_loadBanner'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginInMobiLua_PluginInMobi_setEducation(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginInMobi::SBIMSDKEducation arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginInMobi:setEducation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginInMobiLua_PluginInMobi_setEducation'", nullptr);
            return 0;
        }
        sdkbox::PluginInMobi::setEducation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi:setEducation",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setEducation'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginInMobiLua_PluginInMobi_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginInMobi)");
    return 0;
}

int lua_register_PluginInMobiLua_PluginInMobi(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginInMobi");
    tolua_cclass(tolua_S,"PluginInMobi","sdkbox.PluginInMobi","",nullptr);

    tolua_beginmodule(tolua_S,"PluginInMobi");
        tolua_function(tolua_S,"removeIdType", lua_PluginInMobiLua_PluginInMobi_removeIdType);
        tolua_function(tolua_S,"setRefreshInterval", lua_PluginInMobiLua_PluginInMobi_setRefreshInterval);
        tolua_function(tolua_S,"setInterstitialKeywords", lua_PluginInMobiLua_PluginInMobi_setInterstitialKeywords);
        tolua_function(tolua_S,"showInterstitial", lua_PluginInMobiLua_PluginInMobi_showInterstitial);
        tolua_function(tolua_S,"addIdForType", lua_PluginInMobiLua_PluginInMobi_addIdForType);
        tolua_function(tolua_S,"setLocation", lua_PluginInMobiLua_PluginInMobi_setLocation);
        tolua_function(tolua_S,"setIncome", lua_PluginInMobiLua_PluginInMobi_setIncome);
        tolua_function(tolua_S,"setAgeGroup", lua_PluginInMobiLua_PluginInMobi_setAgeGroup);
        tolua_function(tolua_S,"setBannerKeywords", lua_PluginInMobiLua_PluginInMobi_setBannerKeywords);
        tolua_function(tolua_S,"setHouseholdIncome", lua_PluginInMobiLua_PluginInMobi_setHouseholdIncome);
        tolua_function(tolua_S,"setInterests", lua_PluginInMobiLua_PluginInMobi_setInterests);
        tolua_function(tolua_S,"setLogLevel", lua_PluginInMobiLua_PluginInMobi_setLogLevel);
        tolua_function(tolua_S,"init", lua_PluginInMobiLua_PluginInMobi_init);
        tolua_function(tolua_S,"loadInterstitial", lua_PluginInMobiLua_PluginInMobi_loadInterstitial);
        tolua_function(tolua_S,"disableHardwareAccelerationForInterstitial", lua_PluginInMobiLua_PluginInMobi_disableHardwareAccelerationForInterstitial);
        tolua_function(tolua_S,"setNationality", lua_PluginInMobiLua_PluginInMobi_setNationality);
        tolua_function(tolua_S,"setLanguage", lua_PluginInMobiLua_PluginInMobi_setLanguage);
        tolua_function(tolua_S,"setGender", lua_PluginInMobiLua_PluginInMobi_setGender);
        tolua_function(tolua_S,"setYearOfBirth", lua_PluginInMobiLua_PluginInMobi_setYearOfBirth);
        tolua_function(tolua_S,"setBannerAnimationType", lua_PluginInMobiLua_PluginInMobi_setBannerAnimationType);
        tolua_function(tolua_S,"setAreaCode", lua_PluginInMobiLua_PluginInMobi_setAreaCode);
        tolua_function(tolua_S,"setAge", lua_PluginInMobiLua_PluginInMobi_setAge);
        tolua_function(tolua_S,"shouldAutoRefresh", lua_PluginInMobiLua_PluginInMobi_shouldAutoRefresh);
        tolua_function(tolua_S,"getVersion", lua_PluginInMobiLua_PluginInMobi_getVersion);
        tolua_function(tolua_S,"setPostalCode", lua_PluginInMobiLua_PluginInMobi_setPostalCode);
        tolua_function(tolua_S,"isInterstitialReady", lua_PluginInMobiLua_PluginInMobi_isInterstitialReady);
        tolua_function(tolua_S,"disableHardwareAccelerationForBanner", lua_PluginInMobiLua_PluginInMobi_disableHardwareAccelerationForBanner);
        tolua_function(tolua_S,"setEthnicity", lua_PluginInMobiLua_PluginInMobi_setEthnicity);
        tolua_function(tolua_S,"loadBanner", lua_PluginInMobiLua_PluginInMobi_loadBanner);
        tolua_function(tolua_S,"setEducation", lua_PluginInMobiLua_PluginInMobi_setEducation);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginInMobi).name();
    g_luaType[typeName] = "sdkbox.PluginInMobi";
    g_typeCast["PluginInMobi"] = "sdkbox.PluginInMobi";
    return 1;
}
TOLUA_API int register_all_PluginInMobiLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginInMobiLua_PluginInMobi(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

