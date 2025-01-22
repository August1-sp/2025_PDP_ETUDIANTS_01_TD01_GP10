#include <Arduino.h>
#include <DHT.h>
#include <esp_sleep.h>


// Define the pins that we will use
#define CAPTEUR 33
#define LED 25
#define DHTTYPE DHT11 
#define uS_TO_S_FACTOR 1000000  // Conversion factor for seconds to microseconds
#define TIME_TO_SLEEP 10        // Time ESP32 will sleep in seconds


DHT dht(CAPTEUR, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Échec de lecture du capteur DHT!");
    delay(2000);
    return;
  }
  
  Serial.print("Température: ");
  Serial.print(temperature);
  Serial.print("°C, Humidité: ");
  Serial.print(humidity);
  Serial.println("%");

  esp_deep_sleep_start();//met le deep sleep en marche

}

void loop() {

  Serial.println("CA MARCHE PAS (si tu vois ça :)!!!");//c'est vide, c'était juste pour vérif
  delay(5000); 
}



