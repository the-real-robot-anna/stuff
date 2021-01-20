// Define output constants
#define GREEN_PIN 10
#define RED_PIN   11
#define BLUE_PIN   9

// Define color codes
int TEMPO = 500;
int i = 0;

void setup() {
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN,   OUTPUT);
  pinMode(BLUE_PIN,  OUTPUT);
  Serial.begin(9600);
}


void loop() {

  // try lots of colors
  RGB_color(255,0,0); // red
  delay(TEMPO);
  RGB_color(0,255,0); // green
  delay(TEMPO);
  RGB_color(0,0,255); // blue
  delay(TEMPO);
  RGB_color(255,255,125); // raspberry
  delay(TEMPO);
  RGB_color(0,255,255); // cyan
  delay(TEMPO);
  RGB_color(255,0,255); // magenta
  delay(TEMPO);
  RGB_color(255,255,0); // yellow
  delay(TEMPO);
  RGB_color(255,255,255); // white
  delay(TEMPO);

  // turn up and down the intensity, keep one color constant
  for (i=0;i<=255;i++) {
    RGB_color(i,0,i); // green
    delay(5);
  }
  for (i=255;i>=0;i--) {
    RGB_color(i,0,i); // green
    delay(5);
  }
}


void RGB_color( int red_value, int green_value, int blue_value )
{
  analogWrite(RED_PIN,   red_value);
  analogWrite(GREEN_PIN, green_value);
  analogWrite(BLUE_PIN,  blue_value);
}
