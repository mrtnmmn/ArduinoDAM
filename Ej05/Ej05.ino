#include <Servo.h>
Servo servo;
int angulo = 0;
int pinServo = 12;

const int pulsador = 13;

const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;

int aux1 = 7;
int aux2 = 2;
int mod = 0;

void setup() {
    for (int i = 2; i <= 8; i++) {
        pinMode(i, OUTPUT);
    }
    pinMode(pulsador, INPUT);  
    servo.attach(pinServo);
}

void loop() {
    if (digitalRead(pulsador) == LOW) {
        apagar7S();
    }
  
    while(digitalRead(pulsador) == HIGH) {
    moverServo();
    comprobarAngulo();

    if (mod == -1) {
        mover7D();
    }
    else { 
        mover7I();
    }
    escribir7();
  }
}

void apagar7S() {
    for (int i = 2; i <= 8; i++) {
        digitalWrite(A, LOW);
    }
}

void moverServo() {
    angulo += 2 * mod;
    servo.write(angulo);
}

void comprobarAngulo() {
    if (angulo == 180) {
        mod = -1;
    }
    else if (angulo == 0) { 
        mod = 1;
    }
}

void mover7D() {
    aux1 += 1;
    aux2 = aux1 + 1;  

    if(aux1 == 8) {
        aux1 = 2;
    }
    if(aux2 == 8) {
        aux2 =  2;
    }
}

void mover7I() {
    aux1 -= 1;
    aux2 = aux1 - 1;

    if(aux1 == 1) {
        aux1 = 7;
    }
    if(aux2 == 1) {
        aux2 =  7;
    }
}

void escribir7() {
    digitalWrite(aux1, HIGH);
    digitalWrite(aux2, HIGH);
    delay(50);
    digitalWrite(aux1, LOW);
    digitalWrite(aux2, LOW);
}