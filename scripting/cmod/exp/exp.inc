enum ExpArrayPosition {
  ExpArrayPosition_Ratio,
  ExpArrayPosition_MaxLevel,
  ExpArrayPosition_Level,
  ExpArrayPosition_Exp,
  ExpArrayPosition_Count
};

static ArrayList data;

void Exp_init() {
  data = new ArrayList(view_as<int>(ExpArrayPosition_Count));
}

void Exp_setRatio(SlotID slotID, int ratio) {
  data.Set(view_as<int>(slotID), ratio, view_as<int>(ExpArrayPosition_Ratio));
}

int Exp_getRatio(SlotID slotID) {
  return data.Get(view_as<int>(slotID), view_as<int>(ExpArrayPosition_Ratio));
}

void Exp_setMaxLevel(SlotID slotID, int maxLevel) {
  data.Set(view_as<int>(slotID), maxLevel, view_as<int>(ExpArrayPosition_MaxLevel));
}

int Exp_getMaxLevel(SlotID slotID) {
  return data.Get(view_as<int>(slotID), view_as<int>(ExpArrayPosition_MaxLevel));
}

void Exp_setLevel(SlotID slotID, int level) {
  data.Set(view_as<int>(slotID), level, view_as<int>(ExpArrayPosition_Level));
}

int Exp_getLevel(SlotID slotID) {
  return data.Get(view_as<int>(slotID), view_as<int>(ExpArrayPosition_Level));
}

void Exp_setExp(SlotID slotID, int exp) {
  data.Set(view_as<int>(slotID), exp, view_as<int>(ExpArrayPosition_Exp));
}

int Exp_getExp(SlotID slotID) {
  return data.Get(view_as<int>(slotID), view_as<int>(ExpArrayPosition_Exp));
}

int Exp_getExpForLevelUp(SlotID slotID) {
  int level = Exp_getLevel(slotID);
  int ratio = Exp_getRatio(slotID);
  return level * level * ratio;
}

void Exp_check(SlotID slotID) {
  int level = Exp_getLevel(slotID);
  int nextLevel = level;
  int maxLevel = Exp_getMaxLevel(slotID);

  while (Exp_getExp(slotID) > Exp_getExpForLevelUp(slotID) && nextLevel < maxLevel) {
    Exp_setLevel(slotID, ++nextLevel);
  }

  if (level != nextLevel) {
    onLevelChange(slotID, level, nextLevel);
  }
}

SlotID Exp_create(int maxLevel, int ratio) {
  SlotID slotID = SlotManager_createSlot();

  if (view_as<int>(slotID) >= data.Length) {
    data.Resize(view_as<int>(slotID) + 1);
  }

  Exp_setLevel(slotID, 1);
  Exp_setExp(slotID, 0);
  Exp_setMaxLevel(slotID, maxLevel);
  Exp_setRatio(slotID, ratio);

  onExpIDCreate(slotID);

  return slotID;
}

void Exp_remove(SlotID slotID) {
  SlotManager_removeSlot(slotID);
  onExpIDRemove(slotID);
}

int Exp_getSlotCount() {
  return SlotManager_getSlotArray().Length;
}
