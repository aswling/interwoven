#include <Adafruit_NeoPixel.h>
#ifdef _AVR_
  #include <avr/power.h>
#endif

#define PIN 6 //strip pin
const int sensorPin = 0; //ultrasonic pin
int distance1, distance2;
int fadeValue; //brightness of strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600); //start serial monitor
  strip.begin();
//  strip.show(); //initialize all pixels to "off"
}

void loop() {
  distance1 = analogRead(sensorPin)*5; //read sensor distance and convert to mm
  distance2 = 300 - distance1;
  fadeValue = map(distance2, 0, 300, 0, 255); //distance 0-300 brightness 0-255

//  test pixel 1
//  strip.setPixelColor(1,strip.Color(fadeValue, fadeValue, fadeValue));
//  strip.show();

  if (distance1 <= 300) {
    colorWipe(strip.Color(fadeValue, fadeValue, fadeValue), 50);
  } else if (distance1 > 300) {
    colorWipe(strip.Color(0, 0, 0), 50);
  }
  
  Serial.print(distance1);
  Serial.print("mm");
  Serial.println();
  Serial.print("fade value: ");
  Serial.println(fadeValue);
  delay(10);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(10);
  }
}
