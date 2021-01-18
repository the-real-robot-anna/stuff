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
  RGB_color(255, 0, 0); // Red
  delay(1000);
  RGB_color(0, 255, 0); // Green
  delay(1000);
  RGB_color(0, 0, 255); // Blue
  delay(1000);
  RGB_color(255, 255, 125); // Raspberry
  delay(1000);
  RGB_color(0, 255, 255); // Cyan
  delay(1000);
  RGB_color(255, 0, 255); // Magenta
  delay(1000);
  RGB_color(255, 255, 0); // Yellow
  delay(1000);
  RGB_color(255, 255, 255); // White
  delay(1000);    
}


void RGB_color(int red_value, int green_value, int blue_value)
 {
  analogWrite(RED_PIN, red_value);
  analogWrite(GREEN_PIN, green_value);
  analogWrite(BLUE_PIN, blue_value);
}
