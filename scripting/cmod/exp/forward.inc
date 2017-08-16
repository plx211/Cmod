static HelperForwardArray levelChange;

void Forward_init() {
  levelChange = new HelperForwardArray();
}

ForwardLevelChange Forward_getLevelChangeForward(SlotID slotID) {
  return view_as<ForwardLevelChange>(levelChange.get(view_as<int>(slotID)));
}

void Forward_onExpIDCreate(SlotID slotID) {
  levelChange.set(view_as<int>(slotID), new ForwardLevelChange());
}

void Forward_onExpIDRemove(SlotID slotID) {
  Forward_getLevelChangeForward(slotID).remove();
}

void Forward_onLevelChange(SlotID slotID, int oldLevel, int newLevel) {
  Forward_getLevelChangeForward(slotID).call(slotID, oldLevel, newLevel);
}
