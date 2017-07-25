#include <sourcemod>
#include <cmod>

#tryinclude "cmod/version"
#tryinclude "cmod/test"

#include "cmod/helper/forward"
#include "cmod/helper/forward_array"

#include "cmod/exp/exp"
#include "cmod/exp/forward/level_change"
#include "cmod/exp/forward"

#if defined TEST
  #include "cmod/exp/test/exp"
#endif

static CmodModuleID module;

public void OnPluginStart() {
  module = new CmodModuleID("exp_core");
  module.setReady();

  Exp_init();
  Forward_init();

  #if defined TEST
    ExpTest_init();
  #endif
}

public void OnPluginEnd() {
  module.remove();
}

public void onLevelChange(ExpID expID, int oldLevel, int newLevel) {
  Forward_onLevelChange(expID, oldLevel, newLevel);
}
