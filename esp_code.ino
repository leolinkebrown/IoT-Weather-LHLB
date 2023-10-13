#include "DHT.h"

#define DHTPIN 17
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  delay(1000); 

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Could not read DHT11!");
    return;
  }

  Serial.print(h);
  Serial.print(",");
  Serial.print(t);
  Serial.println();
}