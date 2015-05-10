#include "Adafruit_WS2801.h"
#include "SPI.h" // Comment out this line if using Trinket or Gemma
#ifdef __AVR_ATtiny85__
 #include <avr/power.h>
#endif

/*****************************************************************************
Example sketch for driving Adafruit WS2801 pixels!


  Designed specifically to work with the Adafruit RGB Pixels!
  12mm Bullet shape ----> https://www.adafruit.com/products/322
  12mm Flat shape   ----> https://www.adafruit.com/products/738
  36mm Square shape ----> https://www.adafruit.com/products/683

  These pixels use SPI to transmit the color data, and have built in
  high speed PWM drivers for 24 bit color per pixel
  2 pins are required to interface

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution

*****************************************************************************/

// Choose which 2 pins you will use for output.
// Can be any valid output pins.
// The colors of the wires may be totally different so
// BE SURE TO CHECK YOUR PIXELS TO SEE WHICH WIRES TO USE!
uint8_t dataPin  = 2;    // Yellow wire on Adafruit Pixels
uint8_t clockPin = 3;    // Green wire on Adafruit Pixels

// Don't forget to connect the ground wire to Arduino ground,
// and the +5V wire to a +5V supply

// Set the first variable to the NUMBER of pixels. 25 = 25 pixels in a row
Adafruit_WS2801 strip = Adafruit_WS2801(24, dataPin, clockPin);

// Optional: leave off pin numbers to use hardware SPI
// (pinout is then specific to each board and can't be changed)
//Adafruit_WS2801 strip = Adafruit_WS2801(25);

// For 36mm LED pixels: these pixels internally represent color in a
// different format.  Either of the above constructors can accept an
// optional extra parameter: WS2801_RGB is 'conventional' RGB order
// WS2801_GRB is the GRB order required by the 36mm pixels.  Other
// than this parameter, your code does not need to do anything different;
// the library will handle the format change.  Examples:
//Adafruit_WS2801 strip = Adafruit_WS2801(25, dataPin, clockPin, WS2801_GRB);
//Adafruit_WS2801 strip = Adafruit_WS2801(25, WS2801_GRB);

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  strip.begin();

  // Update LED contents, to start they are all 'off'
  strip.show();
}


void loop() {
  // Some example procedures showing how to display to the pixels
  
  LightPattern1();
  LightPattern2();
  LightPattern3();
  LightPattern4();
  LightPattern5();
  LightPattern6();
  LightPattern7();
  LightPattern8();
  LightPattern9();
  LightPattern0();
}

void topStripLight(uint32_t c, uint8_t wait){
  int i;
  
  for (i=0; i<3; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void topLeftStripLight(uint32_t c, uint8_t wait){
  int i;
  
  for (i=3; i<6; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void bottomLeftStripLight(uint32_t c, uint8_t wait){
  int i;
  
  for (i=6; i<9; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void bottomStripLight(uint32_t c, uint8_t wait){
  int i;
  
  for (i=9; i<12; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void bottomRightStripLight(uint32_t c, uint8_t wait){
  int i;
  
  for (i=12; i<15; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void middleStripLight(uint32_t c, uint8_t wait){
  int i;
  
  for (i=15; i<18; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void topRightStripLight(uint32_t c, uint8_t wait){
  int i;
  
  for (i=18; i<21; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void LightPattern1(){
  topRightStripLight(Color(255, 0, 0), 0);
  bottomRightStripLight(Color(255, 0, 0), 0);
}

void LightPattern2(){
  topStripLight(Color(0, 255, 0), 0);
  middleStripLight(Color(0, 255, 0), 0);
  bottomStripLight(Color(0, 255, 0), 0);
  topRightStripLight(Color(0, 255, 0), 0);
  bottomLeftStripLight(Color(0, 255, 0), 0);
}

void LightPattern3(){
  topRightStripLight(Color(0, 0, 255), 0);
  bottomRightStripLight(Color(0, 0, 255), 0);
  topStripLight(Color(0, 0, 255), 0);
  middleStripLight(Color(0, 0, 255), 0);
  bottomStripLight(Color(0, 0, 255), 0);
}

void LightPattern4(){
  middleStripLight(Color(255, 0, 255), 0);
  topLeftStripLight(Color(255, 0, 255), 0);
  topRightStripLight(Color(255, 0, 255), 0);
  bottomRightStripLight(Color(255, 0, 255), 0);
}

void LightPattern5(){
  topStripLight(Color(255, 0, 0), 0);
  middleStripLight(Color(255, 0, 0), 0);
  bottomStripLight(Color(255, 0, 0), 0);
  topLeftStripLight(Color(255, 0, 0), 0);
  bottomRightStripLight(Color(255, 0, 0), 0);
}

void LightPattern6(){
  topStripLight(Color(0, 255, 0), 0);
  middleStripLight(Color(0, 255, 0), 0);
  bottomStripLight(Color(0, 255, 0), 0);
  topLeftStripLight(Color(0, 255, 0), 0);
  bottomLeftStripLight(Color(0, 255, 0), 0);
  bottomRightStripLight(Color(0, 255, 0), 0);
}

void LightPattern7(){
  topStripLight(Color(0, 0, 255), 0);
  topRightStripLight(Color(0, 0, 255), 0);
  bottomRightStripLight(Color(0, 0, 255), 0);
}

void LightPattern8(){
  topStripLight(Color(255, 0, 255), 0);
  middleStripLight(Color(255, 0, 255), 0);
  bottomStripLight(Color(255, 0, 255), 0);
  topLeftStripLight(Color(255, 0, 255), 0);
  bottomLeftStripLight(Color(255, 0, 255), 0);
  topRightStripLight(Color(255, 0, 255), 0);
  bottomRightStripLight(Color(255, 0, 255), 0);
}

void LightPattern9(){
  topStripLight(Color(255, 0, 0), 0);
  middleStripLight(Color(255, 0, 0), 0);
  topLeftStripLight(Color(255, 0, 0), 0);
  topRightStripLight(Color(255, 0, 0), 0);
  bottomRightStripLight(Color(255, 0, 0), 0);
}

void LightPattern0(){
  topStripLight(Color(0, 255, 0), 0);
  bottomStripLight(Color(0, 255, 0), 0);
  topLeftStripLight(Color(0, 255, 0), 0);
  topRightStripLight(Color(0, 255, 0), 0);
  bottomLeftStripLight(Color(0, 255, 0), 0);
  bottomRightStripLight(Color(0, 255, 0), 0);
}

/* Helper functions */

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g -b - back to r
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85) {
   return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
   WheelPos -= 85;
   return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170; 
   return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
