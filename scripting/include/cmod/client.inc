enum CmodClient {
  CmodClient_Server = 0,
  CmodClient_First = 1,
  CmodClient_Count = MAXPLAYERS
};

methodmap CmodClient {
  property CmodExpID expID {
    public native get();
  }

  property CmodExpID ExpID {
    public native get();
  }
};

native CmodExpID CmodClient_getExpID(int client);
native CmodExpID CmodClient_GetExpID(int client);
