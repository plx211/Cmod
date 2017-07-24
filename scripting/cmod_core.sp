#include <sourcemod>

#tryinclude "cmod/version"
#tryinclude "cmod/test"

#include "cmod/helper/forward"
#include "cmod/helper/forward_array"

#include "cmod/core/module"
#include "cmod/core/req"
#include "cmod/core/forward/module_disable"
#include "cmod/core/forward/module_enable"
#include "cmod/core/forward"

#if defined TEST
  #include "cmod/core/test/module"
  #include "cmod/core/test/req"
#endif

#include "cmod/core/native/module"
#include "cmod/core/native/req"
#include "cmod/core/native/forward"

public void OnPluginStart() {
  Module_init();
  Req_init();
  Forward_init();

  #if defined TEST
    ModuleTest_init();
    ReqTest_init();
  #endif
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  ModuleNative_init();
  ReqNative_init();
  ForwardNative_init();
  return APLRes_Success;
}

public void onModuleCreate(ModuleID module, const char[] name) {
  Forward_onModuleCreate(module);
  Req_onModuleCreate(module);

  #if defined TEST
    ModuleTest_onModuleCreate(module, name);
  #endif
}

public void onModuleEnable(ModuleID module, const char[] name) {
  Forward_onModuleEnable(module, name);
  Req_onModuleEnable();

  #if defined TEST
    ModuleTest_onModuleEnable(module, name);
  #endif
}

public void onModuleRemove(ModuleID module, const char[] name) {
  Forward_onModuleRemove(module, name);
  Req_onModuleRemove(module);

  #if defined TEST
    ModuleTest_onModuleRemove(module, name);
  #endif
}

public void onModuleDisable(ModuleID module, const char[] name) {
  Forward_onModuleDisable(module, name);
  Req_onModuleDisable();

  #if defined TEST
    ModuleTest_onModuleDisable(module, name);
  #endif
}
