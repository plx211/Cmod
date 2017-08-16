const int MAX_SLOT_NAME_LENGTH = 256;

static ArrayList nameArray;

void SlotName_init() {
  nameArray = new ArrayList(MAX_SLOT_NAME_LENGTH + 1);
}

SlotID SlotName_find(const char[] name) {
  return view_as<SlotID>(nameArray.FindString(name));
}

void SlotName_set(SlotID slotID, const char[] name) {
  int length = nameArray.Length;
  if (view_as<int>(slotID) >= length) {
    nameArray.Resize(view_as<int>(slotID) + 1);
    for (int i = length; i <= view_as<int>(slotID); ++i) {
      nameArray.SetString(i, "");
    }
  }
  nameArray.SetString(view_as<int>(slotID), name);
}

void SlotName_get(SlotID slotID, char[] buffer, int length) {
  nameArray.GetString(view_as<int>(slotID), buffer, length);
}
