void ModuleNative_init() {
  CreateNative("Cmod_createModule", ModuleNative_create);
  CreateNative("Cmod_CreateModule", ModuleNative_create);
  CreateNative("CmodModuleID.CmodModuleID", ModuleNative_create);

  CreateNative("Cmod_getModuleName", ModuleNative_getName);
  CreateNative("Cmod_GetModuleName", ModuleNative_getName);
  CreateNative("CmodModuleID.getName", ModuleNative_getName);
  CreateNative("CmodModuleID.GetName", ModuleNative_getName);

  CreateNative("Cmod_getModuleStatus", ModuleNative_getStatus);
  CreateNative("Cmod_GetModuleStatus", ModuleNative_getStatus);
  CreateNative("CmodModuleID.getStatus", ModuleNative_getStatus);
  CreateNative("CmodModuleID.GetStatus", ModuleNative_getStatus);

  CreateNative("Cmod_findModuleID", ModuleNative_find);
  CreateNative("Cmod_FindModuleID", ModuleNative_find);

  CreateNative("Cmod_removeModule", ModuleNative_remove);
  CreateNative("Cmod_RemoveModule", ModuleNative_remove);
  CreateNative("CmodModuleID.remove", ModuleNative_remove);
  CreateNative("CmodModuleID.Remove", ModuleNative_remove);

  CreateNative("Cmod_getModuleSlotCount", ModuleNative_getSlotCount);
  CreateNative("Cmod_GetModuleSlotCount", ModuleNative_getSlotCount);
}

public int ModuleNative_create(Handle plugin, int numParams) {
  char name[MAX_NAME_MODULE_LENGTH + 1];
  GetNativeString(1, name, sizeof(name));
  return view_as<int>(Module_create(name));
}

public int ModuleNative_getName(Handle plugin, int numParams) {
  char name[MAX_NAME_MODULE_LENGTH + 1];
  ModuleID module = GetNativeCell(1);
  Module_getName(module, name, sizeof(name));
  int size = GetNativeCell(3);
  SetNativeString(2, name, size);
}

public int ModuleNative_getStatus(Handle plugin, int numParams) {
  ModuleID module = GetNativeCell(1);
  return view_as<int>(Module_getStatus(module));
}

public int ModuleNative_find(Handle plugin, int numParams) {
  char name[MAX_NAME_MODULE_LENGTH + 1];
  GetNativeString(1, name, sizeof(name));
  return view_as<int>(Module_find(name));
}

public int ModuleNative_remove(Handle plugin, int numParams) {
  ModuleID module = GetNativeCell(1);
  Module_remove(module);
}

public int ModuleNative_getSlotCount(Handle plugin, int numParams) {
  return Module_getSlotCount();
}
