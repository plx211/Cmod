static CmodExpID clientExpID[MAXPLAYERS];

void ClientExpID_init() {
  int ratio = Config_getRatio();
  int maxLevel = Config_getMaxLevel();

  for (int i = 0; i < MAXPLAYERS; ++i) {
    clientExpID[i] = new CmodExpID(ratio, maxLevel);
  }
}

CmodExpID ClientExpID_get(int client) {
  return clientExpID[client];
}
