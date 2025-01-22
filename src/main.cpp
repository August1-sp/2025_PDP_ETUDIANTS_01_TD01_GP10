#include <Arduino.h>
#include <DHT.h>

// Define the pins that we will use
#define CAPTEUR 33
#define LED 25
#define DHTTYPE DHT11   

DHT dht(CAPTEUR, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Effectuer une mesure toutes les 5s
  
  // Afficher l'humidité relative avec un peu de formatage

  // Afficher la température avec un peu de formatage

   // Lecture des valeurs du capteur
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
    
  // Vérification si la lecture a réussi
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
  
  delay(5000); 
}



