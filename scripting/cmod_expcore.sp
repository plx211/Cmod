#include <sourcemod>
#include <cmod>

#include "cmod/helper/forward"
#include "cmod/helper/forward_array"

#include "cmod/exp/exp"
#include "cmod/exp/forward/level_change"
#include "cmod/exp/forward"

static CmodModuleID module;

public void OnPluginStart() {
  module = new CmodModuleID("exp_core");
  module.setReady();

  Exp_init();
  Forward_init();
}

public void OnPluginEnd() {
  module.remove();
}

public void onLevelChange(ExpID expID, int oldLevel, int newLevel) {
  Forward_onLevelChange(expID, oldLevel, newLevel);
}
