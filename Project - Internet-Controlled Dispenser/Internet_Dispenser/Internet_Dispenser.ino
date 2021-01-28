#include <Servo.h>
#define  DEBUG 1

Servo     theLever;
const int tempPin = 8;
      int switchState = 0;


void setup() {
  pinMode(tempPin,INPUT);   // temp: connect button switch to pin 8
  theLever.attach(3);       // connect the servo to pin 3

  #ifdef DEBUG 
  Serial.begin(9600);
  #endif
}


void loop() {

  switchState = digitalRead(tempPin);
  #ifdef DEBUG
  Serial.println((String)"switch="+switchState);
  #endif

  if(switchState == 1) {
    theLever.write(89);
    delay(500);
    theLever.write(0);
    delay(500);
  }

  delay(500);

}
