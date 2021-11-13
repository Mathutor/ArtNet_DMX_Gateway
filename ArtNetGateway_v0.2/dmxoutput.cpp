#include "dmxoutput.h"
#include <Arduino.h>
#include <ArduinoRS485.h>
#include "dmx.h"

#define DMX_BAUD 250000
#define UART_THREE_TX 14
#define UART_THREE_DE 2
#define UART_THREE_RE 5

RS485Class RS485_Serial3(SERIAL_PORT_HARDWARE3, UART_THREE_TX, UART_THREE_DE, UART_THREE_RE);

void dmxserialSetup()
{
  RS485_Serial3.begin(DMX_BAUD,SERIAL_8N2);
  RS485_Serial3.beginTransmission();
}

void outputTest()
{
    
    RS485_Serial3.write((uint8_t)0x00);
    RS485_Serial3.sendBreakMicroseconds(50);
    RS485_Serial3.write((uint8_t)0xFF);
    RS485_Serial3.sendBreakMicroseconds(50);
    
}

void outputDMX()
{
  uint8_t startcode[] = {0x38,0x03};
  RS485_Serial3.sendBreakMicroseconds(100);//space for break
  RS485_Serial3.write(startcode,2);//MARK after BREAK (MAB)
  
}
