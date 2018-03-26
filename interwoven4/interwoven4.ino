#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

const int ledPin = 6; //strip in pin 6
const int numLeds = 30; //number of LEDs
//const int sensorPin 0; //sensor in analog pin 0

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, ledPin, NEO_RGB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  pixels.setPixelColor(1, pixels.Color(150,0,0));
  pixels.setPixelColor(2, pixels.Color(0,150,0));
  pixels.setPixelColor(3, pixels.Color(0,0,150));
}

void loop() {
//  uint32_t low = strip.Color(0,0,0);
//  uint32_t high = strip.Color(150,150,150);
//
//  for(int i = 0; i<numLeds; i++){
//    strip.setPixelColor(i, high);
//    strip.show();
//  } delay(1000);
//    
//  for(int i = 0; i<numLeds; i++){
//    strip.setPixelColor(i, low);
//    strip.show();
//  } delay(1000);
}
