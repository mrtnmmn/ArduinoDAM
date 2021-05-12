#include <LiquidCrystal.h>

const int leds[] = {13, 12, 11};
const int tiempoDeAceleracion = 10000; // en diez segundos llega a su velocidad maxima
const int tiempoOnInicial = 500;
const int tiempoOnFinal = 50; // tiempo que se mantendra encendido cada led a la maxima velocidad
int tiempo = 0;
int tiempoOn = 0;
boolean acelera = true;


void setup(){
    for (int elemento: leds) {
        pinMode(elemento, OUTPUT);
    }
}

void loop(){
    for(int led: leds) {
        tiempoOn = calcularTiempo();
        encenderLed(led,tiempoOn);
    }

    if (tiempo > tiempoDeAceleracion ) {
        acelera = false;
    }
}

int calcularTiempo() { 
    tiempo = millis();
    if (acelera) {
        int sol = map(tiempo, 0 , tiempoDeAceleracion, tiempoOnInicial, tiempoOnFinal);
        return sol;
    }
    else {
        return tiempoOnFinal;
    }
    
}

void encenderLed(int puerto, int tiempo) {
    digitalWrite(puerto, HIGH);
    delay(tiempo);
    digitalWrite(puerto, LOW);
}