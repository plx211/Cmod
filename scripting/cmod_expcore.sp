#include <sourcemod>
#include <cmod>

#include "cmod/exp/exp"

static CmodModuleID module;

public void OnPluginStart() {
  module = new CmodModuleID("exp_core");
  module.setReady();
}

public void OnPluginEnd() {
  module.remove();
}
