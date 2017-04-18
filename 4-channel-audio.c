/* 4-channel-audio.c
 * This file initializes and runs the timers that run through the MIDI.
 * Trey Boehm, 2017-04-17
 * Hardware connections: None.
 */

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "TExaS.h"
#include "dac.h"
#include "little.h"
#include "SoundMacros.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

uint32_t Durations[4] = {0};
uint32_t Pitches[4] = {0};
uint32_t Event_Lengths[4] = {0};
uint32_t Event_Indices[4] = {0};

uint32_t Tempo = TEMPO/5;

const Song *Channels[4] = {Channel0, Channel1, Channel2, Channel3};

int main(void){
    uint8_t i;
    
    TExaS_Init(SW_PIN_PE3210, DAC_PIN_PB3210, ScopeOn);    // bus clock at 80 MHz
    DAC_Init(); // Set up Port B
    Timers_Init(); // Start all the timers
    EnableInterrupts();
    // Uncomment the following lines for testing tuning on high pitches
    /*
    Timer0A_Init(REST);
    pitches[0] = C7;
    while (1) {
    }
    */
    // Initialize pitches and duration (hereafter in SysTick_Handler())
    for (i = 0; i < 4; i++) {
        Pitches[i]   = Channels[i][Event_Indices[i]].pitch;
        Durations[i] = Channels[i][Event_Indices[i]].duration;
    }
    while (1) {
        ;
    }
}

