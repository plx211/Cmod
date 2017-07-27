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
  for (ExpID expID = ExpID_First; expID < view_as<ExpID>(count); ++expID) {
    PrintToServer("---------------------");
    PrintToServer("Slot status: %d", Exp_getSlotStatus(expID));
    PrintToServer("Level: %d", Exp_getLevel(expID));
    PrintToServer("Exp: %d", Exp_getExp(expID));
    PrintToServer("Max level: %d", Exp_getMaxLevel(expID));
    PrintToServer("Ratio: %d", Exp_getRatio(expID));
    PrintToServer("Exp to levelup: %d", Exp_getExpForLevelUp(expID));
  }
}

public Action ExpTestCmd_create(int argc) {
  PrintToServer("expID = %d", Exp_create(200, 35));
}

public Action ExpTestCmd_setLevel(int argc) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  ExpID expID = view_as<ExpID>(StringToInt(buffer));
  GetCmdArg(2, buffer, sizeof(buffer));
  int value = StringToInt(buffer);
  Exp_setLevel(expID, value);
}

public Action ExpTestCmd_setExp(int argc) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  ExpID expID = view_as<ExpID>(StringToInt(buffer));
  GetCmdArg(2, buffer, sizeof(buffer));
  int value = StringToInt(buffer);
  Exp_setExp(expID, value);
}

public Action ExpTestCmd_setMaxLevel(int argc) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  ExpID expID = view_as<ExpID>(StringToInt(buffer));
  GetCmdArg(2, buffer, sizeof(buffer));
  int value = StringToInt(buffer);
  Exp_setMaxLevel(expID, value);
}

public Action ExpTestCmd_setRatio(int argc) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  ExpID expID = view_as<ExpID>(StringToInt(buffer));
  GetCmdArg(2, buffer, sizeof(buffer));
  int value = StringToInt(buffer);
  Exp_setRatio(expID, value);
}

public Action ExpTestCmd_check(int argc) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  ExpID expID = view_as<ExpID>(StringToInt(buffer));
  Exp_check(expID);
}

public Action ExpTestCmd_remove(int argc) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  ExpID expID = view_as<ExpID>(StringToInt(buffer));
  Exp_remove(expID);
}
