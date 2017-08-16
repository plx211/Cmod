methodmap ForwardSlotCreate < HelperForward {
  public ForwardSlotCreate() {
    return view_as<ForwardSlotCreate>(CreateForward(ET_Ignore, Param_Cell));
  }

  public void call(SlotID slotID) {
    Call_StartForward(this);
    Call_PushCell(slotID);
    Call_Finish();
  }
};
