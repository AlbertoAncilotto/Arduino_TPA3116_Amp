#include <Sense.h>

float get_volts(){
    float in_v=(float)analogRead(VOLT_PIN)/1024.0*5.0;
    return in_v*(27.0+5.1)/5.1;
}

float get_amps(){
    float shunt_v=(float)analogRead(AMP_PIN)/1024.0*5.0;
    return shunt_v/R_SENSE;
}


float get_temp(){
    float therm_v=(float)analogRead(TEMP_PIN);
    float temp = -0.1128*therm_v + 82.949; //data obtained from linear interpolation during calibration
    return temp;
}