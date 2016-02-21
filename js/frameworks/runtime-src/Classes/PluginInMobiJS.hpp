#ifndef __PluginInMobiJS_h__
#define __PluginInMobiJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginInMobi_class;
extern JSObject *jsb_sdkbox_PluginInMobi_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginInMobiJS_PluginInMobi(JSContext *cx, JS::HandleObject global);
void register_all_PluginInMobiJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginInMobiJS_PluginInMobi(JSContext *cx, JSObject* global);
void register_all_PluginInMobiJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginInMobiJS_PluginInMobi_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginInMobiJS_PluginInMobi_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_removeIdType(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_removeIdType(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setRefreshInterval(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setRefreshInterval(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setInterstitialKeywords(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setInterstitialKeywords(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_addIdForType(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_addIdForType(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setIncome(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setIncome(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setAgeGroup(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setAgeGroup(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setBannerKeywords(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setBannerKeywords(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setHouseholdIncome(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setHouseholdIncome(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setInterests(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setInterests(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setLogLevel(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setLogLevel(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_loadInterstitial(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_loadInterstitial(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForInterstitial(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForInterstitial(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setNationality(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setNationality(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setLanguage(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setLanguage(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setGender(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setGender(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setYearOfBirth(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setYearOfBirth(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setBannerAnimationType(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setBannerAnimationType(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setAreaCode(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setAreaCode(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setAge(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setAge(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setInterstitialExtras(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setInterstitialExtras(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_shouldAutoRefresh(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_shouldAutoRefresh(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_getVersion(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_getVersion(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setPostalCode(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setPostalCode(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_isInterstitialReady(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_isInterstitialReady(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForBanner(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_disableHardwareAccelerationForBanner(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setBannerExtras(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setBannerExtras(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setEthnicity(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setEthnicity(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_loadBanner(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_loadBanner(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginInMobiJS_PluginInMobi_setEducation(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginInMobiJS_PluginInMobi_setEducation(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

