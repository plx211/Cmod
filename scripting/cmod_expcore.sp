#include <sourcemod>
#include <cmod>

#tryinclude "cmod/version"
#tryinclude "cmod/test"

#include "cmod/helper/forward"
#include "cmod/helper/forward_array"
#include "cmod/helper/slot_manager/slot_id"
#include "cmod/helper/slot_manager/slot_status"
#include "cmod/helper/slot_manager/slot_manager"

#include "cmod/exp/exp"
#include "cmod/exp/forward/level_change"
#include "cmod/exp/forward"

#include "cmod/exp/native/exp"
#include "cmod/exp/native/forward"

#if defined TEST
  #include "cmod/exp/test/exp"
#endif

static CmodModuleID module;

public void OnPluginStart() {
  module = new CmodModuleID("expcore");
  module.setReady();

  SlotManager_init();
  Exp_init();
  Forward_init();

  #if defined TEST
    ExpTest_init();
  #endif
}

public void OnPluginEnd() {
  module.remove();
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  ExpNative_init();
  ForwardNative_init();
  return APLRes_Success;
}

public void onExpIDCreate(SlotID slotID) {
  Forward_onExpIDCreate(slotID);
}

public void onExpIDRemove(SlotID slotID) {
  Forward_onExpIDRemove(slotID);
}

public void onLevelChange(SlotID slotID, int oldLevel, int newLevel) {
  Forward_onLevelChange(slotID, oldLevel, newLevel);
}
