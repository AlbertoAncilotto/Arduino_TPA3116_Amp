#include <Segm.h>

//Arduino pins to display pins
uint8_t pins[7]={10,9,8,7,6,5,4};

//Display pins for a segment, clockwise (0 is the top segment, 7 is the center dash). Fist value is the positive pin, second is the negative one
uint8_t pairs[4][7][2] = {
    //position 0
    {
        {2,1},
        {3,1},
        {4,1},
        {5,1},
        {6,1},
        {7,1},
        {3,2},
    },

    //position 1
    {
        {1,2},
        {1,3},
        {1,4},
        {1,5},
        {1,6},
        {1,7},
        {2,3},
    },

    //position 2
    {
        {4,3},
        {5,3},
        {6,3},
        {7,3},
        {5,4},
        {6,4},
        {7,4},
    },

    //position 3
    {
        {3,4},
        {3,5},
        {3,6},
        {3,7},
        {4,5},
        {4,6},
        {4,7},
    },
};

//sequence of segments to display a number (9 is used as an empty flag)
uint8_t sequences[10][7] = {
    {0,1,2,3,4,5,9}, //0
    {1,2,9,9,9,9,9}, //1
    {0,1,3,4,6,9,9}, //2
    {0,1,2,3,6,9,9}, //3
    {1,2,5,6,9,9,9}, //4
    {0,2,3,5,6,9,9}, //5
    {0,2,3,4,5,6,9}, //6
    {0,1,2,9,9,9,9}, //7
    {0,1,2,3,4,5,6}, //8
    {0,1,2,3,5,6,9}, //9
};


void print_number(uint8_t pos, uint8_t num){
    //Return if the inpjut cannot be displayed
    if (num<0 || num>99)
    {
        return;
    }

    //Print the two digits
    print_digit(pos*2+1, num%10);
    print_digit(pos*2, num/10);
}

void print_digit(uint8_t pos, uint8_t num){
    //Return if the inpjut cannot be displayed
    if (num<0 || num>9)
    {
        return;
    }
    
    //Set the correct semgents
    for (uint8_t i = 0; i < 7; i++)
    {
        uint8_t bar=sequences[num][i];
        if (bar==9)
        {
            break;
        }
        set_segment(pos, bar);
    }
    
}


void test_disp(){
    //Cycle each segment of each position
    for (uint8_t pos = 0; pos < 4; pos++)
    {
        for (uint8_t i = 0; i < 7; i++)
        {
            set_segment(pos, i);
        }
    }
}

void set_segment(uint8_t pos, uint8_t num){
 for (uint8_t i = 0; i < 7; i++)
 {
    pinMode(pins[i], INPUT);
 }

 pinMode(pins[pairs[pos][num][0]-1], OUTPUT);
 digitalWrite(pins[pairs[pos][num][0]-1], HIGH);

 pinMode(pins[pairs[pos][num][1]-1], OUTPUT);
 digitalWrite(pins[pairs[pos][num][1]-1], LOW);

 delayMicroseconds(SEGMENT_US);
 
}