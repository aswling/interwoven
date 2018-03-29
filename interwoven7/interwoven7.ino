#include <Adafruit_NeoPixel.h>
#ifdef _AVR_
  #include <avr/power.h>
#endif

#define PIN 6 //strip pin
const int sensorPin = 0; //ultrasonic pin
int distance1, distance2;
int fadeValue; //brightness of strip

int pixels[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29};

Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600); //start serial monitor
  strip.begin();
//  strip.show(); //initialize all pixels to "off"
}

void loop() {
  distance1 = analogRead(sensorPin)*5; //read sensor distance and convert to mm
  distance2 = 300 - distance1; //distance2 maps to fadeValue if distance is less than 300mm (1ft)
  fadeValue = map(distance2, 0, 300, 0, 255); //distance 0-300 brightness 0-255

//  *calls pixel array (!!!FINAL CODE!!!)*
for (int i = 0; i < 30; i++) {
  if (distance1 <= 300) {
      strip.setPixelColor(pixels[i], strip.Color(fadeValue,fadeValue,fadeValue)); //white
      strip.show(); //!!!sends the updated pixel color to the hardware!!! if u delete this u die
  } else if (distance1 > 300) {
      strip.setPixelColor(pixels[i], strip.Color(0,0,0)); //black    
      strip.show();
  }
}
  
  Serial.print(distance1);
  Serial.print("mm");
  Serial.println();
  Serial.print("fade value: ");
  Serial.println(fadeValue);
  delay(30);

//  *test pixel 0*
//  strip.setPixelColor(0,strip.Color(fadeValue, fadeValue, fadeValue));
//  strip.show();

//  *if function combined with NeoPixel simple example*
//  if (distance1 <= 300) {
//    strip.setPixelColor(0, strip.Color(255,0,0)); //red
//    strip.show(); //sends the updated pixel color to the hardware
//  } else if (distance1 > 300) {
//    strip.setPixelColor(0, strip.Color(0,0,0)); //black
//    strip.show();
//  }

//  *fade pixel 0*
//  if (distance1 <= 300) {
//    strip.setPixelColor(0, strip.Color(fadeValue,fadeValue,fadeValue)); //white
//    strip.show(); //sends the updated pixel color to the hardware
//  } else if (distance1 > 300) {
//    strip.setPixelColor(0, strip.Color(0,0,0)); //black
//    strip.show();
//  }

//  *fade pixels 0-4*
//  if (distance1 <= 300) {
//    strip.setPixelColor(0, strip.Color(fadeValue,fadeValue,fadeValue)); //white
//    strip.setPixelColor(1, strip.Color(fadeValue,fadeValue,fadeValue));
//    strip.setPixelColor(2, strip.Color(fadeValue,fadeValue,fadeValue));
//    strip.setPixelColor(3, strip.Color(fadeValue,fadeValue,fadeValue));
//    strip.setPixelColor(4, strip.Color(fadeValue,fadeValue,fadeValue));
//    strip.show(); //sends the updated pixel color to the hardware
//  } else if (distance1 > 300) {
//    strip.setPixelColor(0, strip.Color(0,0,0)); //black
//    strip.setPixelColor(1, strip.Color(0,0,0));
//    strip.setPixelColor(2, strip.Color(0,0,0));
//    strip.setPixelColor(3, strip.Color(0,0,0));
//    strip.setPixelColor(4, strip.Color(0,0,0));
//    strip.show();
//  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(10);
  }
}
