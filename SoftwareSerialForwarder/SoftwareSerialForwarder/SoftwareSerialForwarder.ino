void setup() {
  // initialize the serial ports
  Serial.begin(9600);
  Serial1.begin(9600);
}
void loop() {
  int pin;
  // wait for data
  while(0==Serial1.available());
  // get the next byte
  int b = (byte)Serial1.read();
  
  if(254==b) { // read
    // wait for data
    while(0==Serial1.available());
    // read the pin id
    pin = Serial1.read();
    // read the pin
    int val = digitalRead(pin);
    // write the result back to the other CPU
    Serial1.write((byte)(0==val?0:1));
  } else if(255==b) { // write 
    // wait for data
    while(0==Serial1.available());
    // read the pin id
    pin = Serial1.read();
    // wait for data
    while(0==Serial1.available());
    // read the value to set
    int val = Serial1.read();
    // set the pin
    digitalWrite(pin,0!=val?HIGH:LOW);
  } else // simply forward
    Serial.write((byte)b);
  return;
}
