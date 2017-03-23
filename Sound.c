// Sound.c
// This module contains the SysTick ISR that plays sound. Also
//     initializes the sequencer (port F buttons) and defines the song
//     data in an array of structs.
// Runs on LM4F120 or TM4C123
// Program written by: Emily Steck and Trey Boehm
// Date Created: 2017-03-06
// Last Modified: 2017-03-23
// Lab number: 6
// Hardware connections
//     PB0 through PB5: DAC output bits
//     PE0 through PE2: Synthesizer button inputs
//     PF0 and PF4: On-board start/stop buttons

// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data
#include <stdint.h>
#include "dac.h"
#include "SysTickInts.h"
#include "tm4c123gh6pm.h"

// Pointer to the next voltage level in the sine wave to output
volatile uint8_t wavePointer = 0;

// 6-bit 64-element sine wave, copy/pasted from Valvano's spreadsheet
const unsigned short wave[64] = {
    32,35,38,41,44,47,49,52,54,56,58,59,
    61,62,62,63,63,63,62,62,61,59,58,56,
    54,52,49,47,44,41,38,35,32,29,26,23,
    20,17,15,12,10,8,6,5,3,2,2,1,1,1,2,
    2,3,5,6,8,10,12,15,17,20,23,26,29
};
/*
const unsigned short wave[64] = {
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
    20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,
    36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,
    52,53,54,55,56,57,58,59,60,61,62,63};
*/
// **************Sound_Init*********************
// Initialize Systick periodic interrupts
// Called once, with sound initially off
// Input: interrupt period
//           Units to be determined by YOU
//           Maximum to be determined by YOU
//           Minimum to be determined by YOU
// Output: none
void Sound_Init(uint32_t period){
    SysTick_Init(period);
    DAC_Init();
}

// **************Sound_Play*********************
// Start sound output, and set Systick interrupt period 
// Input: interrupt period
//           Units to be determined by YOU
//           Maximum to be determined by YOU
//           Minimum to be determined by YOU
//         input of zero disable sound output
// Output: none
void Sound_Play(uint32_t period) {
    NVIC_ST_RELOAD_R = period-1;
    NVIC_ST_CURRENT_R = 0;
}

void Sequencer_Init(void) {
    uint8_t i;
    SYSCTL_RCGC2_R |= 0x020;
    for (i = 0; i < 4; i++) ; // Wait for clock to stabilize
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTF_CR_R |= 0x11;
    GPIO_PORTF_PUR_R |= 0x11;
    GPIO_PORTF_DIR_R &= ~0x11;
    GPIO_PORTF_DEN_R |= 0x11;
}

uint8_t Sequencer_In(void) {
    return (GPIO_PORTF_DATA_R & 0x11);
}
