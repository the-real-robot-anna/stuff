const int BUTTON_PIN =  2;  // define pins
const int LED_PIN    = 13;
const int POT_PIN    = A0;
const int ENABLE_PIN = 9;

int ledState = LOW;     // current state of LED
int lastButtonState;    // previous state of button
int currentButtonState = 0; // current state of button
int motorSpeed = 0;



void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN,    OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);

  digitalWrite(ENABLE_PIN, LOW);  // start with motor off
}



void loop() {

  // save the previous state and read new status
  lastButtonState    = currentButtonState;
  currentButtonState = digitalRead(BUTTON_PIN);

  // toggle the LED
  if(lastButtonState == HIGH && currentButtonState == LOW) { // only trigger when button is released, ie. high to low
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState); 
  }

  if (ledState == 1) {
    motorSpeed = analogRead(POT_PIN)/4;  // read POT to set motor speed
    analogWrite(ENABLE_PIN, motorSpeed); // run the motor at that speed
  } else {
    analogWrite(ENABLE_PIN, 0);
  }
  Serial.println((String)"ledState: "+ledState+ ", motorSpeed: "+motorSpeed); // debug
  
  delay(50);
}
