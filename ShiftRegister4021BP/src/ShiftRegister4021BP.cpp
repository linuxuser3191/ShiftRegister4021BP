/*
 * ShiftRegister4021BP.cpp - Arduino library for simple control of 4021BP shift registers
 * Written by Thomas Robinson, May 2018
 * Released into the public domain
 */

 #include "Arduino.h"
 #include "ShiftRegister4021BP.h"

  //Shift Register constructor
 ShiftRegister4021BP::ShiftRegister4021BP(int numberOfRegisters, int dataPin, int clockPin, int latchPin) {
	 
    //constructor attributes
    _numberOfRegisters = numberOfRegisters;
    _clockPin = clockPin;
    _dataPin = dataPin;
    _latchPin = latchPin;

    //define pins as i/o
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, INPUT);
    pinMode(latchPin, OUTPUT);

    //set pins low
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, LOW);
    digitalWrite(latchPin, LOW);

    //allocates the specified number of bytes and sets all to 0
    _registerValues = (uint8_t *)malloc(numberOfRegisters * sizeof(uint8_t));
    memset(_registerValues, 0, numberOfRegisters * sizeof(uint8_t));
 }
 
//reads shift register pins and writes to registerValues, an uint8_t array equal to the number of shift registers
uint8_t ShiftRegister4021BP::getAll() {
    int byte;

    digitalWrite(_latchPin, HIGH);
    delayMicroseconds(20);
    digitalWrite(_latchPin, LOW);
	  
    for (byte = _numberOfRegisters - 1; byte >= 0; byte--) {
      _registerValues[byte] = shiftIn(_dataPin, _clockPin, MSBFIRST);
      digitalWrite(_clockPin, LOW);
      delayMicroseconds(1);
      digitalWrite(_clockPin, HIGH);
    }

    return _registerValues;
}

//reads pins and returns value of specified pin
uint8_t ShiftRegister4021BP::get(int pin) {
    getAll();	
    return (_registerValues[pin / 8] >> (pin % 8)) & 1;
}