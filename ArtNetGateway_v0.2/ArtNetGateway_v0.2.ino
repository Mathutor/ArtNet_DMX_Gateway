#include "artnet.h"

#include "dmxoutput.h"
#include "dmx.h"

void setup() {
  serialSetup();
  ethernetSetup();
  dmxInit();
  // dmxserialSetup();
}

void loop() {
  //packetRead();
  //artnetParse();
  // outputTest();
}
