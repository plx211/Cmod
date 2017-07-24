enum CmodModuleID {
  CmodModuleID_Invalid = -1,
  CmodModuleID_First
};

enum CmodModuleStatus {
  CmodModuleStatus_FreeSlot = 0,
  CmodModuleStatus_Prepare,
  CmodModuleStatus_ReadyToCheck,
  CmodModuleStatus_Enable
};

typedef CmodModuleEnableCB = function void (CmodModuleID module, const char[] name);

typedef CmodModuleDisableCB = function void (CmodModuleID module, const char[] name);

methodmap CmodModuleID __nullable__ {
  public native CmodModuleID(const char[] name);

  public native void getName(char[] buffer, int size);
  public native void GetName(char[] buffer, int size);

  public native CmodModuleStatus getStatus();
  public native CmodModuleStatus GetStatus();

  public native void remove();
  public native void Remove();

  public native void addReq(const char[] req);
  public native void AddReq(const char[] req);

  public native void setReady();
  public native void SetReady();

  public native void hookEnable(CmodModuleEnableCB cb);
  public native void HookEnable(CmodModuleEnableCB cb);

  public native void unhookEnable(CmodModuleEnableCB cb);
  public native void UnhookEnable(CmodModuleEnableCB cb);

  public native void hookDisable(CmodModuleDisableCB cb);
  public native void HookDisable(CmodModuleDisableCB cb);

  public native void unhookDisable(CmodModuleDisableCB cb);
  public native void UnhookDisable(CmodModuleDisableCB cb);
};

native CmodModuleID Cmod_createModule(const char[] name);
native CmodModuleID Cmod_CreateModule(const char[] name);

native void Cmod_getModuleName(CmodModuleID module, char[] buffer, int size);
native void Cmod_GetModuleName(CmodModuleID module, char[] buffer, int size);

native CmodModuleStatus Cmod_getModuleStatus(CmodModuleID module);
native CmodModuleStatus Cmod_GetModuleStatus(CmodModuleID module);

native CmodModuleID Cmod_findModuleID(const char[] name);
native CmodModuleID Cmod_FindModuleID(const char[] name);

native void Cmod_removeModule(CmodModuleID module);
native void Cmod_RemoveModule(CmodModuleID module);

native int Cmod_getModuleSlotCount();
native int Cmod_GetModuleSlotCount();

native void Cmod_addModuleReq(CmodModuleID module, const char[] req);
native void Cmod_AddModuleReq(CmodModuleID module, const char[] req);

native void Cmod_setModuleReady(CmodModuleID module);
native void Cmod_SetModuleReady(CmodModuleID module);

native void Cmod_hookModuleEnable(CmodModuleID module, CmodModuleEnableCB cb);
native void Cmod_HookModuleEnable(CmodModuleID module, CmodModuleEnableCB cb);

native void Cmod_unhookModuleEnable(CmodModuleID module, CmodModuleEnableCB cb);
native void Cmod_UnhookModuleEnable(CmodModuleID module, CmodModuleEnableCB cb);

native void Cmod_hookModuleDisable(CmodModuleID module, CmodModuleDisableCB cb);
native void Cmod_HookModuleDisable(CmodModuleID module, CmodModuleDisableCB cb);

native void Cmod_unhookModuleDisable(CmodModuleID module, CmodModuleDisableCB cb);
native void Cmod_UnhookModuleDisable(CmodModuleID module, CmodModuleDisableCB cb);
