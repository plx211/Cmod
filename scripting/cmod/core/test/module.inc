void ModuleTest_init() {
  RegServerCmd("test_cmod_core_module_create", ModuleTestCmd_create);
  RegServerCmd("test_cmod_core_module_remove", ModuleTestCmd_remove);
  RegServerCmd("test_cmod_core_module_print", ModuleTestCmd_print);
}

public Action ModuleTestCmd_create(int args) {
  char name[MAX_NAME_MODULE_LENGTH + 1];
  GetCmdArg(1, name, sizeof(name));
  ModuleID module = Module_create(name);
  PrintToServer("Name = \"%s\" ModuleID = %d", name, module);
}

public Action ModuleTestCmd_remove(int args) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  ModuleID module = view_as<ModuleID>(StringToInt(buffer));
  Module_remove(module);
}

public Action ModuleTestCmd_print(int args) {
  char name[MAX_NAME_MODULE_LENGTH + 1];
  int count = Module_getSlotCount();
  PrintToServer("Slot count = %d", count);
  for (ModuleID module = ModuleID_First; module < view_as<ModuleID>(count); ++module) {
    Module_getName(module, name, sizeof(name));
    ModuleStatus status = Module_getStatus(module);
    PrintToServer("---------------------------");
    PrintToServer("ModuleID = %d", module);
    PrintToServer("Name = %s", name);
    PrintToServer("Slot status = %d", status);
    if (status != ModuleStatus_FreeSlot) {
      PrintToServer("Req:");
      int reqCount = Req_getCount(module);
      for (int i = 0; i < reqCount; ++i) {
        Req_get(module, i, name, sizeof(name));
        PrintToServer("\t\"%s\"", name);
      }
    }
  }
}

void ModuleTest_onModuleCreate(ModuleID module, const char[] name) {
  PrintToServer("ModuleTest_onModuleCreate module = %d name = %s", module, name);
}

void ModuleTest_onModuleEnable(ModuleID module, const char[] name) {
  PrintToServer("ModuleTest_onModuleEnable module = %d name = %s", module, name);
}

void ModuleTest_onModuleRemove(ModuleID module, const char[] name) {
  PrintToServer("ModuleTest_onModuleRemove module = %d name = %s", module, name);
}

void ModuleTest_onModuleDisable(ModuleID module, const char[] name) {
  PrintToServer("ModuleTest_onModuleDisable module = %d name = %s", module, name);
}
