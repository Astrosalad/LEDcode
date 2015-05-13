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

const int pingPin = 7;
long cm = 0;
int score = 0;
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

void setup() {
  Serial.begin(9600);
  
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif
  strip.begin();
  strip.show();
}


void loop() {
  
  ultrasonic();
  long measure1 = cm;
  delay(100);
  ultrasonic();
  long measure2 = cm;
  
  void (*ptr[10])();
  
  ptr[0] = LightPattern0;
  ptr[1] = LightPattern1;
  ptr[2] = LightPattern2;
  ptr[3] = LightPattern3;
  ptr[4] = LightPattern4;
  ptr[5] = LightPattern5;
  ptr[6] = LightPattern6;
  ptr[7] = LightPattern7;
  ptr[8] = LightPattern8;
  ptr[9] = LightPattern9;
  
  if(measure1 > 10 && measure2 < 10){
    score = score + 1;
    if(score > 9){
      score  = 0;
    }
  }
  ptr[score];
}

void topStripLight(uint32_t c, uint8_t wait){
  for (int i=3; i<6; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void topLeftStripLight(uint32_t c, uint8_t wait){
  for (int i=6; i<9; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void bottomLeftStripLight(uint32_t c, uint8_t wait){
  for (int i=9; i<12; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void bottomStripLight(uint32_t c, uint8_t wait){
  for (int i=12; i<15; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void bottomRightStripLight(uint32_t c, uint8_t wait){
  for (int i=15; i<18; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void middleStripLight(uint32_t c, uint8_t wait){
  for (int i=18; i<21; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void topRightStripLight(uint32_t c, uint8_t wait){
  for (int i=0; i<3; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void LightPattern1(){
  topRightStripLight(Color(255, 0, 0), 0);
  bottomRightStripLight(Color(255, 0, 0), 0);
  delay(1000);
  stripReset();
}

void LightPattern2(){
  topStripLight(Color(0, 255, 0), 0);
  middleStripLight(Color(0, 255, 0), 0);
  bottomStripLight(Color(0, 255, 0), 0);
  topRightStripLight(Color(0, 255, 0), 0);
  bottomLeftStripLight(Color(0, 255, 0), 0);
  delay(1000);
  stripReset();
}

void LightPattern3(){
  topRightStripLight(Color(0, 0, 255), 0);
  bottomRightStripLight(Color(0, 0, 255), 0);
  topStripLight(Color(0, 0, 255), 0);
  middleStripLight(Color(0, 0, 255), 0);
  bottomStripLight(Color(0, 0, 255), 0);
  delay(1000);
  stripReset();
}

void LightPattern4(){
  middleStripLight(Color(255, 0, 255), 0);
  topLeftStripLight(Color(255, 0, 255), 0);
  topRightStripLight(Color(255, 0, 255), 0);
  bottomRightStripLight(Color(255, 0, 255), 0);
  delay(1000);
  stripReset();
}

void LightPattern5(){
  topStripLight(Color(255, 0, 0), 0);
  middleStripLight(Color(255, 0, 0), 0);
  bottomStripLight(Color(255, 0, 0), 0);
  topLeftStripLight(Color(255, 0, 0), 0);
  bottomRightStripLight(Color(255, 0, 0), 0);
  delay(1000);
  stripReset();
}

void LightPattern6(){
  topStripLight(Color(0, 255, 0), 0);
  middleStripLight(Color(0, 255, 0), 0);
  bottomStripLight(Color(0, 255, 0), 0);
  topLeftStripLight(Color(0, 255, 0), 0);
  bottomLeftStripLight(Color(0, 255, 0), 0);
  bottomRightStripLight(Color(0, 255, 0), 0);
  delay(1000);
  stripReset();
}

void LightPattern7(){
  topStripLight(Color(0, 0, 255), 0);
  topRightStripLight(Color(0, 0, 255), 0);
  bottomRightStripLight(Color(0, 0, 255), 0);
  delay(1000);
  stripReset();
}

void LightPattern8(){
  topStripLight(Color(255, 0, 255), 0);
  middleStripLight(Color(255, 0, 255), 0);
  bottomStripLight(Color(255, 0, 255), 0);
  topLeftStripLight(Color(255, 0, 255), 0);
  bottomLeftStripLight(Color(255, 0, 255), 0);
  topRightStripLight(Color(255, 0, 255), 0);
  bottomRightStripLight(Color(255, 0, 255), 0);
  delay(1000);
  stripReset();
}

void LightPattern9(){
  topStripLight(Color(255, 0, 0), 0);
  middleStripLight(Color(255, 0, 0), 0);
  topLeftStripLight(Color(255, 0, 0), 0);
  topRightStripLight(Color(255, 0, 0), 0);
  bottomRightStripLight(Color(255, 0, 0), 0);
  bottomStripLight(Color(255, 0, 0), 0);
  delay(1000);
  stripReset();
}

void LightPattern0(){
  topStripLight(Color(0, 255, 0), 0);
  bottomStripLight(Color(0, 255, 0), 0);
  topLeftStripLight(Color(0, 255, 0), 0);
  topRightStripLight(Color(0, 255, 0), 0);
  bottomLeftStripLight(Color(0, 255, 0), 0);
  bottomRightStripLight(Color(0, 255, 0), 0);
  delay(1000);
  stripReset();
}

void stripReset(){
  for(int i=0; i<32; i++){
    strip.setPixelColor(i, Color(0,0,0));
    strip.show();
  }
}

void ultrasonic(){
    long duration;

    // Sensor is triggered by a HIGH pulse of 2 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin, LOW);

    // The same pin is used to read the signal from the sensor: a HIGH
    // pulse whose duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(pingPin, INPUT);
    duration = pulseIn(pingPin, HIGH);
    
    /* The speed of sound is 340 m/s or 29 microseconds per centimeter.
       The ping travels out and back, so to find the distance of the
       object we take half of the distance travelled.*/
    cm = duration / 29 / 2;

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
