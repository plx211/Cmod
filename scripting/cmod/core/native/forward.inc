void ForwardNative_init() {
  CreateNative("Cmod_hookModuleEnable", ForwardNative_hookEnable);
  CreateNative("Cmod_HookModuleEnable", ForwardNative_hookEnable);
  CreateNative("CmodModuleID.hookEnable", ForwardNative_hookEnable);
  CreateNative("CmodModuleID.HookEnable", ForwardNative_hookEnable);

  CreateNative("Cmod_unhookModuleEnable", ForwardNative_unhookEnable);
  CreateNative("Cmod_UnhookModuleEnable", ForwardNative_unhookEnable);
  CreateNative("CmodModuleID.unhookEnable", ForwardNative_unhookEnable);
  CreateNative("CmodModuleID.UnhookEnable", ForwardNative_unhookEnable);

  CreateNative("Cmod_hookModuleDisable", ForwardNative_hookDisable);
  CreateNative("Cmod_HookModuleDisable", ForwardNative_hookDisable);
  CreateNative("CmodModuleID.hookDisable", ForwardNative_hookDisable);
  CreateNative("CmodModuleID.HookDisable", ForwardNative_hookDisable);

  CreateNative("Cmod_unhookModuleDisable", ForwardNative_unhookDisable);
  CreateNative("Cmod_UnhookModuleDisable", ForwardNative_unhookDisable);
  CreateNative("CmodModuleID.unhookDisable", ForwardNative_unhookDisable);
  CreateNative("CmodModuleID.UnhookDisable", ForwardNative_unhookDisable);
}

public int ForwardNative_hookEnable(Handle plugin, int numParams) {
  ModuleID module = GetNativeCell(1);
  Forward_getEnableForward(module).hook(plugin, GetNativeCell(2));
}

public int ForwardNative_unhookEnable(Handle plugin, int numParams) {
  ModuleID module = GetNativeCell(1);
  Forward_getEnableForward(module).unhook(plugin, GetNativeCell(2));
}

public int ForwardNative_hookDisable(Handle plugin, int numParams) {
  ModuleID module = GetNativeCell(1);
  Forward_getDisableForward(module).hook(plugin, GetNativeCell(2));
}

public int ForwardNative_unhookDisable(Handle plugin, int numParams) {
  ModuleID module = GetNativeCell(1);
  Forward_getDisableForward(module).unhook(plugin, GetNativeCell(2));
}
