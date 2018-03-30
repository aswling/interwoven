#include <Adafruit_NeoPixel.h>
#ifdef _AVR_
  #include <avr/power.h>
#endif

#define PIN 6 //strip pin
const int sensorPin = 0; //ultrasonic pin
int distance1, distance2;
int fadeValue; //brightness of strip

int pixels[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,
30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,
60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89};

Adafruit_NeoPixel strip = Adafruit_NeoPixel(90, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600); //start serial monitor
  strip.begin();
//  strip.show(); //initialize all pixels to "off"
}

void loop() {
  distance1 = analogRead(sensorPin)*5; //read sensor distance and convert to mm
  distance2 = 600 - distance1; //distance2 maps to fadeValue if distance is less than 600mm (2ft)
  fadeValue = map(distance2, 0, 600, 0, 255); //distance 0-600 brightness 0-255

//  *calls pixel array (!!!FINAL CODE!!!)*
for (int i = 0; i < 90; i++) {
  if (distance1 <= 600) {
      strip.setPixelColor(pixels[i], strip.Color(fadeValue,fadeValue,fadeValue)); //white
      strip.show(); //!!!sends the updated pixel color to the hardware!!! if u delete this u die
  } else if (distance1 > 600) {
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
