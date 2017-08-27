void ExpNative_init() {
  CreateNative("Cmod_createExpSys", ExpNative_create);
  CreateNative("Cmod_CreateExpSys", ExpNative_create);
  CreateNative("CmodExpID.CmodExpID", ExpNative_create);

  CreateNative("Cmod_removeExpSys", ExpNative_remove);
  CreateNative("Cmod_RemoveExpSys", ExpNative_remove);
  CreateNative("CmodExpID.remove", ExpNative_remove);
  CreateNative("CmodExpID.Remove", ExpNative_remove);

  CreateNative("Cmod_setExp", ExpNative_setExp);
  CreateNative("Cmod_SetExp", ExpNative_setExp);
  CreateNative("CmodExpID.setExp", ExpNative_setExp);
  CreateNative("CmodExpID.SetExp", ExpNative_setExp);
  CreateNative("CmodExpID.exp.set", ExpNative_setExp);
  CreateNative("CmodExpID.Exp.set", ExpNative_setExp);

  CreateNative("Cmod_getExp", ExpNative_getExp);
  CreateNative("Cmod_GetExp", ExpNative_getExp);
  CreateNative("CmodExpID.getExp", ExpNative_getExp);
  CreateNative("CmodExpID.GetExp", ExpNative_getExp);
  CreateNative("CmodExpID.exp.get", ExpNative_getExp);
  CreateNative("CmodExpID.Exp.get", ExpNative_getExp);

  CreateNative("Cmod_setLevel", ExpNative_setLevel);
  CreateNative("Cmod_SetLevel", ExpNative_setLevel);
  CreateNative("CmodExpID.setLevel", ExpNative_setLevel);
  CreateNative("CmodExpID.SetLevel", ExpNative_setLevel);
  CreateNative("CmodExpID.level.set", ExpNative_setLevel);
  CreateNative("CmodExpID.Level.set", ExpNative_setLevel);

  CreateNative("Cmod_getLevel", ExpNative_getLevel);
  CreateNative("Cmod_GetLevel", ExpNative_getLevel);
  CreateNative("CmodExpID.getLevel", ExpNative_getLevel);
  CreateNative("CmodExpID.GetLevel", ExpNative_getLevel);
  CreateNative("CmodExpID.level.get", ExpNative_getLevel);
  CreateNative("CmodExpID.Level.get", ExpNative_getLevel);

  CreateNative("Cmod_setMaxLevel", ExpNative_setMaxLevel);
  CreateNative("Cmod_SetMaxLevel", ExpNative_setMaxLevel);
  CreateNative("CmodExpID.setMaxLevel", ExpNative_setMaxLevel);
  CreateNative("CmodExpID.SetMaxLevel", ExpNative_setMaxLevel);
  CreateNative("CmodExpID.maxLevel.set", ExpNative_setMaxLevel);
  CreateNative("CmodExpID.MaxLevel.set", ExpNative_setMaxLevel);

  CreateNative("Cmod_getMaxLevel", ExpNative_getMaxLevel);
  CreateNative("Cmod_GetMaxLevel", ExpNative_getMaxLevel);
  CreateNative("CmodExpID.getMaxLevel", ExpNative_getMaxLevel);
  CreateNative("CmodExpID.GetMaxLevel", ExpNative_getMaxLevel);
  CreateNative("CmodExpID.maxLevel.get", ExpNative_getMaxLevel);
  CreateNative("CmodExpID.MaxLevel.get", ExpNative_getMaxLevel);

  CreateNative("Cmod_setRatio", ExpNative_setRatio);
  CreateNative("Cmod_SetRatio", ExpNative_setRatio);
  CreateNative("CmodExpID.setRatio", ExpNative_setRatio);
  CreateNative("CmodExpID.SetRatio", ExpNative_setRatio);
  CreateNative("CmodExpID.ratio.set", ExpNative_setRatio);
  CreateNative("CmodExpID.Ratio.set", ExpNative_setRatio);

  CreateNative("Cmod_getRatio", ExpNative_getRatio);
  CreateNative("Cmod_GetRatio", ExpNative_getRatio);
  CreateNative("CmodExpID.getRatio", ExpNative_getRatio);
  CreateNative("CmodExpID.GetRatio", ExpNative_getRatio);
  CreateNative("CmodExpID.ratio.get", ExpNative_getRatio);
  CreateNative("CmodExpID.Ratio.get", ExpNative_getRatio);

  CreateNative("Cmod_checkExp", ExpNative_check);
  CreateNative("Cmod_CheckExp", ExpNative_check);
  CreateNative("CmodExpID.check", ExpNative_check);
  CreateNative("CmodExpID.Check", ExpNative_check);

  CreateNative("Cmod_getExpForLevelUp", ExpNative_getExpForLevelUp);
  CreateNative("Cmod_GetExpForLevelUp", ExpNative_getExpForLevelUp);
}

public int ExpNative_create(Handle plugin, int numParams) {
  int maxLevel = GetNativeCell(1);
  int ratio = GetNativeCell(2);
  return view_as<int>(Exp_create(maxLevel, ratio));
}

public int ExpNative_remove(Handle plugin, int numParams) {
  SlotID slotID = GetNativeCell(1);
  Exp_remove(slotID);
}

public int ExpNative_setExp(Handle plugin, int numParams) {
  SlotID slotID = GetNativeCell(1);
  int value = GetNativeCell(2);
  Exp_setExp(slotID, value);
}

public int ExpNative_getExp(Handle plugin, int numParams) {
  SlotID slotID = GetNativeCell(1);
  return Exp_getExp(slotID);
}

public int ExpNative_setLevel(Handle plugin, int numParams) {
  SlotID slotID = GetNativeCell(1);
  int value = GetNativeCell(2);
  Exp_setLevel(slotID, value);
}

public int ExpNative_getLevel(Handle plugin, int numParams) {
  SlotID slotID = GetNativeCell(1);
  return Exp_getLevel(slotID);
}

public int ExpNative_setMaxLevel(Handle plugin, int numParams) {
  SlotID slotID = GetNativeCell(1);
  int value = GetNativeCell(2);
  Exp_setMaxLevel(slotID, value);
}

public int ExpNative_getMaxLevel(Handle plugin, int numParams) {
  SlotID slotID = GetNativeCell(1);
  return Exp_getMaxLevel(slotID);
}

public int ExpNative_setRatio(Handle plugin, int numParams) {
  SlotID slotID = GetNativeCell(1);
  int value = GetNativeCell(2);
  Exp_setRatio(slotID, value);
}

public int ExpNative_getRatio(Handle plugin, int numParams) {
  SlotID slotID = GetNativeCell(1);
  return Exp_getRatio(slotID);
}

public int ExpNative_check(Handle plugin, int numParams) {
  SlotID slotID = GetNativeCell(1);
  Exp_check(slotID);
}

public int ExpNative_getExpForLevelUp(Handle plugin, int numParams) {
  SlotID slotID = GetNativeCell(1);
  return view_as<int>(Exp_getExpForLevelUp(slotID));
}
