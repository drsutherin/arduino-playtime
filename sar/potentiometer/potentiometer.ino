int pot = 0;
int led = 13;
int val = 0;
unsigned long prev = 0, now;
uint16_t uVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(pot);
  now = millis();
  //Serial.print(now);
  //Serial.print(" ");
  //Serial.println(val);
  if (now > (prev+500)) {
    prev = now;
//    uVal = (uint16_t) val;
    Serial.print("Time: ");
    Serial.println(now);
    Serial.print("Value: ");
    Serial.println(val);
//    Serial.print("uVal: ");
//    Serial.println(uVal);
//    Serial.println();
  }
  if (val > 500) {  digitalWrite(led,HIGH); }
  else {  digitalWrite(led,LOW);  }
}
