//sending pulse to get distance: https://www.maxbotix.com/Arduino-Ultrasonic-Sensors-085/
//LED brightness based on distance: http://easyarduino.webs.com/ultrasonicfadeled.htm

const int anPin1 = 0; //sensor in analog pin 0
const int ledPin = 9; //LED in pin 9
long distance1, distance2; //distance1 = sensor reading distace, distance2 = LED fade distance
int fadeValue;

void setup() {
  Serial.begin(9600);
}

void read_sensors(){
  //scale factor is (Vcc/1024) per 5mm. A 5V supply yields ~4.9mV/5mm
  //arduino analog pin goes from 0 to 1024, so the value has to be multiplied by 5 to get range in mm
  distance1 = analogRead(anPin1)*5;
}

void print_all(){
  Serial.print("S1");
  Serial.print(" ");
  Serial.print(distance1);
  Serial.print("mm");
  Serial.println();
  Serial.print("fade value");
  Serial.println(fadeValue);
}

void fadeLED() {
  if (distance1<914.4) {//if distance is less than 914.4mm (3ft) then do the following:

  //maps the LED brightness inversely proportional to the distance 
  distance2 = 914.4 - distance1;  
  fadeValue = map(distance2 , 0, 914.4, 0, 254);

  analogWrite(ledPin, fadeValue);  //writes fadeValue to pin 9 
 } else {
  analogWrite(ledPin, 0);  //if distance > 914.4mm then switch off  
  }
}

void loop() {
  read_sensors();
  fadeLED();
  print_all();
  delay(300); //slow down serial monitor
}

