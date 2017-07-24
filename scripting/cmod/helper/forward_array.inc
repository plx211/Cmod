methodmap HelperForwardArray < ArrayList {
  public HelperForwardArray() {
    return view_as<HelperForwardArray>(new ArrayList());
  }

  public HelperForward get(int index) {
    return this.Get(index);
  }

  public void set(int index, HelperForward fwd) {
    if (index >= this.Length) {
      this.Resize(index + 1);
    }

    this.Set(index, fwd);
  }
}
