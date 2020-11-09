#ifndef SENSE_H /* include guards */
#define SENSE_H

#include <Arduino.h>

#define TEMP_PIN A5
#define VOLT_PIN A6
#define AMP_PIN A0
#define R_SENSE 0.1 //sense resistor value in ohms

/* Print a 0-99 number in one of the two places */
float get_volts();

/* Print a single digit (0-9) at one of the four 7 segment positions (0-3) */
float get_amps();

/* Test routine */
float get_temp();


#endif /* SENSE_H */