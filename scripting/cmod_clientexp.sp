#include <sourcemod>
#include <cmod/exp>

#tryinclude "cmod/version"
#tryinclude "cmod/test"

#include "cmod/client_exp/config"
#include "cmod/client_exp/client_expid"

public void OnPluginStart() {
  Config_init();
  ClientExpID_init();
}
