// Piano.c
// This software configures the off-board piano keys
// Runs on LM4F120 or TM4C123
// Program written by: Emily Steck and Trey Boehm
// Date Created: 2017-03-06
// Last Modified: 2017-03-21
// Lab number: 6
// Hardware connections
//     PB0 through PB5: DAC output bits
//     PE0 through PE2: Synthesizer button inputs

// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "Sound.h"
#include "Piano.h"

// The three pitches activated by the button presses
unsigned int pianoNotes[] = {
    0,  // 0x0: If no buttons, play no sound
    C4, // 0x1: Button 1
    D4, // 0x2: Button 2
    0,  // 0x3: Nothing
    E4, // 0x4: Button 3
    0,  // 0x5: Nothing
    0,  // 0x6: Nothing
    0,  // 0x7: Nothing
};

// **************Piano_Init*********************
// Initialize piano key inputs, called once 
// Input: none 
// Output: none
void Piano_Init(void) {
    uint8_t i;
    SYSCTL_RCGC2_R |= 0x010;
    for (i = 0; i < 4; i++) ; // Wait for clock to stabilize
    GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTE_DIR_R &= ~0x07;
    GPIO_PORTE_DEN_R |= 0x07;
}

// **************Piano_In*********************
// Input from piano key inputs 
// Input: none 
// Output: 0 to 7 depending on keys
// 0x01 is just Key0, 0x02 is just Key1, 0x04 is just Key2
uint32_t Piano_In(void) {
    return (GPIO_PORTE_DATA_R & 0x07);
}
