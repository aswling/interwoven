int IRsensor = 0;
int sensorReading = 0; //store sensor value
int outputValue;

void setup() {
  Serial.begin(9600); //start serial monitor to print output
}

void loop() {
  //read distance from object (http://tinkcore.com/sharp-ir-gp2y0a41-skf/)
  float volts = analogRead(IRsensor)*0.0048828125;  //value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); //worked out from datasheet graph
  delay(300); // slow down serial port

  Serial.print("distance: ");
  Serial.println(distance);
}
