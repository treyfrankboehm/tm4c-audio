/* Comm.c
 * See whether song needs to start or stop playing
 * Trey Boehm and Emily Steck, 2017-05-03
 * PD3 is start signal, PD4 is stop signal
 */

#include "tm4c123gh6pm.h"

void Comm_Init(void) {
    SYSCTL_RCGCGPIO_R |= 0x08;
    while ((SYSCTL_RCGCGPIO_R & 0x08) == 0) { ; } // Stabilize
    GPIO_PORTD_CR_R |= 0x18;
    GPIO_PORTD_DEN_R |= 0x18;
    GPIO_PORTD_DIR_R &= ~0x18;
}

unsigned int Comm_In(void) {
    int data = GPIO_PORTD_DATA_R & 0x18;
    if (data & 0x010) {
        return 2; // 2 indicates stop
    } else if (data & 0x08) {
        return 1; // 1 indicates start
    } else {
        return 0; // 0 indicates no communication
    }
}
