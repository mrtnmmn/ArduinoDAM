const int leds[] = {13, 12, 11};
const int tiempo = 1000;

void setup() {
    for (int led: leds)	{
        pinMode(led, OUTPUT);
    }
}

void loop() {
    encender();
    delay(tiempo);
}

void encender() {
    for(int led: leds) {
        digitalWrite(led, HIGH);
    }
    delay(tiempo);
    for(int led: leds) {
        digitalWrite(led, LOW);
    }
}