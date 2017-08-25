void ClientExpIDNative_init() {
  CreateNative("CmodClient.expID.get", ClientExpIDNative_get);
  CreateNative("CmodClient.ExpID.get", ClientExpIDNative_get);
  CreateNative("CmodClient_getExpID", ClientExpIDNative_get);
  CreateNative("CmodClient_GetExpID", ClientExpIDNative_get);
}

public int ClientExpIDNative_get(Handle plugin, int numParams) {
  int client = GetNativeCell(1);
  return view_as<int>(ClientExpID_get(client));
}
