#include <Arduino.h>
#include "w7a8n1y4a_radiation.h"

#define RADIATION_PIN D7

w7a8n1y4a_radiation  radiation;
void ICACHE_RAM_ATTR ISR(){
  radiation.radiation_count();
}

void setup() {
  Serial.begin(115200);
  pinMode(RADIATION_PIN, INPUT);
  interrupts();
  attachInterrupt(RADIATION_PIN, ISR, FALLING);
}

void loop() {   
  Serial.println(String(radiation.radiation_count_all_time()) + '\t' + String(radiation.radiation_cpm(),5) + '\t' + String(radiation.radiation_uSv(),5) + '\t' + String(radiation.radiation_uR(), 5));
  delay(100);
}