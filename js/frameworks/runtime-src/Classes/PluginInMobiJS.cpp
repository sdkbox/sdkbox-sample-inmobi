#include "PluginInMobiJS.hpp"
#include "cocos2d_specifics.hpp"
#include "PluginInMobi/PluginInMobi.h"
#include "SDKBoxJSHelper.h"
#include "sdkbox/Sdkbox.h"


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

#if (COCOS2D_VERSION >= 0x00031000)
        JS::RootedObject proto(cx, typeClass->proto.ref());
        JS::RootedObject parent(cx, typeClass->parentProto.ref());
#else
        JS::RootedObject proto(cx, typeClass->proto.get());
        JS::RootedObject parent(cx, typeClass->parentProto.get());
#endif
        JS::RootedObject _tmp(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
        
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        AddObjectRoot(cx, &pp->obj);
        args.rval().set(OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;    
}
#else
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JSObject *_tmp = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        JS_AddObjectRoot(cx, &pp->obj);
        JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, JS::HandleObject obj, JS::HandleId id, JS::MutableHandleValue vp)
{
    vp.set(BOOLEAN_TO_JSVAL(true));
    return true;    
}
#endif
#elif defined(JS_VERSION)
template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    TypeTest<T> t;
    T* cobj = new T();
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    assert(p);
    JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
    js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

    return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return JS_FALSE;
}
#endif
JSClass  *jsb_sdkbox_PluginInMobi_class;
JSObject *jsb_sdkbox_PluginInMobi_prototype;

#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_removeIdType(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMSDKIdType arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_removeIdType : Error processing arguments");
        sdkbox::PluginInMobi::removeIdType(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_removeIdType : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_removeIdType(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMSDKIdType arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::removeIdType(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setRefreshInterval(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setRefreshInterval : Error processing arguments");
        sdkbox::PluginInMobi::setRefreshInterval(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setRefreshInterval : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setRefreshInterval(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setRefreshInterval(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setInterstitialKeywords(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setInterstitialKeywords : Error processing arguments");
        sdkbox::PluginInMobi::setInterstitialKeywords(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setInterstitialKeywords : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setInterstitialKeywords(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setInterstitialKeywords(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_addIdForType(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        sdkbox::PluginInMobi::SBIMSDKIdType arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_addIdForType : Error processing arguments");
        sdkbox::PluginInMobi::addIdForType(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_addIdForType : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_addIdForType(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        sdkbox::PluginInMobi::SBIMSDKIdType arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::addIdForType(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setIncome(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        unsigned int arg0;
        ok &= jsval_to_uint32(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setIncome : Error processing arguments");
        sdkbox::PluginInMobi::setIncome(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setIncome : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setIncome(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        unsigned int arg0;
        ok &= jsval_to_uint32(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setIncome(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setAgeGroup(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMSDKAgeGroup arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setAgeGroup : Error processing arguments");
        sdkbox::PluginInMobi::setAgeGroup(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setAgeGroup : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setAgeGroup(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMSDKAgeGroup arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setAgeGroup(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setBannerKeywords(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setBannerKeywords : Error processing arguments");
        sdkbox::PluginInMobi::setBannerKeywords(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setBannerKeywords : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setBannerKeywords(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setBannerKeywords(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setHouseholdIncome(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMSDKHouseholdIncome arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setHouseholdIncome : Error processing arguments");
        sdkbox::PluginInMobi::setHouseholdIncome(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setHouseholdIncome : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setHouseholdIncome(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMSDKHouseholdIncome arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setHouseholdIncome(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setInterests(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setInterests : Error processing arguments");
        sdkbox::PluginInMobi::setInterests(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setInterests : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setInterests(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setInterests(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setLogLevel(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMSDKLogLevel arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setLogLevel : Error processing arguments");
        sdkbox::PluginInMobi::setLogLevel(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setLogLevel : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setLogLevel(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMSDKLogLevel arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setLogLevel(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginInMobi::init();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginInMobi::init();
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_loadInterstitial(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginInMobi::loadInterstitial();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_loadInterstitial : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_loadInterstitial(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginInMobi::loadInterstitial();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForInterstitial(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginInMobi::disableHardwareAccelerationForInterstitial();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForInterstitial : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForInterstitial(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginInMobi::disableHardwareAccelerationForInterstitial();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setNationality(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setNationality : Error processing arguments");
        sdkbox::PluginInMobi::setNationality(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setNationality : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setNationality(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setNationality(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setLanguage(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setLanguage : Error processing arguments");
        sdkbox::PluginInMobi::setLanguage(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setLanguage : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setLanguage(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setLanguage(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setGender(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMSDKGender arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setGender : Error processing arguments");
        sdkbox::PluginInMobi::setGender(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setGender : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setGender(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMSDKGender arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setGender(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setYearOfBirth(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setYearOfBirth : Error processing arguments");
        sdkbox::PluginInMobi::setYearOfBirth(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setYearOfBirth : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setYearOfBirth(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setYearOfBirth(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setBannerAnimationType(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMBannerAnimationType arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setBannerAnimationType : Error processing arguments");
        sdkbox::PluginInMobi::setBannerAnimationType(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setBannerAnimationType : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setBannerAnimationType(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMBannerAnimationType arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setBannerAnimationType(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setAreaCode(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setAreaCode : Error processing arguments");
        sdkbox::PluginInMobi::setAreaCode(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setAreaCode : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setAreaCode(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setAreaCode(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setAge(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setAge : Error processing arguments");
        sdkbox::PluginInMobi::setAge(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setAge : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setAge(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setAge(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setInterstitialExtras(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::map<std::string, std::string> arg0;
        ok &= sdkbox::jsval_to_std_map_string_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setInterstitialExtras : Error processing arguments");
        sdkbox::PluginInMobi::setInterstitialExtras(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setInterstitialExtras : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setInterstitialExtras(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::map<std::string, std::string> arg0;
        ok &= sdkbox::jsval_to_std_map_string_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setInterstitialExtras(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_shouldAutoRefresh(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_shouldAutoRefresh : Error processing arguments");
        sdkbox::PluginInMobi::shouldAutoRefresh(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_shouldAutoRefresh : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_shouldAutoRefresh(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::shouldAutoRefresh(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_getVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginInMobi::getVersion();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_getVersion : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_getVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginInMobi::getVersion();
        jsval jsret;
        jsret = std_string_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setPostalCode(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setPostalCode : Error processing arguments");
        sdkbox::PluginInMobi::setPostalCode(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setPostalCode : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setPostalCode(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setPostalCode(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_isInterstitialReady(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginInMobi::isInterstitialReady();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_isInterstitialReady : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_isInterstitialReady(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginInMobi::isInterstitialReady();
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForBanner(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginInMobi::disableHardwareAccelerationForBanner();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForBanner : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForBanner(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginInMobi::disableHardwareAccelerationForBanner();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setBannerExtras(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::map<std::string, std::string> arg0;
        ok &= sdkbox::jsval_to_std_map_string_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setBannerExtras : Error processing arguments");
        sdkbox::PluginInMobi::setBannerExtras(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setBannerExtras : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setBannerExtras(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::map<std::string, std::string> arg0;
        ok &= sdkbox::jsval_to_std_map_string_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setBannerExtras(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setEthnicity(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMSDKEthnicity arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setEthnicity : Error processing arguments");
        sdkbox::PluginInMobi::setEthnicity(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setEthnicity : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setEthnicity(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMSDKEthnicity arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setEthnicity(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_loadBanner(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginInMobi::loadBanner();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_loadBanner : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_loadBanner(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginInMobi::loadBanner();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setEducation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMSDKEducation arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginInMobiJS_PluginInMobi_setEducation : Error processing arguments");
        sdkbox::PluginInMobi::setEducation(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginInMobiJS_PluginInMobi_setEducation : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setEducation(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginInMobi::SBIMSDKEducation arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginInMobi::setEducation(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginInMobiJS_PluginInMobi_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginInMobi)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;

#if (COCOS2D_VERSION >= 0x00031000)
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
#else
    jsproxy = jsb_get_js_proxy(obj);
#endif

    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        sdkbox::PluginInMobi *nobj = static_cast<sdkbox::PluginInMobi *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        jsb_remove_proxy(nproxy, jsproxy);
    }
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginInMobiJS_PluginInMobi(JSContext *cx, JS::HandleObject global) {
    jsb_sdkbox_PluginInMobi_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginInMobi_class->name = "PluginInMobi";
    jsb_sdkbox_PluginInMobi_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginInMobi_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginInMobi_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginInMobi_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginInMobi_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginInMobi_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginInMobi_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginInMobi_class->finalize = js_PluginInMobiJS_PluginInMobi_finalize;
    jsb_sdkbox_PluginInMobi_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("removeIdType", js_PluginInMobiJS_PluginInMobi_removeIdType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRefreshInterval", js_PluginInMobiJS_PluginInMobi_setRefreshInterval, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setInterstitialKeywords", js_PluginInMobiJS_PluginInMobi_setInterstitialKeywords, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addIdForType", js_PluginInMobiJS_PluginInMobi_addIdForType, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setIncome", js_PluginInMobiJS_PluginInMobi_setIncome, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgeGroup", js_PluginInMobiJS_PluginInMobi_setAgeGroup, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBannerKeywords", js_PluginInMobiJS_PluginInMobi_setBannerKeywords, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setHouseholdIncome", js_PluginInMobiJS_PluginInMobi_setHouseholdIncome, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setInterests", js_PluginInMobiJS_PluginInMobi_setInterests, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLogLevel", js_PluginInMobiJS_PluginInMobi_setLogLevel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginInMobiJS_PluginInMobi_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadInterstitial", js_PluginInMobiJS_PluginInMobi_loadInterstitial, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("disableHardwareAccelerationForInterstitial", js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForInterstitial, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setNationality", js_PluginInMobiJS_PluginInMobi_setNationality, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLanguage", js_PluginInMobiJS_PluginInMobi_setLanguage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGender", js_PluginInMobiJS_PluginInMobi_setGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setYearOfBirth", js_PluginInMobiJS_PluginInMobi_setYearOfBirth, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBannerAnimationType", js_PluginInMobiJS_PluginInMobi_setBannerAnimationType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAreaCode", js_PluginInMobiJS_PluginInMobi_setAreaCode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAge", js_PluginInMobiJS_PluginInMobi_setAge, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setInterstitialExtras", js_PluginInMobiJS_PluginInMobi_setInterstitialExtras, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("shouldAutoRefresh", js_PluginInMobiJS_PluginInMobi_shouldAutoRefresh, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVersion", js_PluginInMobiJS_PluginInMobi_getVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPostalCode", js_PluginInMobiJS_PluginInMobi_setPostalCode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isInterstitialReady", js_PluginInMobiJS_PluginInMobi_isInterstitialReady, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("disableHardwareAccelerationForBanner", js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForBanner, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBannerExtras", js_PluginInMobiJS_PluginInMobi_setBannerExtras, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setEthnicity", js_PluginInMobiJS_PluginInMobi_setEthnicity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadBanner", js_PluginInMobiJS_PluginInMobi_loadBanner, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setEducation", js_PluginInMobiJS_PluginInMobi_setEducation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginInMobi_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_sdkbox_PluginInMobi_class,
        dummy_constructor<sdkbox::PluginInMobi>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginInMobi", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
#if (COCOS2D_VERSION >= 0x00031000)
    JS::RootedObject proto(cx, jsb_sdkbox_PluginInMobi_prototype);
    jsb_register_class<sdkbox::PluginInMobi>(cx, jsb_sdkbox_PluginInMobi_class, proto, JS::NullPtr());
#else
    TypeTest<sdkbox::PluginInMobi> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginInMobi_class;
        p->proto = jsb_sdkbox_PluginInMobi_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
#endif
}
#else
void js_register_PluginInMobiJS_PluginInMobi(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginInMobi_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginInMobi_class->name = "PluginInMobi";
    jsb_sdkbox_PluginInMobi_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginInMobi_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginInMobi_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginInMobi_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginInMobi_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginInMobi_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginInMobi_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginInMobi_class->finalize = js_PluginInMobiJS_PluginInMobi_finalize;
    jsb_sdkbox_PluginInMobi_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("removeIdType", js_PluginInMobiJS_PluginInMobi_removeIdType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRefreshInterval", js_PluginInMobiJS_PluginInMobi_setRefreshInterval, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setInterstitialKeywords", js_PluginInMobiJS_PluginInMobi_setInterstitialKeywords, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addIdForType", js_PluginInMobiJS_PluginInMobi_addIdForType, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setIncome", js_PluginInMobiJS_PluginInMobi_setIncome, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgeGroup", js_PluginInMobiJS_PluginInMobi_setAgeGroup, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBannerKeywords", js_PluginInMobiJS_PluginInMobi_setBannerKeywords, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setHouseholdIncome", js_PluginInMobiJS_PluginInMobi_setHouseholdIncome, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setInterests", js_PluginInMobiJS_PluginInMobi_setInterests, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLogLevel", js_PluginInMobiJS_PluginInMobi_setLogLevel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginInMobiJS_PluginInMobi_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadInterstitial", js_PluginInMobiJS_PluginInMobi_loadInterstitial, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("disableHardwareAccelerationForInterstitial", js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForInterstitial, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setNationality", js_PluginInMobiJS_PluginInMobi_setNationality, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLanguage", js_PluginInMobiJS_PluginInMobi_setLanguage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGender", js_PluginInMobiJS_PluginInMobi_setGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setYearOfBirth", js_PluginInMobiJS_PluginInMobi_setYearOfBirth, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBannerAnimationType", js_PluginInMobiJS_PluginInMobi_setBannerAnimationType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAreaCode", js_PluginInMobiJS_PluginInMobi_setAreaCode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAge", js_PluginInMobiJS_PluginInMobi_setAge, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setInterstitialExtras", js_PluginInMobiJS_PluginInMobi_setInterstitialExtras, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("shouldAutoRefresh", js_PluginInMobiJS_PluginInMobi_shouldAutoRefresh, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVersion", js_PluginInMobiJS_PluginInMobi_getVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPostalCode", js_PluginInMobiJS_PluginInMobi_setPostalCode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isInterstitialReady", js_PluginInMobiJS_PluginInMobi_isInterstitialReady, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("disableHardwareAccelerationForBanner", js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForBanner, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBannerExtras", js_PluginInMobiJS_PluginInMobi_setBannerExtras, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setEthnicity", js_PluginInMobiJS_PluginInMobi_setEthnicity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadBanner", js_PluginInMobiJS_PluginInMobi_loadBanner, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setEducation", js_PluginInMobiJS_PluginInMobi_setEducation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginInMobi_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginInMobi_class,
        dummy_constructor<sdkbox::PluginInMobi>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginInMobi", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginInMobi> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginInMobi_class;
        p->proto = jsb_sdkbox_PluginInMobi_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginInMobiJS_PluginInMobi(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginInMobi_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginInMobi_class->name = "PluginInMobi";
    jsb_sdkbox_PluginInMobi_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginInMobi_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginInMobi_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginInMobi_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginInMobi_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginInMobi_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginInMobi_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginInMobi_class->finalize = js_PluginInMobiJS_PluginInMobi_finalize;
    jsb_sdkbox_PluginInMobi_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("removeIdType", js_PluginInMobiJS_PluginInMobi_removeIdType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRefreshInterval", js_PluginInMobiJS_PluginInMobi_setRefreshInterval, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setInterstitialKeywords", js_PluginInMobiJS_PluginInMobi_setInterstitialKeywords, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addIdForType", js_PluginInMobiJS_PluginInMobi_addIdForType, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setIncome", js_PluginInMobiJS_PluginInMobi_setIncome, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgeGroup", js_PluginInMobiJS_PluginInMobi_setAgeGroup, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBannerKeywords", js_PluginInMobiJS_PluginInMobi_setBannerKeywords, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setHouseholdIncome", js_PluginInMobiJS_PluginInMobi_setHouseholdIncome, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setInterests", js_PluginInMobiJS_PluginInMobi_setInterests, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLogLevel", js_PluginInMobiJS_PluginInMobi_setLogLevel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginInMobiJS_PluginInMobi_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadInterstitial", js_PluginInMobiJS_PluginInMobi_loadInterstitial, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("disableHardwareAccelerationForInterstitial", js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForInterstitial, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setNationality", js_PluginInMobiJS_PluginInMobi_setNationality, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLanguage", js_PluginInMobiJS_PluginInMobi_setLanguage, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGender", js_PluginInMobiJS_PluginInMobi_setGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setYearOfBirth", js_PluginInMobiJS_PluginInMobi_setYearOfBirth, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBannerAnimationType", js_PluginInMobiJS_PluginInMobi_setBannerAnimationType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAreaCode", js_PluginInMobiJS_PluginInMobi_setAreaCode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAge", js_PluginInMobiJS_PluginInMobi_setAge, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setInterstitialExtras", js_PluginInMobiJS_PluginInMobi_setInterstitialExtras, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("shouldAutoRefresh", js_PluginInMobiJS_PluginInMobi_shouldAutoRefresh, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVersion", js_PluginInMobiJS_PluginInMobi_getVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPostalCode", js_PluginInMobiJS_PluginInMobi_setPostalCode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isInterstitialReady", js_PluginInMobiJS_PluginInMobi_isInterstitialReady, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("disableHardwareAccelerationForBanner", js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForBanner, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBannerExtras", js_PluginInMobiJS_PluginInMobi_setBannerExtras, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setEthnicity", js_PluginInMobiJS_PluginInMobi_setEthnicity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadBanner", js_PluginInMobiJS_PluginInMobi_loadBanner, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setEducation", js_PluginInMobiJS_PluginInMobi_setEducation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginInMobi_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginInMobi_class,
        dummy_constructor<sdkbox::PluginInMobi>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginInMobi", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginInMobi> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginInMobi_class;
        p->proto = jsb_sdkbox_PluginInMobi_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginInMobiJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginInMobiJS_PluginInMobi(cx, ns);

    sdkbox::setProjectType("js");
}
#else
void register_all_PluginInMobiJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    JS::RootedValue nsval(cx);
    JS::RootedObject ns(cx);
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginInMobiJS_PluginInMobi(cx, obj);

    sdkbox::setProjectType("js");
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginInMobiJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    jsval nsval;
    JSObject *ns;
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", &nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginInMobiJS_PluginInMobi(cx, obj);

    sdkbox::setProjectType("js");
}
#endif