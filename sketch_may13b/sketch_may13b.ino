#define OFFMODE -1
#define ONMODE 0

const int LED = 13;

#include <Servo.h>
Servo servo;

int ServoPin = 6;
int angle = 0;

char ch;
int state = OFFMODE;

void setup() {
  pinMode(LED , OUTPUT);
  Serial.begin(115200);
  servo.attach(ServoPin);
}

void loop() {
  if (Serial.available()) {
    ch = Serial.read();
  }

  if (ch == 'a') {
    state = ONMODE;
  }

  else if (ch == 'c') {
    state = OFFMODE;
  }

  if (state == ONMODE) {
    for (angle = 90; angle < 180; angle++)
    {
      servo.write(angle);
      delay(30);
      digitalWrite(LED, HIGH);     
     }
    for (angle = 180; angle >= 90; angle--)
    {
      servo.write(angle);
      delay(30);
      digitalWrite(LED, LOW);
    }
  }
  
  else if(state == OFFMODE) {
    digitalWrite(LED, LOW);
  }
}



