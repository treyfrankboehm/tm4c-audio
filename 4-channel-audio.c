/* 4-channel-audio.c
 * This file initializes and runs the timers that run through the MIDI.
 * Trey Boehm, 2017-04-22
 * Hardware connections: PB0-PB5 are DAC output bits.
 */

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "pll.h"
#include "dac.h"
#include "little.h"
#include "timers.h"
#include "SoundMacros.h"

void DisableInterrupts(void);
void EnableInterrupts(void);

uint32_t Durations[4]     = {0};
uint32_t Pitches[4]       = {0};
uint32_t Event_Lengths[4] = {0};
uint32_t Event_Indices[4] = {0};

const Song *Channels[4] = {Channel0, Channel1, Channel2, Channel3};

int main(void){
    uint8_t i;
    
    PLL_Init();          // Bus clock at 80 MHz
    DAC_Init();          // Port B outputs DAC voltages 
    Timer0A_Init(A4);    // Timers 0A-3A are for each channel
    Timer1A_Init(A4);
    Timer2A_Init(A4);
    Timer3A_Init(A4);
    SysTick_Init(Tempos[0].tempo/5); // SysTick updates MIDI event number
    EnableInterrupts();  // Each timer has an ISR associated with it
    // Initialize pitches and durations (hereafter done in SysTick)
    for (i = 0; i < 4; i++) {
        Pitches[i]   = Channels[i][Event_Indices[i]].pitch;
        Durations[i] = Channels[i][Event_Indices[i]].duration;
    }
    
    while (1) {
        DAC_Out();
    }
}

