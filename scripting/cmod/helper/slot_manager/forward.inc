static ForwardSlotCreate fwdSlotCreate;
static ForwardSlotRemove fwdSlotRemove;

void SlotManagerForward_init() {
  fwdSlotCreate = new ForwardSlotCreate();
  fwdSlotRemove = new ForwardSlotRemove();
}

ForwardSlotCreate SlotManagerForward_getCreate() {
  return fwdSlotCreate;
}

ForwardSlotRemove SlotManagerForward_getRemove() {
  return fwdSlotRemove;
}
