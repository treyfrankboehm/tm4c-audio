/* 4-channel-audio.c
 * This file initializes and runs the timers that run through the MIDI.
 * Trey Boehm, 2017-04-19
 * Hardware connections: PB0-PB5 are DAC output bits.
 */

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "TExaS.h"
#include "dac.h"
#include "little.h"
#include "SoundMacros.h"

void DisableInterrupts(void);
void EnableInterrupts(void);

uint32_t Durations[4]     = {0};
uint32_t Pitches[4]       = {0};
uint32_t Event_Lengths[4] = {0};
uint32_t Event_Indices[4] = {0};

uint32_t Tempo = TEMPO/5;

const Song *Channels[4] = {Channel0, Channel1, Channel2, Channel3};

int main(void){
    uint8_t i;
    
    /* TODO: Get rid of TExaS_Init and replace with code that only sets
     * the bus clock to 80 MHz (not auto-grader crap)
     */
    TExaS_Init(SW_PIN_PE3210, DAC_PIN_PB3210, ScopeOn);
    DAC_Init(); // Set up Port B
    Timers_Init(); // Start all the timers
    EnableInterrupts();
    // Uncomment the following lines for testing tuning on high pitches
    /*
    Timer0A_Init(REST);
    Pitches[0] = C7;
    Pitches[1] = C7;
    Pitches[2] = C7;
    Pitches[3] = C7;
    while (1) { }
    */
    // Initialize Pitches and duration (hereafter in SysTick_Handler())
    for (i = 0; i < 4; i++) {
        Pitches[i]   = Channels[i][Event_Indices[i]].pitch;
        Durations[i] = Channels[i][Event_Indices[i]].duration;
    }
    while (1) {
        ;
    }
}

