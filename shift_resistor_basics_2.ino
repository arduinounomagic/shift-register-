//Copyright (C) 2007 Free Software Foundation, Inc. <arduinounomagic@gmail.com>
//For more projects please visit://www.arduinounomagic.com
//This example turn on alternate LEDs one by one and then turn off them in the same manner. 

const int DataPin=2;       // Data pin of 74HC595 shift resistor is connected to pin 2 
const int ClockPin=3;      // Clock pin of 74HC595 shift resistor is connected to pin 3 
const int LatchPin=4;      // Latch pin of 74HC595 shift resistor is connected to pin 4

byte Data=0;              // Define a variable named Data to hold the current state (ON or OFF) of LEDs 

void setup()              // This function run once when Arduino turns ON
{
pinMode(DataPin, OUTPUT); // Set pin 2 as output
pinMode(ClockPin, OUTPUT);// Set pin 3 as output
pinMode(LatchPin, OUTPUT);// Set pin 4 as output

}

void loop()               // This function runs over and over again
{
   shiftWrite(1,1);       // Turn on the 2nd LED from left hand side by making pin 1 ON
  delay(1000);            // Wait for 1 sec
 
shiftWrite(3,1);         // Turn on the 4th LED from left hand side by making pin 3  ON
  delay(1000);           // Wait for 1 sec

  shiftWrite(5,1);       // Turn on the 6th LED from left hand side by making pin 5  ON
  delay(1000);           // Wait for 1 sec
  
   shiftWrite(7,1);      // Turn on the 8th LED from left hand side by making pin 7  ON
  delay(1000);           // Wait for 1 sec

 
   shiftWrite(1,0);      // Turn off the 2nd LED from left hand side by making pin 1 OFF
  delay(1000);           // Wait for 1 sec
  
    shiftWrite(3,0);     // Turn off the 4th LED from left hand side by making pin 3 OFF
 delay(1000);            // Wait for 1 sec
  
  shiftWrite(5,0);       // Turn off the 6th LED from left hand side by making pin 5 OFF
  delay(1000);           // Wait for 1 sec
  
    shiftWrite(7,0);     // Turn off the 8th LED from left hand side by making pin 7 OFF
  delay(1000);           // Wait for 1 sec
} 

void shiftWrite(int Pin, boolean State) //Initalize the function shiftWrite which has variable Pin that defines pins (0 to 7 from left hand side) and boolean variable defines the state (0/1) of the LEDS 
  
{
 bitWrite(Data, Pin, State);            
  digitalWrite(LatchPin, LOW);                     //Sets the pin 4 LOW
  shiftOut(DataPin, ClockPin, MSBFIRST, Data);     //shift out a byte of data one bit at a time start from Most significnat bit first
  digitalWrite(LatchPin, HIGH);                    //Sets the pin 4 HIGH
}
