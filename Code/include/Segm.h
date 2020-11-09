#ifndef SEGM_H /* include guards */
#define SEGM_H

#include <Arduino.h>

#define SEGMENT_US 100 //how long to keep each segment on for

/* Print a 0-99 number in one of the two places */
void print_number(uint8_t pos, uint8_t num);

/* Print a single digit (0-9) at one of the four 7 segment positions (0-3) */
void print_digit(uint8_t pos, uint8_t num);

/* Test routine */
void test_disp();

/* Light up a single segment for SEGMENT_US */
void set_segment(uint8_t pos, uint8_t num);

#endif /* SEGM_H */