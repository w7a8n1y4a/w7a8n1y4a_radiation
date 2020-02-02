#include "w7a8n1y4a_radiation.h"

void w7a8n1y4a_radiation::radiation_count(){
  count++;
  counts++;
}
uint32_t w7a8n1y4a_radiation::radiation_count_all_time(){
  return counts;
}

float w7a8n1y4a_radiation::radiation_cpm(){
  if(millis() - millis_radiation >= MINUTE){
    cpm = count;
    count = 0;
    millis_radiation = millis();
  }
  return cpm;
}
float w7a8n1y4a_radiation::radiation_uSv(){
  return radiation_cpm() * TUBE_FACTOR;
}
float w7a8n1y4a_radiation::radiation_uR(){
  return radiation_cpm() * TUBE_FACTOR * 100;
}
