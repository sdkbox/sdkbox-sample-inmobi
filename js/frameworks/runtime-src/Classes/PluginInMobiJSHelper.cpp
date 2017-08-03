#include "PluginInMobiJSHelper.h"
#include "PluginInMobi/PluginInMobi.h"
#include "SDKBoxJSHelper.h"

extern JSObject* jsb_sdkbox_PluginInMobi_prototype;
static JSContext* s_cx = nullptr;

#if (COCOS2D_VERSION < 0x00030000)
#define Ref CCObject
#define Director CCDirector
#define getInstance sharedDirector
#define schedule scheduleSelector
#endif

class IMCallbackJS: public cocos2d::Ref {
public:
    IMCallbackJS();
    void schedule();
    void notityJs(float dt);
    void transParams(JSContext* cx);

    std::string _name;

    JS::Value _paramVal[2];
    int _paramLen;

    sdkbox::PluginInMobi::SBIMStatusCode _code;
    std::string _description;
    std::map<std::string, std::string> _params;
};

class InMobiListenerJS : public sdkbox::InMobiListener, public sdkbox::JSListenerBase
{
public:
    InMobiListenerJS():sdkbox::JSListenerBase() {
    }

    void bannerDidFinishLoading() {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "bannerDidFinishLoading";
        cb->schedule();
    }

    void bannerDidFailToLoadWithError(sdkbox::PluginInMobi::SBIMStatusCode code, const std::string& description) {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "bannerDidFailToLoadWithError";
        cb->_code = code;
        cb->_description = description;
        cb->_paramLen = 2;
        cb->schedule();
    }

    void bannerDidInteractWithParams(const std::map<std::string, std::string>& params) {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "bannerDidInteractWithParams";
        cb->_params = params;
        cb->_paramLen = 1;
        cb->schedule();
    }

    void userWillLeaveApplicationFromBanner() {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "userWillLeaveApplicationFromBanner";
        cb->schedule();
    }

    void bannerWillPresentScreen() {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "bannerWillPresentScreen";
        cb->schedule();
    }

    void bannerDidPresentScreen() {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "bannerDidPresentScreen";
        cb->schedule();
    }

    void bannerWillDismissScreen() {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "bannerWillDismissScreen";
        cb->schedule();
    }

    void bannerDidDismissScreen() {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "bannerDidDismissScreen";
        cb->schedule();
    }

    void bannerRewardActionCompletedWithRewards(const std::map<std::string, std::string>& rewards) {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "bannerRewardActionCompletedWithRewards";
        cb->_params = rewards;
        cb->_paramLen = 1;
        cb->schedule();
    }

    void interstitialDidFinishLoading() {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "interstitialDidFinishLoading";
        cb->schedule();
    }

    void interstitialDidFailToLoadWithError(sdkbox::PluginInMobi::SBIMStatusCode code, const std::string& description) {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "interstitialDidFailToLoadWithError";
        cb->_code = code;
        cb->_description = description;
        cb->_paramLen = 2;
        cb->schedule();
    }

    void interstitialWillPresent() {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "interstitialWillPresent";
        cb->schedule();
    }

    void interstitialDidPresent() {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "interstitialDidPresent";
        cb->schedule();
    }

    void interstitialDidFailToPresentWithError(sdkbox::PluginInMobi::SBIMStatusCode code, const std::string& description) {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "interstitialDidFailToPresentWithError";
        cb->_code = code;
        cb->_description = description;
        cb->_paramLen = 2;
        cb->schedule();
    }

    void interstitialWillDismiss() {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "interstitialWillDismiss";
        cb->schedule();
    }

    void interstitialDidDismiss() {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "interstitialDidDismiss";
        cb->schedule();
    }

    void interstitialDidInteractWithParams(const std::map<std::string, std::string>& params) {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "interstitialDidInteractWithParams";
        cb->_params = params;
        cb->_paramLen = 1;
        cb->schedule();
    }

    void interstitialRewardActionCompletedWithRewards(const std::map<std::string, std::string>& rewards) {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "interstitialRewardActionCompletedWithRewards";
        cb->_params = rewards;
        cb->_paramLen = 1;
        cb->schedule();
    }

    void userWillLeaveApplicationFromInterstitial() {
        IMCallbackJS* cb = new IMCallbackJS();
        cb->_name = "userWillLeaveApplicationFromInterstitial";
        cb->schedule();
    }


    void invokeJS(const char* func, IMCallbackJS* cb) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = func;
        JS::RootedObject obj(cx, getJSDelegate());
        JSAutoCompartment ac(cx, obj);

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#else
        bool hasAction;
        jsval retval;
        JS::RootedValue func_handle(cx);
#endif
#elif defined(JS_VERSION)
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif

        cb->transParams(cx);
        JS::Value* pVals = cb->_paramVal;
        int valueSize = cb->_paramLen;

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JS::NullValue()) {
                return;
            }

#if MOZJS_MAJOR_VERSION >= 31
            if (0 == valueSize) {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::empty(), &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(valueSize, pVals), &retval);
            }
#else
            if (0 == valueSize) {
                JS_CallFunctionName(cx, obj, func_name, 0, nullptr, &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, valueSize, pVals, &retval);
            }
#endif
        }
    }

};


IMCallbackJS::IMCallbackJS():
_paramLen(0) {
}

void IMCallbackJS::schedule() {
    retain();
    cocos2d::Director::getInstance()->getScheduler()->schedule(schedule_selector(IMCallbackJS::notityJs), this, 0.1, 0, 0.0f, false);
    autorelease();
}

void IMCallbackJS::notityJs(float dt) {
    sdkbox::InMobiListener* lis = sdkbox::PluginInMobi::getListener();
    InMobiListenerJS* l = dynamic_cast<InMobiListenerJS*>(lis);
    if (l) {
        l->invokeJS(_name.c_str(), this);
    }
    release();
}

void IMCallbackJS::transParams(JSContext* cx) {
    if (0 == _name.compare("bannerDidFailToLoadWithError")
        || 0 == _name.compare("interstitialDidFailToLoadWithError")
        || 0 == _name.compare("interstitialDidFailToPresentWithError")) {
        _paramVal[0] = JS::Int32Value(_code);
        _paramVal[1] = SB_STR_TO_JSVAL(cx, _description);
        _paramLen = 2;
    } else if (0 == _name.compare("bannerDidInteractWithParams")
               || 0 == _name.compare("bannerRewardActionCompletedWithRewards")
               || 0 == _name.compare("interstitialDidInteractWithParams")
               || 0 == _name.compare("interstitialRewardActionCompletedWithRewards")) {
        JS::RootedValue jsMap(cx);
        sdkbox::std_map_string_string_to_jsval(cx, _params, &jsMap);
        _paramVal[0] = jsMap;
        _paramLen = 1;
    } else {
        _paramLen = 0;
    }
}


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
bool js_PluginInMobiJS_PluginInMobi_setListener(JSContext *cx, uint32_t argc, JS::Value *vp)
#else
bool js_PluginInMobiJS_PluginInMobi_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
{
    s_cx = cx;
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    if (argc == 1) {

        if (!args.get(0).isObject())
        {
            ok = false;
        }

        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setIAPListener : Error processing arguments");
        InMobiListenerJS* wrapper = new InMobiListenerJS();
        wrapper->setJSDelegate(cx, args.get(0));
        sdkbox::PluginInMobi::setListener(wrapper);

        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginInMobiJS_PluginInMobi_setIAPListener : wrong number of arguments");
    return false;
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
bool js_PluginInMobiJS_PluginInMobi_setLocation(JSContext *cx, uint32_t argc, JS::Value *vp)
#else
bool js_PluginInMobiJS_PluginInMobi_setLocation(JSContext *cx, uint32_t argc, jsval *vp)
#endif
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setLocation(JSContext *cx, uint32_t argc, jsval *vp)
#endif
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    do {
        if (argc == 2) {
            double arg0;
            ok &= sdkbox::js_to_number(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            double arg1;
            ok &= sdkbox::js_to_number(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            sdkbox::PluginInMobi::setLocation(arg0, arg1);
            return true;
        }
    } while (0);

    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            std::string arg2;
            ok &= jsval_to_std_string(cx, args.get(2), &arg2);
            if (!ok) { ok = true; break; }
            sdkbox::PluginInMobi::setLocation(arg0, arg1, arg2);
            return true;
        }
    } while (0);
    JS_ReportErrorUTF8(cx, "js_PluginInMobiJS_PluginInMobi_setLocation : wrong number of arguments");
    return false;
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
bool js_PluginInMobiJS_PluginInMobi_showInterstitial(JSContext *cx, uint32_t argc, JS::Value *vp)
#else
bool js_PluginInMobiJS_PluginInMobi_showInterstitial(JSContext *cx, uint32_t argc, jsval *vp)
#endif
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_showInterstitial(JSContext *cx, uint32_t argc, jsval *vp)
#endif
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    do {
        if (argc == 0) {
            sdkbox::PluginInMobi::showInterstitial("");
            return true;
        }
    } while (0);

    do {
        if (argc == 1) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            sdkbox::PluginInMobi::showInterstitial(arg0);
            return true;
        }
    } while (0);

    do {
        if (argc == 1) {
            sdkbox::PluginInMobi::SBIMInterstitialAnimationType arg0;
            ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
            if (!ok) { ok = true; break; }
            sdkbox::PluginInMobi::showInterstitial(arg0, "");
            return true;
        }
    } while (0);

    do {
        if (argc == 2) {
            sdkbox::PluginInMobi::SBIMInterstitialAnimationType arg0;
            ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(0), &arg1);
            if (!ok) { ok = true; break; }
            sdkbox::PluginInMobi::showInterstitial(arg0, arg1);
            return true;
        }
    } while (0);

    do {
        if (argc == 2) {
            int arg0;
            ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
            if (!ok) { ok = true; break; }
            int arg1;
            ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
            if (!ok) { ok = true; break; }
            sdkbox::PluginInMobi::showInterstitial(arg0, arg1, "");
            return true;
        }
    } while (0);

    do {
        if (argc == 3) {
            int arg0;
            ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
            if (!ok) { ok = true; break; }
            int arg1;
            ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
            if (!ok) { ok = true; break; }
            std::string arg2;
            ok &= jsval_to_std_string(cx, args.get(0), &arg2);
            if (!ok) { ok = true; break; }
            sdkbox::PluginInMobi::showInterstitial(arg0, arg1, arg2);
            return true;
        }
    } while (0);

    JS_ReportErrorUTF8(cx, "js_PluginInMobiJS_PluginInMobi_showInterstitial : wrong number of arguments");
    return false;
}

#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void inmobi_set_constants(JSContext* cx, const JS::RootedObject& obj, const std::string& name, const std::map<std::string, int>& params)
#else
void inmobi_set_constants(JSContext* cx, JSObject* obj, const std::string& name, const std::map<std::string, int>& params)
#endif
{
    JS::RootedValue val(cx);
    sdkbox::std_map_string_int_to_jsval(cx, params, &val);

    JS::RootedValue rv(cx);
    rv = val;
#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
    JS_SetProperty(cx, obj, name.c_str(), rv);
#else
    JS_SetProperty(cx, obj, name.c_str(), rv.address());
#endif
}

#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void inmobi_register_constants(JSContext* cx, const JS::RootedObject& obj)
#else
void inmobi_register_constants(JSContext* cx, JSObject* obj)
#endif
{
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
    inmobi_set_constants(cx, obj, "SBIMStatusCode", enums);

    enums.clear();
    enums.insert(std::make_pair("kIMSDKIdTypeSession", 0));
    enums.insert(std::make_pair("kIMSDKIdTypeLogin", 1));
    inmobi_set_constants(cx, obj, "SBIMSDKIdType", enums);

    enums.clear();
    enums.insert(std::make_pair("kIMSDKLogLevelNone", 0));
    enums.insert(std::make_pair("kIMSDKLogLevelError", 1));
    enums.insert(std::make_pair("kIMSDKLogLevelDebug", 2));
    inmobi_set_constants(cx, obj, "SBIMSDKLogLevel", enums);

    enums.clear();
    enums.insert(std::make_pair("kIMSDKGenderMale", 1));
    enums.insert(std::make_pair("kIMSDKGenderFemale", 2));
    inmobi_set_constants(cx, obj, "SBIMSDKGender", enums);

    enums.clear();
    enums.insert(std::make_pair("kIMSDKEducationHighSchoolOrLess", 1));
    enums.insert(std::make_pair("kIMSDKEducationCollegeOrGraduate", 2));
    enums.insert(std::make_pair("kIMSDKEducationPostGraduateOrAbove", 3));
    inmobi_set_constants(cx, obj, "SBIMSDKEducation", enums);

    enums.clear();
    enums.insert(std::make_pair("kIMSDKEthnicityHispanic", 1));
    enums.insert(std::make_pair("kIMSDKEthnicityCaucasian", 2));
    enums.insert(std::make_pair("kIMSDKEthnicityAsian", 3));
    enums.insert(std::make_pair("kIMSDKEthnicityAfricanAmerican", 4));
    enums.insert(std::make_pair("kIMSDKEthnicityOther", 5));
    inmobi_set_constants(cx, obj, "SBIMSDKEthnicity", enums);

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
    inmobi_set_constants(cx, obj, "SBIMSDKHouseholdIncome", enums);

    enums.clear();
    enums.insert(std::make_pair("kIMSDKAgeGroupBelow18", 1));
    enums.insert(std::make_pair("kIMSDKAgeGroupBetween18And20", 2));
    enums.insert(std::make_pair("kIMSDKAgeGroupBetween21And24", 3));
    enums.insert(std::make_pair("kIMSDKAgeGroupBetween25And34", 4));
    enums.insert(std::make_pair("kIMSDKAgeGroupBetween35And54", 5));
    enums.insert(std::make_pair("kIMSDKAgeGroupAbove55", 6));
    inmobi_set_constants(cx, obj, "SBIMSDKAgeGroup", enums);

    enums.clear();
    enums.insert(std::make_pair("kIMInterstitialAnimationTypeCoverVertical", 0));
    enums.insert(std::make_pair("kIMInterstitialAnimationTypeFlipHorizontal", 1));
    enums.insert(std::make_pair("kIMInterstitialAnimationTypeNone", 2));
    inmobi_set_constants(cx, obj, "SBIMInterstitialAnimationType", enums);

    enums.clear();
    enums.insert(std::make_pair("kIMBannerAnimationTypeOff", 0));
    enums.insert(std::make_pair("kIMBannerAnimationTypeAlpha", 1));
    enums.insert(std::make_pair("kIMBannerAnimationTypeRotateHorizontalAxis", 2));
    enums.insert(std::make_pair("kIMBannerAnimationTypeRotateVerticalAxis", 3));
    inmobi_set_constants(cx, obj, "SBIMBannerAnimationType", enums);
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginInMobiJS_helper(JSContext* cx, JS::HandleObject global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginInMobi", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginInMobiJS_PluginInMobi_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "setLocation", js_PluginInMobiJS_PluginInMobi_setLocation, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "showInterstitial", js_PluginInMobiJS_PluginInMobi_showInterstitial, 1, JSPROP_READONLY | JSPROP_PERMANENT);

    inmobi_register_constants(cx, pluginObj);
}
#else
void register_all_PluginInMobiJS_helper(JSContext* cx, JSObject* global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, JS::RootedObject(cx, global), "sdkbox.PluginInMobi", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginInMobiJS_PluginInMobi_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "setLocation", js_PluginInMobiJS_PluginInMobi_setLocation, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "showInterstitial", js_PluginInMobiJS_PluginInMobi_showInterstitial, 1, JSPROP_READONLY | JSPROP_PERMANENT);

    inmobi_register_constants(cx, pluginObj);
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginInMobiJS_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginInMobi", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginInMobiJS_PluginInMobi_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "setLocation", js_PluginInMobiJS_PluginInMobi_setLocation, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "showInterstitial", js_PluginInMobiJS_PluginInMobi_showInterstitial, 1, JSPROP_READONLY | JSPROP_PERMANENT);

    inmobi_register_constants(cx, pluginObj);
}
#endif
