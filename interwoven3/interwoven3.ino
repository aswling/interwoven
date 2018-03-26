//sending pulse to get distance: https://www.maxbotix.com/Arduino-Ultrasonic-Sensors-085/
//LED brightness based on distance: http://easyarduino.webs.com/ultrasonicfadeled.htm
//wiring NeoPixel: https://core-electronics.com.au/tutorials/ws2812-addressable-leds-arduino-quickstart-guide.html

#include <FastLED.h>
#define NUM_LEDS 30 //number of LEDS in strip
CRGB leds[NUM_LEDS];
#define PIN 6 //data pin in pin 6
#define COLOR_ORDER RGB;

const int sensorPin = 0; //sensor in analog pin 0
int distance1, distance2;
int fadeValue;

void setup() {
  Serial.begin(9600); //start serial monitor
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
}

void loop() {
  distance1 = analogRead(sensorPin)*5; //read sensor distance and convert to mm
  distance2 = 300 - distance1;
  fadeValue = map(distance2, 0, 300, 0, 255);

  if (distance1 <= 300) {
    FastLED.setBrightness(fadeValue);
    FastLED.show();  
  } else if (distance1 > 300) {
    FastLED.setBrightness(0);
  }
  
  Serial.print(distance1);
  Serial.print("mm");
  Serial.println();
  Serial.print("fade value: ");
  Serial.println(fadeValue);
  delay(300);

}
