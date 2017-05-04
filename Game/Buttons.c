/* Buttons.c
 * Helper functions to calculate scores, multipliers, and current status
 * Trey Boehm and Emily Steck, 2017-04-23
 * Hardware connections: Refer to ST7735_InitR() (Port A, mainly)
 */
 
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "ADC.h"
#include "timers.h"

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
