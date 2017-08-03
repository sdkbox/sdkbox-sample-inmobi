#ifndef __PluginInMobiJS_h__
#define __PluginInMobiJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginInMobiJS_PluginInMobi(JSContext *cx, JS::HandleObject global);
void register_all_PluginInMobiJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginInMobiJS_PluginInMobi(JSContext *cx, JSObject* global);
void register_all_PluginInMobiJS(JSContext* cx, JSObject* obj);
#endif
#endif

