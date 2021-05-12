const int leds[] = {13,12,11};
const int l = sizeof(leds);
const int tiempo =  1000;
int cont = 0;

void setup() {
    for(int led: leds) {
        pinMode(led, OUTPUT);
    }
}

void loop() {
	accion();
}

void accion() {
    cont += 1;
    if (cont%2 == 0) {
        encenderPares(tiempo);
    }  
    else {
        encenderImpares(tiempo);
    }
}

void encenderPares(int duracion) {
    for(int i = 0; i < l; i++ ){ 
        if (i%2 == 0) {
            digitalWrite(leds[i], HIGH);
        }  
    }
    delay(duracion);
    for(int i = 0; i < l; i++ ){ 
        if (i%2 == 0) {
            digitalWrite(leds[i], LOW);
        }  
    }
}

void encenderImpares(int duracion) {
    for(int i = 0; i < l; i++ ){ 
        if (i%2 != 0) {
            digitalWrite(leds[i], HIGH);
        }  
    }
    delay(duracion);
    for(int i = 0; i < l; i++ ){ 
        if (i%2 != 0) {
            digitalWrite(leds[i], LOW);
        }  
    }
}