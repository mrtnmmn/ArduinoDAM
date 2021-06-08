#include <DHT.h>
#define DHTTYPE DHT11 

const int pinDht = 5;

DHT dht(pinDht, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
	delay(2000);
  int time = millis();

	Serial.print("TIEMPO: ");
  Serial.println(time);
  Serial.print("HUMEDAD: ");
  Serial.println(dht.readHumidity());
  Serial.print("TEMPERATURA: ");
  Serial.println(dht.readTemperature());
}
