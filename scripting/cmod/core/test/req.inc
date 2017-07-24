void ReqTest_init() {
  RegServerCmd("test_cmod_core_req_add", ReqTestCmd_add);
  RegServerCmd("test_cmod_core_req_set_ready", ReqTestCmd_setReady);
}

public Action ReqTestCmd_add(int args) {
  char buffer[MAX_NAME_MODULE_LENGTH];
  GetCmdArg(1, buffer, sizeof(buffer));
  ModuleID module = view_as<ModuleID>(StringToInt(buffer));
  GetCmdArg(2, buffer, sizeof(buffer));
  Req_add(module, buffer);
}

public Action ReqTestCmd_setReady(int args) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  ModuleID module = view_as<ModuleID>(StringToInt(buffer));
  Req_setReadyToCheck(module);
}
