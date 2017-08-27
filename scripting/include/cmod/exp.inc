enum CmodExpID {
  CmodExpID_Invalid = -1,
  CmodExpID_First
};

typedef CmodLevelChangeCB = function void (CmodExpID expID, int oldLevel, int newLevel);


methodmap CmodExpID __nullable__ {
  public native CmodExpID(int maxLevel, int ratio);

  public native void remove();
  public native void Remove();

  property int exp {
    public native set(int value);
    public native get();
  }

  property int Exp {
    public native set(int value);
    public native get();
  }

  public native void setExp(int value);
  public native void SetExp(int value);

  public native int getExp(int value);
  public native int GetExp(int value);

  property int level {
    public native set(int value);
    public native get();
  }

  property int Level {
    public native set(int value);
    public native get();
  }

  public native void setLevel(int value);
  public native void SetLevel(int value);

  public native int getLevel();
  public native int GetLevel();

  property int maxLevel {
    public native set(int value);
    public native get();
  }

  property int MaxLevel {
    public native set(int value);
    public native get();
  }

  public native void setMaxLevel(int value);
  public native void SetMaxLevel(int value);

  public native int getMaxLevel();
  public native int GetMaxLevel();

  property int ratio {
    public native set(int value);
    public native get();
  }

  property int Ratio {
    public native set(int value);
    public native get();
  }

  public native void setRatio(int value);
  public native void SetRatio(int value);

  public native int getRatio();
  public native int GetRatio();

  public native void check();
  public native void Check();

  public native void hookLevelChange(CmodLevelChangeCB cb);
  public native void HookLevelChange(CmodLevelChangeCB cb);

  public native void unhookLevelChange(CmodLevelChangeCB cb);
  public native void UnhookLevelChange(CmodLevelChangeCB cb);
};

native CmodExpID Cmod_createExpSys(int maxLevel, int ratio);
native CmodExpID Cmod_CreateExpSys(int maxLevel, int ratio);

native void Cmod_removeExpSys(CmodExpID expID);
native void Cmod_RemoveExpSys(CmodExpID expID);

native void Cmod_setExp(CmodExpID expID, int value);
native void Cmod_SetExp(CmodExpID expID, int value);

native int Cmod_getExp(CmodExpID expID);
native int Cmod_GetExp(CmodExpID expID);

native void Cmod_setLevel(CmodExpID expID, int value);
native void Cmod_SetLevel(CmodExpID expID, int value);

native int Cmod_getLevel(CmodExpID expID);
native int Cmod_GetLevel(CmodExpID expID);

native void Cmod_setMaxLevel(CmodExpID expID, int value);
native void Cmod_SetMaxLevel(CmodExpID expID, int value);

native int Cmod_getMaxLevel(CmodExpID expID);
native int Cmod_GetMaxLevel(CmodExpID expID);

native void Cmod_setRatio(CmodExpID expID, int value);
native void Cmod_SetRatio(CmodExpID expID, int value);

native int Cmod_getRatio(CmodExpID expID);
native int Cmod_GetRatio(CmodExpID expID);

native void Cmod_checkExp(CmodExpID expID);
native void Cmod_CheckExp(CmodExpID expID);

native void Cmod_hookLevelChange(CmodExpID expID, CmodLevelChangeCB cb);
native void Cmod_HookLevelChange(CmodExpID expID, CmodLevelChangeCB cb);

native void Cmod_unhookLevelChange(CmodExpID expID, CmodLevelChangeCB cb);
native void Cmod_UnhookLevelChange(CmodExpID expID, CmodLevelChangeCB cb);

native int Cmod_getExpForLevelUp(CmodExpID expID);
native int Cmod_GetExpForLevelUp(CmodExpID expID);
