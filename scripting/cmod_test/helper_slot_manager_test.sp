#include <sourcemod>

#include "cmod/helper/slot_manager/slot_id"
#include "cmod/helper/slot_manager/slot_status"
#include "cmod/helper/slot_manager/slot_manager"
#include "cmod/helper/slot_manager/slot_name"

#include "cmod/helper/forward"
#include "cmod/helper/slot_manager/forward/slot_create"
#include "cmod/helper/slot_manager/forward/slot_remove"
#include "cmod/helper/slot_manager/forward"

public void OnPluginStart() {
  SlotManager_init();
  SlotName_init();
  SlotManagerForward_init();

  SlotManagerForward_getCreate().hook(INVALID_HANDLE, SlotManagerTest_onSlotCreate);
  SlotManagerForward_getRemove().hook(INVALID_HANDLE, SlotManagerTest_onSlotRemove);

  RegServerCmd("test_slot_manager_create", SlotManagerTestCmd_create);
  RegServerCmd("test_slot_manager_remove", SlotManagerTestCmd_remove);
}

public Action SlotManagerTestCmd_create(int args) {
  char name[MAX_SLOT_NAME_LENGTH + 1];
  GetCmdArgString(name, sizeof(name));
  PrintToServer("SlotID = %d", SlotManagerTest_createSlot(name));
}

public Action SlotManagerTestCmd_remove(int args) {
  char buffer[32];
  GetCmdArg(1, buffer, sizeof(buffer));
  SlotID slotID = view_as<SlotID>(StringToInt(buffer));
  SlotManagerTest_removeSlot(slotID);
}

SlotID SlotManagerTest_createSlot(const char[] name) {
  SlotID slotID = SlotName_createSlot(name);
  if (slotID != SlotID_Invalid) {
    SlotManagerForward_getCreate().call(slotID);
  }
  return slotID;
}

void SlotManagerTest_removeSlot(SlotID slotID) {
  SlotManager_removeSlot(slotID);
  SlotManagerForward_getRemove().call(slotID);
}

public void SlotManagerTest_onSlotCreate(SlotID slotID) {
  char name[MAX_SLOT_NAME_LENGTH + 1];
  SlotName_get(slotID, name, sizeof(name));
  SlotStatus status = SlotManager_getSlotStatus(slotID);
  PrintToServer("[HelperSlotManagerTest:onSlotCreate]  slotID = %d name = %s status = %d", slotID, name, status);
}

public void SlotManagerTest_onSlotRemove(SlotID slotID) {
  char name[MAX_SLOT_NAME_LENGTH + 1];
  SlotName_get(slotID, name, sizeof(name));
  SlotStatus status = SlotManager_getSlotStatus(slotID);
  PrintToServer("[HelperSlotManagerTest:onSlotRemove]  slotID = %d name = %s status = %d", slotID, name, status);
}
