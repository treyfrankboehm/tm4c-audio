/* Comm.c
 * Communicate to the other board whether to start/stop song
 * Trey Boehm and Emily Steck, 2017-05-03
 * PD3 is the start signal, PD4 is the stop signal
 */
 
 #include "tm4c123gh6pm.h"

void Comm_Init(void) {
    SYSCTL_RCGCGPIO_R |= 0x08; // Start the clock on port D
	while((SYSCTL_RCGCGPIO_R&0x08) == 0) { ; } // Stabilize
    GPIO_PORTD_CR_R |= 0x18;
    GPIO_PORTD_DEN_R |= 0x18;
    GPIO_PORTD_DIR_R |= 0x18;
}

void Comm_Start(void) {
    GPIO_PORTD_DATA_R |= 0x08;   // Send start signal
    GPIO_PORTD_DATA_R &= ~0x010; // Do not send stop signal
}

void Comm_Stop(void) {
    GPIO_PORTD_DATA_R |= 0x010;
    GPIO_PORTD_DATA_R &= ~0x08;
}

void Comm_Tacet(void) {
    GPIO_PORTD_DATA_R &= ~0x018;
}

