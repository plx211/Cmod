const int MAX_NAME_MODULE_LENGTH = 256;

enum ModuleStatus {
  ModuleStatus_FreeSlot = 0,
  ModuleStatus_Prepare,
  ModuleStatus_ReadyToCheck,
  ModuleStatus_Enable
};

enum ModuleID {
  ModuleID_Invalid = -1,
  ModuleID_First
};

static ArrayList moduleStatus;
static ArrayList moduleName;

void Module_init() {
  moduleName = new ArrayList(MAX_NAME_MODULE_LENGTH);
  moduleStatus = new ArrayList();
}

ModuleID Module_getFreeSlot() {
  ModuleID module = view_as<ModuleID>(moduleStatus.FindValue(ModuleStatus_FreeSlot));

  if (module == ModuleID_Invalid) {
    module = view_as<ModuleID>(moduleStatus.Push(ModuleStatus_FreeSlot));
    moduleName.PushString("");
  }

  return module;
}

ModuleID Module_find(const char[] name) {
  return view_as<ModuleID>(moduleName.FindString(name));
}

void Module_setStatus(ModuleID module, ModuleStatus status) {
  moduleStatus.Set(view_as<int>(module), status);
}

ModuleStatus Module_getStatus(ModuleID module) {
  return moduleStatus.Get(view_as<int>(module));
}

void Module_setName(ModuleID module, const char[] name) {
  moduleName.SetString(view_as<int>(module), name);
}

int Module_getName(ModuleID module, char[] buffer, int maxlength) {
  return moduleName.GetString(view_as<int>(module), buffer, maxlength);
}

ModuleID Module_register(const char[] name) {
  if (Module_find(name) != ModuleID_Invalid) {
    LogError("Failed to register, Reason: Name duplicate");
    return ModuleID_Invalid;
  }

  ModuleID module = Module_getFreeSlot();
  Module_setStatus(module, ModuleStatus_Prepare);
  Module_setName(module, name);

  return module;
}

int Module_getSlotCount() {
  return moduleStatus.Length;
}

ModuleID Module_create(const char[] name) {
  ModuleID module = Module_register(name);

  if (module != ModuleID_Invalid) {
    onModuleCreate(module, name);
  }

  return module;
}

void Module_unregister(ModuleID module) {
  Module_setName(module, "");
  Module_setStatus(module, ModuleStatus_FreeSlot);
}

void Module_remove(ModuleID module) {
  char name[MAX_NAME_MODULE_LENGTH + 1];
  Module_getName(module, name, sizeof(name));
  Module_unregister(module);
  onModuleRemove(module, name);
}

void Module_setEnable(ModuleID module) {
  char name[MAX_NAME_MODULE_LENGTH + 1];
  Module_getName(module, name, sizeof(name));
  Module_setStatus(module, ModuleStatus_Enable);
  onModuleEnable(module, name);
}

void Module_setDisable(ModuleID module) {
  char name[MAX_NAME_MODULE_LENGTH + 1];
  Module_getName(module, name, sizeof(name));
  Module_setStatus(module, ModuleStatus_ReadyToCheck);
  onModuleDisable(module, name);
}
