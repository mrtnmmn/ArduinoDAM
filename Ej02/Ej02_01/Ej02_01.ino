const int leds[] = {13, 12, 11};
const int tiempoOn = 500;

void setup() {
    for (int elemento: leds) {
        pinMode(elemento, OUTPUT);
    }
}

void loop() {
	for (int elemento: leds) {
        encenderLed(elemento, tiempoOn);
    }
}

void encenderLed(int puerto, int tiempo) {
    digitalWrite(puerto, HIGH);
    delay(tiempo);
    digitalWrite(puerto, LOW);
}