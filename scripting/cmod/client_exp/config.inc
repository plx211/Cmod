static ConVar cvarRatio;
static ConVar cvarMaxLevel;
static ConVar cvarZero;

void Config_init() {
  cvarRatio = CreateConVar("cmod_clientexp_ratio", "35", "Exp to next level is calculate by level^2 * ratio");
  cvarMaxLevel = CreateConVar("cmod_clientexp_maxlevel", "201", "");
}

int Config_getRatio() {
  return cvarRatio.IntValue;
}

int Config_getMaxLevel() {
  return cvarMaxLevel.IntValue;
}
