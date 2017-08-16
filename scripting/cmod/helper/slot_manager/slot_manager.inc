static ArrayList slotArray;

void SlotManager_init() {
  slotArray = new ArrayList();
}

ArrayList SlotManager_getSlotArray() {
  return slotArray;
}

SlotID SlotManager_getFreeSlotID() {
  SlotID slotID = view_as<SlotID>(slotArray.FindValue(SlotStatus_Free));
  if (slotID == SlotID_Invalid) {
    slotID = view_as<SlotID>(slotArray.Push(SlotStatus_Free));
  }
  return slotID;
}

void SlotManager_setSlotStatus(SlotID slotID, SlotStatus status) {
  slotArray.Set(view_as<int>(slotID), status);
}

SlotStatus SlotManager_getSlotStatus(SlotID slotID) {
  return slotArray.Get(view_as<int>(slotID));
}

SlotID SlotManager_createSlot() {
  SlotID slotID = SlotManager_getFreeSlotID();
  SlotManager_setSlotStatus(slotID, SlotStatus_Use);
  return slotID;
}

void SlotManager_removeSlot(SlotID slotID) {
  SlotManager_setSlotStatus(slotID, SlotStatus_Free);
}
