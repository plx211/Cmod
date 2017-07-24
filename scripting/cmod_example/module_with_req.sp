#include <sourcemod>
#include <cmod>

CmodModuleID module;

public void OnPluginStart() {
  module = new CmodModuleID("example_module_with_req");
  module.hookEnable(onModuleEnable);
  module.hookDisable(onModuleDisable);
  module.addReq("menu");
  module.addReq("database");
  module.addReq("skill[fire]");
  module.addReq("stats[dex]")
  module.setReady();
}

public void OnPluginEnd() {
  module.remove();
}

public void onModuleEnable(CmodModuleID moduleID, const char[] name) {
  CmodModuleID examplModule = Cmod_findModuleID("example_module");
  PrintToServer("[EXAMPLE][Module_with_req enable] moduleID = %d name = \"%s\"", moduleID, name);
}

public void onModuleDisable(CmodModuleID moduleID, const char[] name) {
  PrintToServer("[EXAMPLE][Module_with_req disable] moduleID = %d name = \"%s\"", moduleID, name);
}
