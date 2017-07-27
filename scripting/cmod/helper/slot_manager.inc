enum SlotID {
  SlotID_Invalid = -1,
  SlotID_First
};

enum SlotStatus {
  SlotStatus_Free,
  SlotStatus_Use
};

methodmap SlotManager {
  property ArrayList array {
    public get() {
      return view_as<ArrayList>(this);
    }
  }

  public SlotManager() {
    ArrayList array = new ArrayList();
    return array;
  }

  public SlotID getFreeSlotID() {
    SlotID slotID = this.array.FindValue(SlotStatus_Free);
    if (slotID == SlotID_Invalid) {
      slotID = this.array.Push(SlotStatus_Free);
    }
    return slotID;
  }

  public void setSlotStatus(SlotID slotID, SlotStatus status) {
    this.array.Set(slotID, status);
  }

  public SlotStatus getSlotStatus(SlotID slotID) {
    return this.array.Get(slotID);
  }

  public int getSlotCount() {
    return this.array.Length;
  }

  public bool isValidSlot(SlotID slotID) {
    if (SlotID_Invalid < slotID < this.getSlotCount()) {
      return true;
    }
    return false;
  }

  public SlotID createSlot() {
    SlotID slotID = this.getFreeSlotID();
    this.setSlotStatus(slotID, SlotStatus_Use);
    return slotID
  }

  public void removeSlot(SlotID slotID) {
    this.setSlotStatus(slotID, SlotStatus_Free);
  }
}
