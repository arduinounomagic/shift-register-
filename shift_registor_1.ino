//Copyright (C) 2007 Free Software Foundation, Inc. <arduinounomagic@gmail.com>
//For more projects please visit://www.arduinounomagic.com
//This is a basic shift resistor example which will turn on all the 8 LEDs for a second and then turn them off after some delay 

const int DataPin=2;              // Data pin of 74HC595 shift resistor is connected to pin 2 
const int ClockPin=3;             // Clock pin of 74HC595 shift resistor is connected to pin 3 
const int LatchPin=4;             // Latch pin of 74HC595 shift resistor is connected to pin 4


void setup() {
pinMode(DataPin, OUTPUT);          // Set pin 2 as output
pinMode(ClockPin, OUTPUT);         // Set pin 3 as output
pinMode(LatchPin, OUTPUT);         // Set pin 4 as output


}

void loop() {
digitalWrite(LatchPin, LOW);                       //Sets the pin 4 LOW
shiftOut(DataPin, ClockPin, LSBFIRST, 255);        //shift out a byte of data one bit at a time start from Least significnat bit first
digitalWrite(LatchPin, HIGH);                      //Sets the pin 4 HIGH
delay(1000);                                       //Wait for a sec

digitalWrite(LatchPin, LOW);                       //Sets the pin 4 LOW
shiftOut(DataPin, ClockPin, LSBFIRST, 0);          //shift out a byte of data one bit at a time start from Least significnat bit first
digitalWrite(LatchPin, HIGH);                      //Sets the pin 4 HIGH
delay(1000);                                       //Wait for a sec
}
