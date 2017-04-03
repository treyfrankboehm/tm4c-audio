// Lab6.c
// Runs on LM4F120 or TM4C123
// MOOC lab 13 or EE319K lab6 starter
// Program written by: Emily Steck and Trey Boehm
// Date Created: 2017-03-06
// Last Modified: 2017-03-23
// Lab number: 6
// Hardware connections
//     PB0 through PB5: DAC output bits
//     PE0 through PE2: Synthesizer button inputs
//     PF0 and PF4: On-board start/stop buttons


#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "TExaS.h"
#include "dac.h"
//#include "crystallized-midi.h"
//#include "jesu.h"
#include "little.h"
#include "SoundMacros.h"

// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

// Global variables that are defined in 4-channel-audio.c:
uint32_t durations[4] = {0};     // replaces channelX_duration
uint32_t pitches[4] = {0};       // replaces channelX_pitch
uint32_t event_lengths[4] = {0}; // replaces channelX_count
uint32_t event_indices[4] = {0}; // replaces channelX_index

uint32_t tempo = TEMPO/5;

const song_t *channels[4] = {channel0, channel1, channel2, channel3};

int main(void){
    extern const song_t channel0[];
    extern const song_t channel1[];
    uint8_t i;
    
    TExaS_Init(SW_PIN_PE3210, DAC_PIN_PB3210, ScopeOn);    // bus clock at 80 MHz
    DAC_Init(); // Set up Port B
    Timers_Init(); // Start all the timers
    EnableInterrupts();
    for (i = 0; i < 4; i++) { // Initialize pitches and duration (usually
                              // done in SysTick_Handler())
        pitches[i]   = channels[i][event_indices[i]].pitch;
        durations[i] = channels[i][event_indices[i]].duration;
    }
    while (1) {
    }
}

