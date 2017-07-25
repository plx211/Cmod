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
  data = new ArrayList(ExpArrayPosition_Count);
}

void Exp_setSlotStatus(ExpID expID, SlotStatus status) {
  data.Set(expID, status, ExpArrayPosition_SlotStatus);
}

SlotStatus Exp_getSlotStatus(ExpID expID) {
  return data.Get(expID, ExpArrayPosition_SlotStatus);
}

void Exp_setRatio(ExpID expID, int ratio) {
  data.Set(expID, ratio, ExpArrayPosition_Ratio);
}

int Exp_getRatio(ExpID expID) {
  return data.Get(expID, ExpArrayPosition_Ratio);
}

void Exp_setMaxLevel(ExpID expID, int maxLevel) {
  data.Set(expID, maxLevel, ExpArrayPosition_MaxLevel);
}

int Exp_getMaxLevel(ExpID expID) {
  return data.Get(expID, ExpArrayPosition_MaxLevel);
}

void Exp_setLevel(ExpID expID, int level) {
  data.Set(expID, level, ExpArrayPosition_Level);
}

int Exp_getLevel(ExpID expID) {
  return data.Get(expID, ExpArrayPosition_Level);
}

void Exp_setExp(ExpID expID, int exp) {
  data.Set(expID, exp, ExpArrayPosition_Exp);
}

int Exp_getExp(ExpID expID) {
  return data.Get(expID, ExpArrayPosition_Exp);
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
  ExpID expID = data.FindValue(SlotStatus_Free, ExpArrayPosition_SlotStatus);

  if (expID == ExpID_Invalid) {
    expID = data.Push(SlotStatus_Free);
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
