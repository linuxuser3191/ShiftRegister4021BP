/*
 * ShiftRegister4021BP - Library for simple control of 4021BP shift registers
 * Written by Thomas Robinson, May 2018
 * Released into the public domain
 */

#include <ShiftRegister4021BP.h>

//create shift register object
ShiftRegister4021BP sr(2, 50, 52, 48);          //attributes (number of shift registers, datapin, clockpin, latchpin)

void setup() {
}

void loop() {
  uint8_t valueOfPin0 = sr.get(0);              //read value of pin 0 on register 1

  uint8_t valueOfPin15 = sr.get(15);            //read value of pin 7 on register 2
}
