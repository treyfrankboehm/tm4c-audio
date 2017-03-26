// Lab6.c
// Runs on LM4F120 or TM4C123
// Use SysTick interrupts to implement a 4-key digital piano
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
#include "SoundMacros.h"
#include "song.h"
#include "SysTickInts.h"
#include "Timer0A.h"

// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

uint32_t channel0_index = 0;
uint32_t channel0_pitch = 440;
uint32_t channel0_duration = 4444;
uint32_t channel0_count = 0;
uint32_t channel1_index = 0;
uint32_t channel1_pitch = 440;
uint32_t channel1_duration = 4444;
uint32_t channel1_count = 0;

extern const uint8_t wave[];
extern uint8_t wave_pointer0;
extern uint8_t wave_pointer1;
extern const song_t channel0[];
extern const song_t channel1[];

int main(void){
    extern const song_t channel0[];
    extern const song_t channel1[];
    
    TExaS_Init(SW_PIN_PE3210, DAC_PIN_PB3210, ScopeOn);    // bus clock at 80 MHz
    DAC_Init(); // Set up Port B
    //SysTick_Init(A4); // Start SysTick interrupts at 440 Hz
    Timer0A_Init(A4);
    Timer1A_Init(A4);
    Timer2A_Init(A4);
    Timer3A_Init(A4);
    EnableInterrupts();
    while (1) {
        channel0_pitch    = channel0[channel0_index].pitch;
        channel0_duration = channel0[channel0_index].duration;
        channel1_pitch    = channel1[channel1_index].pitch;
        channel1_duration = channel1[channel1_index].duration;
    }
}

