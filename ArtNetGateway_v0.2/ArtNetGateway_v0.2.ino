#include "artnet.h"

#include "dmxoutput.h"
#include "dmx.h"

void setup() {
  serialSetup();
  wifiSetup();
  dmxInit();
  // dmxserialSetup();
}

void loop() {
  //packetRead();
  //artnetParse();
  // outputTest();
}
