//sending pulse to get distance: https://www.maxbotix.com/Arduino-Ultrasonic-Sensors-085/
//LED brightness based on distance: http://easyarduino.webs.com/ultrasonicfadeled.htm
//wiring NeoPixel: https://core-electronics.com.au/tutorials/ws2812-addressable-leds-arduino-quickstart-guide.html

#include <FastLED.h>
#define NUM_LEDS 30 //number of LEDS in strip
#define DATA_PIN 6 //data pin in pin 6
CRGB leds[NUM_LEDS]; //define array of LEDs

const int anPin1 = 0; //sensor in analog pin 0
long distance1, distance2; //distance1 = sensor reading distace, distance2 = LED fade distance
int fadeValue;

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600); //start serial monitor
}

void read_sensors(){
  //scale factor is (Vcc/1024) per 5mm. A 5V supply yields ~4.9mV/5mm
  //arduino analog pin goes from 0 to 1024, so the value has to be multiplied by 5 to get range in mm
  distance1 = analogRead(anPin1)*5;
}

void fadeLED() {
  //if distance is less than 300mm then do the following:
  if (distance1<=300) {fill_solid( &(leds[0]), NUM_LEDS, CRGB::Blue);
  FastLED.show();
  } else if (distance1>300) {fill_solid( &(leds[0]), NUM_LEDS, CRGB::Black);
  FastLED.show();
  } delay(100);
  
  //maps the LED brightness inversely proportional to the distance 
  //distance2 = 914.4 - distance1;
  //fadeValue = map(distance2 , 0, 914.4, 0, 254);

  //analogWrite(DATA_PIN, fadeValue);  //writes fadeValue to pin 9 
  //} else {
  //analogWrite(DATA_PIN, 0);  //if distance > 914.4mm then switch off  
  //}
}

void print_all(){
  Serial.print(distance1);
  Serial.print("mm");
  Serial.println();
  //Serial.print("fade value");
  //Serial.println(fadeValue);
}

void loop() {
  read_sensors();
  fadeLED();
  print_all();
  delay(300); //slow down serial monitor
}
