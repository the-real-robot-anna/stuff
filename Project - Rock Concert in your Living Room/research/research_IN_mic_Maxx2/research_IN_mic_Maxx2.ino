
const long interval = 10000; // this is the interval where the Microphone MAX4466 is doing a new measurement
const int sampleWindow = 1000 ; // Sample window width in mS (50 mS = 20Hz), this is the window in milliseconds where the measurement is done

uint32_t timer = millis();

void misuraEinvio() {
   
   unsigned long startMillis= millis();  // Start of sample window
   
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   while (millis() - startMillis < sampleWindow)
   {

      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
      //SerialUSB.print(sample);
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = ((peakToPeak * 3.3) / 1024) * 0.707;  // convert to RMS voltage
   // as the mic sensitivity is -44 +-2 dB converted to V RMS / PA is 0.000631
   double first = log10(volts/0.00631)*20;
   // gain is 25, 94 is a PA expressed as dB Spl
   double second = first + 94 - 44 - 25;
