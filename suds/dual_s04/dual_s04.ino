#include <NewPing.h>

#define TRIGGER_PIN_1  10    // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_1     9     // Arduino pin tied to echo pin on the ultrasonic sensor.
unsigned int d1;

#define TRIGGER_PIN_2  12    // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN_2     11    // Arduino pin tied to echo pin on the ultrasonic sensor.
unsigned int d2;

#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar_1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar_2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int green = 0;
int red = 1;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() {
  // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned long t = millis();
//  Serial.print("Time 1-1: ");
//  Serial.println(t);
  // Fire Sensor 1
  d1 = sonar_1.ping_cm();
  if (d1 < 25 && d1 > 0) {
    Serial.println("HELP");
    digitalWrite(green,HIGH);
  }
  else {
    digitalWrite(green,LOW);
  }

  Serial.print("Sensor 1: ");
  Serial.print(d1);
  Serial.print("cm\t\t");
  
//  Serial.print("Time 1-2: ");
//  Serial.println(t);
  
  delay(125);

//  Serial.print("Time 2-1: ");
//  Serial.println(t);
  
  // Fire Sensor 2
  d2 = sonar_2.ping_cm();
  if (d2 < 25 && d2 > 0) { Serial.println(); Serial.println("HELP"); digitalWrite(red,HIGH); }
  else {  digitalWrite(red,LOW);  }

  Serial.print("Sensor 2: ");
  Serial.print(d2);
  Serial.println("cm");

//  Serial.print("Time 2-2: ");
//  Serial.println(t);

  delay(125);
}
