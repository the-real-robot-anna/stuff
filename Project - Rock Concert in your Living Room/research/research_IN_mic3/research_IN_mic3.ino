/*
 * Code from x
*/

#define MIC_PIN   5     // Microphone
#define DC_OFFSET 0     // DC offset in mic signal. This value should be subtracted from raw sample. Adjust as required.

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(MIC_PIN)- DC_OFFSET;
  Serial.println(sensorValue);
  delay(10);
}
