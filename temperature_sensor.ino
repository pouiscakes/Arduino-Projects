const int sensorPin = A0;
const float baselineTemp = 22.0;

void setup() {
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  
  //int FIRSTsensorVal = analogRead(sensorPin);
  //baselineTemp = FIRSTsensorVal;
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  
  Serial.print(", degrees C: ");
  float temperature = (voltage - .5) * 100;
  Serial.print(temperature);
  
  Serial.print(", degrees F: ");
  float fahrenheit = temperature * 9.0/5.0 + 32;
  Serial.println(fahrenheit);
  
  if(temperature < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}
