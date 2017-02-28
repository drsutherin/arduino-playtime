// MULTICOLOR LED
int multi[] = {10,11,12};
int j = 0;

// POTENTIOMETER
int dial = 0;
int val = 0;

int current;

// COLORS
const boolean RED[]     = {1,0,0};
const boolean GREEN[]   = {0,1,0};
const boolean BLUE[]    = {0,0,1};
const boolean YELLOW[]  = {1,1,0};
const boolean CYAN[]    = {0,1,1};
const boolean MAGENTA[] = {1,0,1};
const boolean WHITE[]   = {1,1,1};
const boolean BLACK[]   = {0,0,0};

const boolean* COLORS[] = {RED,GREEN,BLUE,YELLOW,CYAN,MAGENTA,WHITE,BLACK};


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i <= 13; i++)  {
    pinMode(i,OUTPUT);
  }
}


void loop() {
  for (int i = 0; i < 5; i++) {
    // Read from potentiometer
    val = analogRead(dial);
    
    // Light up standard LEDs
    digitalWrite(i,HIGH);
    digitalWrite((9-i),HIGH);
    
    // Light up multicolor LED
    for (int k = 0; k < 3; k++) {
      digitalWrite(multi[k],COLORS[j][k]);
    }
    j = (j+1)%8;
    
    // Pause based on potentiometer value (0-1023ms)
    delay(val);
    
    // Turn standard LEDs off
    digitalWrite(i,LOW);
    digitalWrite((9-i),LOW);
  }
  

}
