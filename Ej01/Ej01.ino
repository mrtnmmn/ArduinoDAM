const int pinLed = 13;

const int tiempoOn = 500;
const int tiempoOff = 100;

void setup() {
    pinMode(pinLed, OUTPUT);
}

void loop() {
    activaLed(pinLed, tiempoOn);
    delay(tiempoOff);
}

void activaLed(int pin, int tiempo) {
    digitalWrite(pinLed, HIGH);
    delay(tiempo);
    digitalWrite(pinLed, LOW);
}