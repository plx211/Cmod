methodmap HelperForward < Handle {
  public bool hook(Handle plugin, Function func) {
    return AddToForward(this, plugin, func);
  }

  public bool unhook(Handle plugin, Function func) {
    return RemoveFromForward(this, plugin, func);
  }

  public void remove() {
    CloseHandle(this);
  }
}
