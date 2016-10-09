
#include "PluginInMobiLuaHelper.h"
#include "PluginInMobi/PluginInMobi.h"
#include "SDKBoxLuaHelper.h"

class InMobiListenerLua : public sdkbox::InMobiListener {
public:
    InMobiListenerLua(): mLuaHandler(0) {
    }

    ~InMobiListenerLua() {
        resetHandler();
    }

    void setHandler(int luaHandler) {
        if (mLuaHandler == luaHandler) {
            return;
        }
        resetHandler();
        mLuaHandler = luaHandler;
    }

    void resetHandler() {
        if (0 == mLuaHandler) {
            return;
        }

        LUAENGINE->removeScriptHandler(mLuaHandler);
        mLuaHandler = 0;
    }


    void bannerDidFinishLoading() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("bannerDidFinishLoading")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void bannerDidFailToLoadWithError(sdkbox::PluginInMobi::SBIMStatusCode code, const std::string& description) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("bannerDidFailToLoadWithError")));
        dict.insert(std::make_pair("code", LuaValue::intValue(code)));
        dict.insert(std::make_pair("description", LuaValue::stringValue(description)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void bannerDidInteractWithParams(const std::map<std::string, std::string>& params) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict paramsDict;
        for (auto it : params) {
            paramsDict.insert(std::make_pair(it.first, LuaValue::stringValue(it.second)));
        }

        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("bannerDidInteractWithParams")));
        dict.insert(std::make_pair("params", LuaValue::dictValue(paramsDict)));


        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void userWillLeaveApplicationFromBanner() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("userWillLeaveApplicationFromBanner")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void bannerWillPresentScreen() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("bannerWillPresentScreen")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void bannerDidPresentScreen() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("bannerDidPresentScreen")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void bannerWillDismissScreen() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("bannerWillDismissScreen")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void bannerDidDismissScreen() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("bannerDidDismissScreen")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void bannerRewardActionCompletedWithRewards(const std::map<std::string, std::string>& rewards) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict rewardsDict;
        for (auto it : rewards) {
            rewardsDict.insert(std::make_pair(it.first, LuaValue::stringValue(it.second)));
        }
        
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("bannerRewardActionCompletedWithRewards")));
        dict.insert(std::make_pair("rewards", LuaValue::dictValue(rewardsDict)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void interstitialDidFinishLoading() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("interstitialDidFinishLoading")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void interstitialDidFailToLoadWithError(sdkbox::PluginInMobi::SBIMStatusCode code, const std::string& description) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("interstitialDidFailToLoadWithError")));
        dict.insert(std::make_pair("code", LuaValue::intValue(code)));
        dict.insert(std::make_pair("description", LuaValue::stringValue(description)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void interstitialWillPresent() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("interstitialWillPresent")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void interstitialDidPresent() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("interstitialDidPresent")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void interstitialDidFailToPresentWithError(sdkbox::PluginInMobi::SBIMStatusCode code, const std::string& description) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("interstitialDidFailToPresentWithError")));
        dict.insert(std::make_pair("code", LuaValue::intValue(code)));
        dict.insert(std::make_pair("description", LuaValue::stringValue(description)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void interstitialWillDismiss() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("interstitialWillDismiss")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void interstitialDidDismiss() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("interstitialDidDismiss")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void interstitialDidInteractWithParams(const std::map<std::string, std::string>& params) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        
        LuaValueDict paramsDict;
        for (auto it : params) {
            paramsDict.insert(std::make_pair(it.first, LuaValue::stringValue(it.second)));
        }

        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("interstitialDidInteractWithParams")));
        dict.insert(std::make_pair("params", LuaValue::dictValue(paramsDict)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void interstitialRewardActionCompletedWithRewards(const std::map<std::string, std::string>& rewards) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        
        LuaValueDict rewardsDict;
        for (auto it : rewards) {
            rewardsDict.insert(std::make_pair(it.first, LuaValue::stringValue(it.second)));
        }
        
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("interstitialRewardActionCompletedWithRewards")));
        dict.insert(std::make_pair("rewards", LuaValue::dictValue(rewardsDict)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };

    void userWillLeaveApplicationFromInterstitial() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("event", LuaValue::stringValue("userWillLeaveApplicationFromInterstitial")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    };


private:
    int mLuaHandler;
};

int lua_PluginInMobiLua_PluginInMobi_setListener(lua_State* tolua_S) {
    int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S, 2 , "LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        InMobiListenerLua* lis = static_cast<InMobiListenerLua*> (sdkbox::PluginInMobi::getListener());
        if (NULL == lis) {
            lis = new InMobiListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginInMobi::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setListener'.",&tolua_err);
#endif
    return 0;
}

int lua_PluginInMobiLua_PluginInMobi_setBannerExtras(lua_State* tolua_S) {
    int argc = 0;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_istable(tolua_S, 2, 0, &tolua_err)) {
            goto tolua_lerror;
        }
#endif
        std::map<std::string, std::string> extras;
        if (!luaval_to_std_map_string_string(tolua_S, 2, &extras, "sdkbox.PluginInMobi:setBannerExtras")) {
            return 0;
        }
        sdkbox::PluginInMobi::setBannerExtras(extras);
        
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setListener'.",&tolua_err);
#endif
    return 0;
}

int lua_PluginInMobiLua_PluginInMobi_setInterstitialExtras(lua_State* tolua_S) {
    int argc = 0;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginInMobi",0,&tolua_err)) goto tolua_lerror;
#endif
    
    argc = lua_gettop(tolua_S) - 1;
    
    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        if (!tolua_istable(tolua_S, 2, 0, &tolua_err)) {
            goto tolua_lerror;
        }
#endif
        std::map<std::string, std::string> extras;
        if (!luaval_to_std_map_string_string(tolua_S, 2, &extras, "sdkbox.PluginInMobi:setInterstitialExtras")) {
            return 0;
        }
        sdkbox::PluginInMobi::setInterstitialExtras(extras);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginInMobi::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginInMobiLua_PluginInMobi_setListener'.",&tolua_err);
#endif
    return 0;
}

static int lua_createTable(lua_State* L, const std::map<std::string, int>& map) {
    lua_newtable(L);
    
    std::map<std::string, int>::const_iterator it = map.begin();
    while (it != map.end()) {
        lua_pushstring(L, it->first.c_str());
        lua_pushinteger(L, it->second);
        lua_settable(L, -3);
        it++;
    }
    
    return 1;
}

static int lua_setTable(lua_State* L, int table, const std::string& name, const std::map<std::string, int>& map) {
    if (table < 0) {
        table = lua_gettop(L) + table + 1;
    }
    lua_pushstring(L, name.c_str());
    lua_createTable(L, map);
    lua_rawset(L, table);

    return 0;
}

int lua_PluginInMobiLua_constants(lua_State* L) {
    if (NULL == L) {
        return 0;
    }
    
    lua_pushstring(L, "sdkbox.PluginInMobi");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1)) {
        
        std::map<std::string, int> enums;
        enums.clear();
        enums.insert(std::make_pair("kIMStatusCodeNetworkUnReachable", 0));
        enums.insert(std::make_pair("kIMStatusCodeNoFill", 1));
        enums.insert(std::make_pair("kIMStatusCodeRequestInvalid", 2));
        enums.insert(std::make_pair("kIMStatusCodeRequestPending", 3));
        enums.insert(std::make_pair("kIMStatusCodeRequestTimedOut", 4));
        enums.insert(std::make_pair("kIMStatusCodeInternalError", 5));
        enums.insert(std::make_pair("kIMStatusCodeServerError", 6));
        enums.insert(std::make_pair("kIMStatusCodeAdActive", 7));
        enums.insert(std::make_pair("kIMStatusCodeEarlyRefreshRequest", 8));
        lua_setTable(L, -1, "SBIMStatusCode", enums);

        enums.clear();
        enums.insert(std::make_pair("kIMSDKIdTypeSession", 0));
        enums.insert(std::make_pair("kIMSDKIdTypeLogin", 1));
        lua_setTable(L, -1, "SBIMSDKIdType", enums);

        enums.clear();
        enums.insert(std::make_pair("kIMSDKLogLevelNone", 0));
        enums.insert(std::make_pair("kIMSDKLogLevelError", 1));
        enums.insert(std::make_pair("kIMSDKLogLevelDebug", 2));
        lua_setTable(L, -1, "SBIMSDKLogLevel", enums);

        enums.clear();
        enums.insert(std::make_pair("kIMSDKGenderMale", 1));
        enums.insert(std::make_pair("kIMSDKGenderFemale", 2));
        lua_setTable(L, -1, "SBIMSDKGender", enums);

        enums.clear();
        enums.insert(std::make_pair("kIMSDKEducationHighSchoolOrLess", 1));
        enums.insert(std::make_pair("kIMSDKEducationCollegeOrGraduate", 2));
        enums.insert(std::make_pair("kIMSDKEducationPostGraduateOrAbove", 3));
        lua_setTable(L, -1, "SBIMSDKEducation", enums);

        enums.clear();
        enums.insert(std::make_pair("kIMSDKEthnicityHispanic", 1));
        enums.insert(std::make_pair("kIMSDKEthnicityCaucasian", 2));
        enums.insert(std::make_pair("kIMSDKEthnicityAsian", 3));
        enums.insert(std::make_pair("kIMSDKEthnicityAfricanAmerican", 4));
        enums.insert(std::make_pair("kIMSDKEthnicityOther", 5));
        lua_setTable(L, -1, "SBIMSDKEthnicity", enums);

        enums.clear();
        enums.insert(std::make_pair("kIMSDKHouseholdIncomeBelow5kUSD", 1));
        enums.insert(std::make_pair("kIMSDKHouseholdIncomeBetweek5kAnd10kUSD", 2));
        enums.insert(std::make_pair("kIMSDKHouseholdIncomeBetween10kAnd15kUSD", 3));
        enums.insert(std::make_pair("kIMSDKHouseholdIncomeBetween15kAnd20kUSD", 4));
        enums.insert(std::make_pair("kIMSDKHouseholdIncomeBetween20kAnd25kUSD", 5));
        enums.insert(std::make_pair("kIMSDKHouseholdIncomeBetween25kAnd50kUSD", 6));
        enums.insert(std::make_pair("kIMSDKHouseholdIncomeBetween50kAnd75kUSD", 7));
        enums.insert(std::make_pair("kIMSDKHouseholdIncomeBetween75kAnd100kUSD", 8));
        enums.insert(std::make_pair("kIMSDKHouseholdIncomeBetween100kAnd150kUSD", 9));
        enums.insert(std::make_pair("kIMSDKHouseholdIncomeAbove150kUSD", 10));
        lua_setTable(L, -1, "SBIMSDKHouseholdIncome", enums);

        enums.clear();
        enums.insert(std::make_pair("kIMSDKAgeGroupBelow18", 1));
        enums.insert(std::make_pair("kIMSDKAgeGroupBetween18And20", 2));
        enums.insert(std::make_pair("kIMSDKAgeGroupBetween21And24", 3));
        enums.insert(std::make_pair("kIMSDKAgeGroupBetween25And34", 4));
        enums.insert(std::make_pair("kIMSDKAgeGroupBetween35And54", 5));
        enums.insert(std::make_pair("kIMSDKAgeGroupAbove55", 6));
        lua_setTable(L, -1, "SBIMSDKAgeGroup", enums);

        enums.clear();
        enums.insert(std::make_pair("kIMInterstitialAnimationTypeCoverVertical", 0));
        enums.insert(std::make_pair("kIMInterstitialAnimationTypeFlipHorizontal", 1));
        enums.insert(std::make_pair("kIMInterstitialAnimationTypeNone", 2));
        lua_setTable(L, -1, "SBIMInterstitialAnimationType", enums);

        enums.clear();
        enums.insert(std::make_pair("kIMBannerAnimationTypeOff", 0));
        enums.insert(std::make_pair("kIMBannerAnimationTypeAlpha", 1));
        enums.insert(std::make_pair("kIMBannerAnimationTypeRotateHorizontalAxis", 2));
        enums.insert(std::make_pair("kIMBannerAnimationTypeRotateVerticalAxis", 3));
        lua_setTable(L, -1, "SBIMBannerAnimationType", enums);
    }
    lua_pop(L, 1);
    
    return 1;
}

int extern_PluginInMobi(lua_State* L) {
    if (NULL == L) {
        return 0;
    }

    lua_pushstring(L, "sdkbox.PluginInMobi");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginInMobiLua_PluginInMobi_setListener);
        tolua_function(L,"setBannerExtras", lua_PluginInMobiLua_PluginInMobi_setBannerExtras);
        tolua_function(L,"setInterstitialExtras", lua_PluginInMobiLua_PluginInMobi_setInterstitialExtras);
    }
     lua_pop(L, 1);
    
    lua_PluginInMobiLua_constants(L);

    return 1;
}

TOLUA_API int register_all_PluginInMobiLua_helper(lua_State* L) {
    tolua_module(L,"sdkbox",0);
    tolua_beginmodule(L,"sdkbox");

    extern_PluginInMobi(L);

    tolua_endmodule(L);
    return 1;
}


