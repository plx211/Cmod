static ArrayList slotArray;

void SlotManager_init() {
  slotArray = new ArrayList();
}

ArrayList SlotManager_getSlotArray() {
  return slotArray;
}

SlotID SlotManager_getFreeSlotID() {
  SlotID slotID = slotArray.FindValue(SlotStatus_Free);
  if (slotID == SlotID_Invalid) {
    slotID = slotArray.Push(SlotStatus_Free);
  }
  return slotID;
}

void SlotManager_setSlotStatus(SlotID slotID, SlotStatus status) {
  slotsArray.Set(slotID, status);
}

SlotStatus SlotManager_getSlotStatus(SlotID slotID) {
  return slotsArray.Get(slotID);
}

SlotID SlotManager_createSlot() {
  SlotID slotID = SlotManager_getFreeSlotID();
  SlotManager_setSlotStatus(slotID, SlotStatus_Use);
  return slotID;
}

void SlotManager_removeSlot(SlotID slotID) {
  SlotManager_setSlotStatus(slotID, SlotStatus_Free);
}
