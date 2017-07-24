methodmap ForwardModuleDisable < HelperForward {
  public ForwardModuleDisable() {
    return view_as<ForwardModuleDisable>(CreateForward(ET_Ignore, Param_Cell, Param_String));
  }

  public void call(ModuleID module, const char[] name) {
    Call_StartForward(this);
    Call_PushCell(module);
    Call_PushString(name);
    Call_Finish();
  }
}
