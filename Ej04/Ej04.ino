#include <Servo.h>

Servo servo;
int angulo = 0;
int pinServo = 9;

void setup() {
  servo.attach(pinServo);
}

void loop() {
    for(angulo  = 0; angulo  <= 180; angulo  += 1) {
        servo.write(angulo);
        delay(25);
    }

    for(angulo  = 180; angulo  >=0; angulo  -=1 ) {
        servo.write( angulo );
        delay(25);
    }
}