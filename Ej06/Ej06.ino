const int led = 2;

const int ultraIn = 12;
const int ultraOut = 13;

boolean inRange = false;
boolean ledStatus = false;

long duration, distance; 

void setup() {
    pinMode(ultraOut, OUTPUT);
    pinMode(ultraIn, INPUT);
    pinMode(led, OUTPUT);
}

void loop() {
    rangeCheck();
    ledCheck();
}
         
void rangeCheck() {
    ultraLaunch();
    if (distance <+ 20) {
        inRange = true;
    }
    else {
        inRange = false;
    }
}

void ultraLaunch() {
    digitalWrite(ultraOut, LOW);
    delayMicroseconds(5);
    digitalWrite(ultraOut, HIGH);
    delayMicroseconds(10);
    digitalWrite(ultraOut, LOW);

    duration = pulseIn(ultraIn, HIGH);

    distance = duration * 10 / 292 / 2; 
}

void ledCheck() {
    if (inRange && not ledStatus) {
        digitalWrite(led, HIGH);
        ledStatus = true;
    }
    else if (not inRange && ledStatus) {
        digitalWrite(led, LOW);
        ledStatus = false;
    }
}