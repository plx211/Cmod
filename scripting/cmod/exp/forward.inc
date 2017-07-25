static HelperForwardArray levelChange;

void Forward_init() {
  levelChange = new HelperForwardArray();
}

ForwardLevelChange getLevelChangeForward(ExpID expID) {
  return view_as<ForwardLevelChange>(levelChange.get(view_as<int>(expID)));
}

void Forward_onExpIDCreate(ExpID expID) {
  levelChange.set(view_as<int>(expID), new ForwardLevelChange());
}

void Forward_onExpIDRemove(ExpID expID) {
  getLevelChangeForward(expID).remove();
}

void Forward_onLevelChange(ExpID expID, int oldLevel, int newLevel) {
  getLevelChangeForward(expID).call(expID, oldLevel, newLevel);
}
