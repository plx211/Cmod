#include <sourcemod>
#include <cmod/exp>

#tryinclude "cmod/version"
#tryinclude "cmod/test"

#include "cmod/requirements/cmod_expcore"

#include "cmod/client_exp/config"
#include "cmod/client_exp/client_expid"
#include "cmod/client_exp/native/client_expid"

public void OnPluginStart() {
  Config_init();
  ClientExpID_init();
}

public APLRes AskPluginLoad2(Handle myself, bool late, char[] error, int err_max) {
  RegPluginLibrary("cmod_clientexp");
  ClientExpIDNative_init();
  return APLRes_Success;
}
