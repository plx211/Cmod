static ArrayList moduleRequest;

void Req_init() {
  moduleRequest = new ArrayList();
}

ArrayList Req_getArray(ModuleID module) {
  return moduleRequest.Get(view_as<int>(module));
}

void Req_setArray(ModuleID module, ArrayList array) {
  moduleRequest.Set(view_as<int>(module), array);
}

void Req_add(ModuleID module, const char[] requirement) {
  Req_getArray(module).PushString(requirement);
}

void Req_get(ModuleID module, int req, char[] buffer, int maxlength) {
  Req_getArray(module).GetString(req, buffer, maxlength);
}

int Req_getCount(ModuleID module) {
  return Req_getArray(module).Length;
}

void Req_check(ModuleID module) {
  ArrayList array = Req_getArray(module);
  int count = array.Length;
  char name[MAX_NAME_MODULE_LENGTH + 1];

  for (int i = 0; i < count; ++i) {
    array.GetString(i, name, sizeof(name));
    ModuleID moduleID = Module_find(name);

    if (moduleID == ModuleID_Invalid || Module_getStatus(moduleID) != ModuleStatus_Enable) {
      if (Module_getStatus(module) == ModuleStatus_Enable) {
        Module_setDisable(module);
      }

      return;
    }
  }

  Module_setEnable(module);
}

void Req_setReadyToCheck(ModuleID module) {
  Module_setStatus(module, ModuleStatus_ReadyToCheck);
  Req_check(module);
}

void Req_onModuleCreate(ModuleID module) {
  if (view_as<int>(module) >= moduleRequest.Length) {
    moduleRequest.Resize(view_as<int>(module) + 1);
  }

  Req_setArray(module, new ArrayList(MAX_NAME_MODULE_LENGTH));
}

void Req_onModuleEnable() {
  int count = Module_getSlotCount();

  for (ModuleID moduleID = ModuleID_First; moduleID < view_as<ModuleID>(count); ++moduleID) {
    if (Module_getStatus(moduleID) == ModuleStatus_ReadyToCheck) {
      Req_check(moduleID);
    }
  }
}

void Req_onModuleRemove(ModuleID module) {
  CloseHandle(Req_getArray(module));
  Req_setArray(module, view_as<ArrayList>(INVALID_HANDLE));
}

void Req_onModuleDisable() {
  Req_onModuleEnable();
}
