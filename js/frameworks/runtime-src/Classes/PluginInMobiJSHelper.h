

#ifndef __js__PluginInMobiJSHelper_H_
#define __js__PluginInMobiJSHelper_H_

#include "jsapi.h"
#include "jsfriendapi.h"

#if MOZJS_MAJOR_VERSION >= 31
void register_all_PluginInMobiJS_helper(JSContext* cx, JS::HandleObject global);
#else
void register_all_PluginInMobiJS_helper(JSContext* cx, JSObject* global);
#endif

#endif /* defined(__PluginInMobiJSHelper_H_) */
