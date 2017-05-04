/* Buttons.c
 * Read input from the three buttons on the protoboard
 * Trey Boehm and Emily Steck, 2017-05-03
 * PD0, PD1, and PD2 are positive-logic switches
 */
 
#include <stdint.h>
#include "tm4c123gh6pm.h"

void Buttons_Init(void){
    SYSCTL_RCGCGPIO_R |= 0x08; // Start the clock on port D
	while((SYSCTL_RCGCGPIO_R&0x08) == 0) { ; } // Stabilize
    GPIO_PORTD_CR_R |= 0x07;
    GPIO_PORTD_DEN_R |= 0x07;
    GPIO_PORTD_DIR_R &= ~0x07;
}

uint8_t Buttons_In(void){
    uint8_t data = GPIO_PORTD_DATA_R & 0x07;
    if (data & 0x04) { // Leftmost is button 1
        return 1;
    } else if (data & 0x02) { // Middle is button 2
        return 2;
    } else { // Rightmost is button 3
        return 3;
    }
}
