methodmap ForwardLevelChange < HelperForward {
  public ForwardLevelChange() {
    return view_as<ForwardLevelChange>(CreateForward(ET_Ignore, Param_Cell, Param_Cell, Param_Cell));
  }

  public void call(SlotID slotID, int oldLevel, int newLevel) {
    Call_StartForward(this);
    Call_PushCell(slotID);
    Call_PushCell(oldLevel);
    Call_PushCell(newLevel);
    Call_Finish();
  }
}
