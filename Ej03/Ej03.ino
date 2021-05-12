int leds[] = {13, 12, 11, 10};
int buzzer = 2;
int buzzDuration = 50;
int ledDuration = 1000; 
int l = sizeof(leds);

int lastLed = leds[l-1];

void setup() {
    Serial.begin(9600);
	pinMode(2, OUTPUT);
    for(int led: leds) {
       	pinMode(led, OUTPUT); 
    }
}

void loop() {
    for (int led: leds) {
        Serial.println(lastLed);
        if (led == 10) {
            buzz();
        }
        turnOn(led, ledDuration);
    }
}

void buzz() {
    digitalWrite(buzzer, HIGH);
    delay(buzzDuration);
    digitalWrite(buzzer, LOW);
}
void turnOn(int led, int duration) {
    digitalWrite(led, HIGH);
    delay(duration);
    digitalWrite(led, LOW);
}

