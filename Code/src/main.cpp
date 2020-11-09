#include <Arduino.h>
#include "Segm.h"
#include "Sense.h"

#define SENSE_INTERVAL 100 // in ms
#define AVG_SAMPLES 20

uint32_t last_measure_time = 0;
uint32_t last_max_time = 0;
float volts;
float amps;
float temp;
float amps_previous[AVG_SAMPLES];
uint8_t amps_last=0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  //Only update the display some number of times per second to avoid flickering
  if (millis()-last_measure_time>SENSE_INTERVAL)
  {
    volts=get_volts();

    //As current varies rapidly, use a moving average for measuring
    amps_previous[amps_last] = get_amps();
    amps_last=(amps_last++) % AVG_SAMPLES;

    amps=0;
    for (uint8_t i = 0; i < AVG_SAMPLES; i++)
    {
      amps+=amps_previous[i]/AVG_SAMPLES;
    }
    
    temp=get_temp();
    last_measure_time=millis();
  }
  
  print_number(0, (uint8_t)(volts*amps));
  print_number(1, (uint8_t)temp);
}