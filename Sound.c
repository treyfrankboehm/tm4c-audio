// Sound.c
// This module contains the SysTick ISR that plays sound
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
#include "dac.h"
#include "tm4c123gh6pm.h"
#include "SysTickInts.h"

// 6-bit 64-element sine wave, copy/pasted from Valvano's spreadsheet
const unsigned short wave[64] = {
    32,35,38,41,44,47,49,52,54,56,58,59,
    61,62,62,63,63,63,62,62,61,59,58,56,
    54,52,49,47,44,41,38,35,32,29,26,23,
    20,17,15,12,10,8,6,5,3,2,2,1,1,1,2,
    2,3,5,6,8,10,12,15,17,20,23,26,29
};

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
void Sound_Play(uint32_t period){
    static int i = 0;
    DAC_Out(wave[i]);
    
    for (i = 0; i < 64; i++) {
        DAC_Out(wave[i]);
        NVIC_ST_CURRENT_R = 0x00FFFFFF;
        while (NVIC_ST_RELOAD_R - NVIC_ST_CURRENT_R < period) {
            ;
        }
    }
}

