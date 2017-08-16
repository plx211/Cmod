void ExpTest_init() {
  RegServerCmd("test_cmod_expcore_print", ExpTestCmd_print);
  RegServerCmd("test_cmod_expcore_create", ExpTestCmd_create);
  RegServerCmd("test_cmod_expcore_set_level", ExpTestCmd_setLevel);
  RegServerCmd("test_cmod_expcore_set_exp", ExpTestCmd_setExp);
  RegServerCmd("test_cmod_expcore_set_max_level", ExpTestCmd_setMaxLevel);
  RegServerCmd("test_cmod_expcore_set_ratio", ExpTestCmd_setRatio);
  RegServerCmd("test_cmod_expcore_check", ExpTestCmd_check);
  RegServerCmd("test_cmod_expcore_remove", ExpTestCmd_remove);
}

public Action ExpTestCmd_print(int argc) {
  int count = Exp_getSlotCount();
  PrintToServer("Slot count = %d", count);
  for (SlotID slotID = SlotID_First; slotID < view_as<SlotID>(count); ++slotID) {
    PrintToServer("---------------------");
    PrintToServer("Slot status: %d", SlotManager_getSlotStatus(slotID));
    PrintToServer("Level: %d", Exp_getLevel(slotID));
    PrintToServer("Exp: %d", Exp_getExp(slotID));
    PrintToServer("Max level: %d", Exp_getMaxLevel(slotID));
    PrintToServer("Ratio: %d", Exp_getRatio(slotID));
    PrintToServer("Exp to levelup: %d", Exp_getExpForLevelUp(slotID));
  }
}

public Action ExpTestCmd_create(int argc) {
  PrintToServer("slotID = %d", Exp_create(200, 35));
}

public Action ExpTestCmd_setLevel(int argc) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  SlotID slotID = view_as<SlotID>(StringToInt(buffer));
  GetCmdArg(2, buffer, sizeof(buffer));
  int value = StringToInt(buffer);
  Exp_setLevel(slotID, value);
}

public Action ExpTestCmd_setExp(int argc) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  SlotID slotID = view_as<SlotID>(StringToInt(buffer));
  GetCmdArg(2, buffer, sizeof(buffer));
  int value = StringToInt(buffer);
  Exp_setExp(slotID, value);
}

public Action ExpTestCmd_setMaxLevel(int argc) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  SlotID slotID = view_as<SlotID>(StringToInt(buffer));
  GetCmdArg(2, buffer, sizeof(buffer));
  int value = StringToInt(buffer);
  Exp_setMaxLevel(slotID, value);
}

public Action ExpTestCmd_setRatio(int argc) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  SlotID slotID = view_as<SlotID>(StringToInt(buffer));
  GetCmdArg(2, buffer, sizeof(buffer));
  int value = StringToInt(buffer);
  Exp_setRatio(slotID, value);
}

public Action ExpTestCmd_check(int argc) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  SlotID slotID = view_as<SlotID>(StringToInt(buffer));
  Exp_check(slotID);
}

public Action ExpTestCmd_remove(int argc) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  SlotID slotID = view_as<SlotID>(StringToInt(buffer));
  Exp_remove(slotID);
}
