static HelperForwardArray moduleEnable;
static HelperForwardArray moduleDisable;

void Forward_init() {
  moduleEnable = new HelperForwardArray();
  moduleDisable = new HelperForwardArray();
}

ForwardModuleEnable Forward_getEnableForward(ModuleID module) {
  return view_as<ForwardModuleEnable>(moduleEnable.get(view_as<int>(module)));
}

ForwardModuleDisable Forward_getDisableForward(ModuleID module) {
  return view_as<ForwardModuleDisable>(moduleDisable.get(view_as<int>(module)));
}

void Forward_onModuleCreate(ModuleID module) {
  moduleEnable.set(view_as<int>(module), new ForwardModuleEnable());
  moduleDisable.set(view_as<int>(module), new ForwardModuleDisable());
}

void Forward_onModuleEnable(ModuleID module, const char[] name) {
  Forward_getEnableForward(module).call(module, name);
}

void Forward_onModuleDisable(ModuleID module, const char[] name) {
  Forward_getDisableForward(module).call(module, name);
}

void Forward_onModuleRemove(ModuleID module, const char[] name) {
  ForwardModuleDisable fwd = Forward_getDisableForward(module);
  fwd.call(module, name);
  fwd.remove();
}
