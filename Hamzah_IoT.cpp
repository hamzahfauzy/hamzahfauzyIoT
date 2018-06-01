#include "Arduino.h"
#include "Hamzah_IoT.h"

HamzahIoT::HamzahIoT(String _API_KEY, EthernetClient _client){
	API_KEY = _API_KEY;
	client = _client;
	lastConnectionTime = 0;
	postingInterval = 10L * 1000L;
	response = "";
	
}

void HamzahIoT::httpRequest(){
	client.stop();
	response = "";
	char server[] = "www.publicdata.esy.es";
  	// if there's a successful connection:
  	if (client.connect(server, 80)) {
    	Serial.println("connected");
    	// Make a HTTP request:
    	client.println("GET /iot/iot.php?API_KEY="+API_KEY+" HTTP/1.1");
    	client.println("Host: www.publicdata.esy.es");
    	client.println("Connection: close");
    	client.println();
    	lastConnectionTime = millis();
  } else {
    	// if you didn't get a connection to the server:
    	Serial.println("connection failed");
  }
}

String HamzahIoT::getValue(String var){
  int response_start = response.indexOf("<"+var+">")+6;
  String data;
  if(response_start>5){
    int response_end = response.indexOf("</"+var+">");
    data = response.substring(response_start, response_end);
    int in = data.indexOf(">");
    if(in>-1)
      data = response.substring(response_start+(in+1), response_end);
  }
  return data;
}
