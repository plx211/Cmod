void ReqNative_init() {
  CreateNative("Cmod_addModuleReq", ReqNative_add);
  CreateNative("Cmod_AddModuleReq", ReqNative_add);
  CreateNative("CmodModuleID.addReq", ReqNative_add);
  CreateNative("CmodModuleID.AddReq", ReqNative_add);

  CreateNative("Cmod_setModuleReady", ReqNative_setReady);
  CreateNative("Cmod_SetModuleReady", ReqNative_setReady);
  CreateNative("CmodModuleID.setReady", ReqNative_setReady);
  CreateNative("CmodModuleID.SetReady", ReqNative_setReady);

}

public int ReqNative_add(Handle plugin, int numParams) {
  char name[MAX_NAME_MODULE_LENGTH + 1];
  GetNativeString(2, name, sizeof(name));
  ModuleID module = GetNativeCell(1);
  Req_add(module, name);
}

public int ReqNative_setReady(Handle plugin, int numParams) {
  ModuleID module = GetNativeCell(1);
  Req_setReadyToCheck(module);
}
