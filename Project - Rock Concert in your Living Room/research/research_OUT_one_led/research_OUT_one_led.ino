/*
Isolate just the microphone as input
*/

// Define output constants
#define GREEN_PIN 10
#define RED_PIN 11
#define BLUE_PIN 9
// Define color codes
//#define RED       (255, 0, 0);     // Red
//#define GREEN     (0, 255, 0);     // Green
//#define BLUE      (0, 0, 255);     // Blue

//#define RASPBERRY (255, 255, 125); // Raspberry

//#define CYAN      (0, 255, 255);   // Cyan
//#define MAGENTA   (255, 0, 255);   // Magenta
//#define YELLOW    (255, 255, 0);   // Yellow
//#define WHITE     (255, 255, 255); // White


void setup() {
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {

for (int i = 0; i <= 255; i++) {
for (int j = 0; j <= 255; j++) {
    RGB_color(j, 0, i);
    delay(10);
}
}

for (int i = 0; i >= 0; i--) {
for (int j = 0; j >= 0; j--) {
    RGB_color(j, 0, i);
    delay(10);
}
}

}

void RGB_color(int red_value, int green_value, int blue_value)
 {
  analogWrite(RED_PIN, red_value);
  analogWrite(GREEN_PIN, green_value);
  analogWrite(BLUE_PIN, blue_value);
}
