methodmap ForwardSlotRemove < HelperForward {
  public ForwardSlotRemove() {
    return view_as<ForwardSlotRemove>(CreateForward(ET_Ignore, Param_Cell));
  }

  public void call(SlotID slotID) {
    Call_StartForward(this);
    Call_PushCell(slotID);
    Call_StartForward();
  }
};
