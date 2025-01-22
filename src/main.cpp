#include <Arduino.h>

// Define the pins that we will use
#define CAPTEUR 35
#define LED 25

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
}