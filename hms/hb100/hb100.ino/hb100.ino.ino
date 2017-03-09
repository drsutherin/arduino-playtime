/* FreqMeasure - Example with Serial output
 * http://www.pjrc.com/teensy/td_libs_FreqMeasure.html
 * 
 * Slightly modified by @3zuli for use with HB100 doppler radar module
 *
 * This example code is in the public domain.
 *
 * Frequency input pin: 8. Connect the IF pin from the preamp board to this pin.
 * This should work with Arduino Uno, Nano, Pro mini and simillar.
 * For other boards, see the FreqMeasure documentation (link above).
 */
 
 
#include "FreqMeasure/FreqMeasure.h"

void setup() {
  Serial.begin(57600);
  FreqMeasure.begin();
}

double sum=0;
int count=0;

void loop() {
  if (FreqMeasure.available()) {
    // average 30 readings together
    sum = sum + FreqMeasure.read();
    count = count + 1;
    if (count > 30) {
      float frequency = FreqMeasure.countToFrequency(sum / count);
      float spd = frequency / 1.425   // convert from freq to cm/s 
      Serial.print("Frequency: ");
      Serial.print(frequency);
      Serial.print(" Hz\t");

      Serial.print("Speed: ");
      Serial.print(spd);
      Serial.print(" cm/s");
      sum = 0;
      count = 0;
    }
  }
}

