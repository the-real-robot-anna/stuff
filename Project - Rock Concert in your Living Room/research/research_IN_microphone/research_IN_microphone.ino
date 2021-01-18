/*
Isolate just the microphone as input
*/

// Define input constants
#define DIGITAL_PIN 2
#define ANALOG_PIN 0

void setup() {
  pinMode(DIGITAL_PIN, INPUT); // set up input and output pins
  Serial.begin(9600);
}

void loop() {
  Serial.print("Digital: ");
  Serial.print(digitalRead(DIGITAL_PIN));
  Serial.print(" - Analog: ");
  Serial.println(analogRead(ANALOG_PIN));

  delay(1000);     
}
