/* main.c
 * This file initializes and runs the timers that run through the MIDI.
 * Trey Boehm, 2017-04-25
 * Hardware connections: PB0-PB5 are DAC output bits.
 */

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "pll.h"
#include "dac.h"
//#include "paradigm.h"
#include "Comm.h"
#include "yyz.h"
#include "timers.h"
#include "custom_types.h"

extern uint32_t Tempo_Index;
extern uint32_t MIDI_Time;

extern uint8_t  Wave_Pointers[4];
extern uint16_t Volume_Pointers[4];
extern uint8_t* Waves[4];
extern uint8_t* Volumes[4];

void DisableInterrupts(void);
void EnableInterrupts(void);

uint32_t Durations[4]     = {0};
uint32_t Pitches[4]       = {0};
uint32_t Event_Lengths[4] = {0};
uint32_t Event_Indices[4] = {0};

const Song *Channels[] = {Channel0, Channel1, Channel2, Channel3};

int main(void) {
    uint8_t i;
    unsigned int communication;
    
    PLL_Init();          // Bus clock at 80 MHz
    DAC_Init();          // Port B outputs DAC voltages 
    Comm_Init();	     // Port D to communicate with other board
    Timer0A_Init(A4);    // Timers 0A-3A are for each channel
    Timer1A_Init(A4);
    Timer2A_Init(A4);
    Timer3A_Init(A4);
    SysTick_Init(Tempos[0].tempo/5); // SysTick updates MIDI event number
    // Initialize pitches and durations (hereafter done in SysTick)
    for (i = 0; i < 4; i++) {
        Pitches[i]   = Channels[i][Event_Indices[i]].pitch;
        Durations[i] = Channels[i][Event_Indices[i]].duration;
    }
    EnableInterrupts();  // Each timer has an ISR associated with it
    
    while (1) {
        communication = Comm_In();
        if (communication) {
            for (i = 0; i < 4; i++) {
                Event_Indices[i] = 0;
                Event_Lengths[i] = 0;
                MIDI_Time = 0;
                Tempo_Index = 0;
                Volume_Pointers[i] = 2;
                Pitches[i]   = Channels[i][Event_Indices[i]].pitch;
                Durations[i] = Channels[i][Event_Indices[i]].duration;
            }
            if (communication == 2) { // Stop signal
                NVIC_ST_CTRL_R = 0;
                TIMER0_CTL_R = 0x0;
                TIMER1_CTL_R = 0x0;
                TIMER2_CTL_R = 0x0;
                TIMER3_CTL_R = 0x0;
            } else {
                // Other communication indicates [re]start }
                SysTick_Init(Tempos[0].tempo/5);
                Timer0A_Init(A4);
                Timer1A_Init(A4);
                Timer2A_Init(A4);
                Timer3A_Init(A4);
            }
        }

        DAC_Out();
    }
}

