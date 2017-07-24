#include <sourcemod>
#include <cmod>

CmodModuleID module;

public void OnPluginStart() {
  module = new CmodModuleID("example_module");
  module.hookEnable(onModuleEnable);
  module.hookDisable(onModuleDisable);
  module.setReady();
}

public void OnPluginEnd() {
  module.remove();
}

public void onModuleEnable(CmodModuleID moduleID, const char[] name) {
  PrintToServer("[EXAMPLE][Module enable] moduleID = %d name = \"%s\"", moduleID, name);
}

public void onModuleDisable(CmodModuleID moduleID, const char[] name) {
  PrintToServer("[EXAMPLE][Module disable] moduleID = %d name = \"%s\"", moduleID, name);
}
