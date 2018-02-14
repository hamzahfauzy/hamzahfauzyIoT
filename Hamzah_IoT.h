#ifndef Hamzah_IoT_h
#define Hamzah_IoT_h

#include "Arduino.h"
#include <Ethernet.h>

class HamzahIoT{
  public:
    HamzahIoT(String _API_KEY, EthernetClient _client);
    String getValue(String var);
    void httpRequest();
	String response;
	long lastConnectionTime;
	long postingInterval;
	EthernetClient client;
  private:
	String API_KEY;
};

#endif
