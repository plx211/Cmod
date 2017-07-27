enum SlotStatus {
  SlotStatus_Free,
  SlotStatus_Use
};

enum ExpArrayPosition {
  ExpArrayPosition_SlotStatus,
  ExpArrayPosition_Ratio,
  ExpArrayPosition_MaxLevel,
  ExpArrayPosition_Level,
  ExpArrayPosition_Exp,
  ExpArrayPosition_Count
};

enum ExpID {
  ExpID_Invalid = -1,
  ExpID_First
};

static ArrayList data;

void Exp_init() {
  data = new ArrayList(view_as<int>(ExpArrayPosition_Count));
}

void Exp_setSlotStatus(ExpID expID, SlotStatus status) {
  data.Set(view_as<int>(expID), status, view_as<int>(ExpArrayPosition_SlotStatus));
}

SlotStatus Exp_getSlotStatus(ExpID expID) {
  return data.Get(view_as<int>(expID), view_as<int>(ExpArrayPosition_SlotStatus));
}

void Exp_setRatio(ExpID expID, int ratio) {
  data.Set(view_as<int>(expID), ratio, view_as<int>(ExpArrayPosition_Ratio));
}

int Exp_getRatio(ExpID expID) {
  return data.Get(view_as<int>(expID), view_as<int>(ExpArrayPosition_Ratio));
}

void Exp_setMaxLevel(ExpID expID, int maxLevel) {
  data.Set(view_as<int>(expID), maxLevel, view_as<int>(ExpArrayPosition_MaxLevel));
}

int Exp_getMaxLevel(ExpID expID) {
  return data.Get(view_as<int>(expID), view_as<int>(ExpArrayPosition_MaxLevel));
}

void Exp_setLevel(ExpID expID, int level) {
  data.Set(view_as<int>(expID), level, view_as<int>(ExpArrayPosition_Level));
}

int Exp_getLevel(ExpID expID) {
  return data.Get(view_as<int>(expID), view_as<int>(ExpArrayPosition_Level));
}

void Exp_setExp(ExpID expID, int exp) {
  data.Set(view_as<int>(expID), exp, view_as<int>(ExpArrayPosition_Exp));
}

int Exp_getExp(ExpID expID) {
  return data.Get(view_as<int>(expID), view_as<int>(ExpArrayPosition_Exp));
}

int Exp_getExpForLevelUp(ExpID expID) {
  int level = Exp_getLevel(expID);
  int ratio = Exp_getRatio(expID);
  return level * level * ratio;
}

void Exp_check(ExpID expID) {
  int level = Exp_getLevel(expID);
  int nextLevel = level;
  int maxLevel = Exp_getMaxLevel(expID);

  while (Exp_getExp(expID) > Exp_getExpForLevelUp(expID) && nextLevel < maxLevel) {
    Exp_setLevel(expID, ++nextLevel);
  }

  if (level != nextLevel) {
    onLevelChange(expID, level, nextLevel);
  }
}

ExpID Exp_getFreeSlot() {
  ExpID expID = view_as<ExpID>(data.FindValue(SlotStatus_Free, view_as<int>(ExpArrayPosition_SlotStatus)));

  if (expID == ExpID_Invalid) {
    expID = view_as<ExpID>(data.Push(SlotStatus_Free));
  }

  return expID;
}

ExpID Exp_create(int maxLevel, int ratio) {
  ExpID expID = Exp_getFreeSlot();

  Exp_setSlotStatus(expID, SlotStatus_Use);
  Exp_setLevel(expID, 1);
  Exp_setExp(expID, 0);
  Exp_setMaxLevel(expID, maxLevel);
  Exp_setRatio(expID, ratio);

  onExpIDCreate(expID);

  return expID;
}

void Exp_remove(ExpID expID) {
  Exp_setSlotStatus(expID, SlotStatus_Free);
  onExpIDRemove(expID);
}

int Exp_getSlotCount() {
  return data.Length;
}
