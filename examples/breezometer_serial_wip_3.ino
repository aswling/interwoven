#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN 6

int inString;
int inByte;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, PIN, NEO_GRB + NEO_KHZ800);

void establishContact(){
  while (Serial.available() <= 0) { //while port is empty
    Serial.write(0);
    delay(300);
    Serial.println("establishContact");
  }
}
void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  
  strip.begin();
  strip.show();

  establishContact();

}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void loop() {
  //colorWipe(strip.Color(255, 0, 0), 0);   // Red
 //Serial.println(Serial.available());
  if (Serial.available() >= 13) { //if any serial available, read
     int aqiData[13];
     //Serial.println("colorwipe");
     aqiData[0] = Serial.parseInt();
     aqiData[1] = Serial.parseInt();
     aqiData[2] = Serial.parseInt();
     aqiData[3] = Serial.parseInt();
     aqiData[4] = Serial.parseInt();
     aqiData[5] = Serial.parseInt();
     aqiData[6] = Serial.parseInt();
     aqiData[7] = Serial.parseInt();
     aqiData[8] = Serial.parseInt();
     aqiData[9] = Serial.parseInt();
     aqiData[10] = Serial.parseInt();
     aqiData[11] = Serial.parseInt();
     aqiData[12] = Serial.parseInt();
     for(int i = 0; i < 13; i++) {
      Serial.println(aqiData[i]);
     }
  }
}

