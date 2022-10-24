#define SENSOR_PIN 0
 
// Integer for sensor value
int sensorValue;


 
void setup() {
  
  // Set up serial port
  Serial.begin(9600);
}
 
void loop() {
  setPwmFrequency(9, 8);
  // Read sensor value
  sensorValue = analogRead(SENSOR_PIN);
  
  // Add "fake" plots to stabilize Y axis
  Serial.print(0); // To freeze the lower limit
  Serial.print(" ");
  Serial.print(1500); // To freeze the upper limit
  Serial.print(" ");
  
  // Print value to Serial Monitor
  Serial.println(sensorValue);
  
}
