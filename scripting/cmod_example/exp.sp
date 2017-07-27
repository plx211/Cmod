#include <sourcemod>
#include <cmod>

const int EXP_PER_KILL = 100;

static CmodModuleID module;
static CmodExpID exp;

public void OnPluginStart() {
  module = new CmodModuleID("exp_example");
  module.hookEnable(onModuleEnable);
  module.hookDisable(onModuleDisable);
  module.addReq("expcore");
  module.setReady();
}


public void onModuleEnable(CmodModuleID moduleID, const char[] name) {
  HookEvent("player_death", onPlayerDeath);
  exp = new CmodExpID(100, 35);
  exp.hookLevelChange(onLevelChange);
}

public void onModuleDisable(CmodModuleID moduleID, const char[] name) {
  UnhookEvent("player_death", onPlayerDeath);
}

public void onLevelChange(CmodExpID expID, int oldLevel, int newLevel) {
  PrintToChatAll("Level UP! New level %d", newLevel);
}

public Action onPlayerDeath(Event event, const char[] name, bool dontBroadcast) {
  exp.exp += EXP_PER_KILL;
}
