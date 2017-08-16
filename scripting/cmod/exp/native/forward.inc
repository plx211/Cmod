void ForwardNative_init() {
  CreateNative("Cmod_hookLevelChange", Forward_hookLevelChange);
  CreateNative("Cmod_HookLevelChange", Forward_hookLevelChange);
  CreateNative("CmodExpID.hookLevelChange", Forward_hookLevelChange);
  CreateNative("CmodExpID.HookLevelChange", Forward_hookLevelChange);

  CreateNative("Cmod_unhookLevelChange", Forward_unhookLevelChange);
  CreateNative("Cmod_UnhookLevelChange", Forward_unhookLevelChange);
  CreateNative("CmodExpID.unhookLevelChange", Forward_unhookLevelChange);
  CreateNative("CmodExpID.UnhookLevelChange", Forward_unhookLevelChange);
}

public int Forward_hookLevelChange(Handle plugin, int numParams) {
  SlotID slotID = GetNativeCell(1);
  Function cb = GetNativeCell(2);
  Forward_getLevelChangeForward(slotID).hook(plugin, cb);
}

public int Forward_unhookLevelChange(Handle plugin, int numParams) {
  SlotID slotID = GetNativeCell(1);
  Function cb = GetNativeCell(2);
  Forward_getLevelChangeForward(slotID).unhook(plugin, cb);
}
