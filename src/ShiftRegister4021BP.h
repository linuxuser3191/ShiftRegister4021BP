/*
 * ShiftRegister4021BP.h - Arduino library for simple control of 4021BP shift registers
 * Written by Thomas Robinson, May 2018
 * Released into the public domain
 */

 #ifndef ShiftRegister4021BP_h
 #define ShiftRegister4021BP_h

 #include "Arduino.h"

 class ShiftRegister4021BP {
  
  public:
    ShiftRegister4021BP(int numberOfRegisters, int dataPin, int clockPin, int latchPin);
    uint8_t getAll();
    uint8_t get(int pin);

  private:
    int _numberOfRegisters;
    int _clockPin;
    int _dataPin;
    int _latchPin;
    uint8_t * _registerValues;
 };

 #endif