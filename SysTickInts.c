// SysTickInts.c
// Runs on LM4F120/TM4C123
// Use the SysTick timer to request interrupts at a particular period.
// Daniel Valvano
// October 11, 2012

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2014

   Program 5.12, section 5.7

 Copyright 2014 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "SysTickInts.h"
#include "Piano.h"
#include "Sound.h"
#include "dac.h"

#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode


// Stuff for the sequencer
struct note_struct {
    uint32_t pitch;
    uint32_t duration;
    uint8_t volume;
};
typedef struct note_struct note_t;

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

// **************SysTick_Init*********************
// Initialize SysTick periodic interrupts
// Input: interrupt period
//        Units of period are 12.5ns (assuming 50 MHz clock)
//        Maximum is 2^24-1
//        Minimum is determined by length of ISR
// Output: none
void SysTick_Init(uint32_t period) {
    long sr;
    sr = StartCritical();
    NVIC_ST_CTRL_R = 0;         // disable SysTick during setup
    NVIC_ST_RELOAD_R = period-1;// reload value
    NVIC_ST_CURRENT_R = 0;      // any write to current clears it
    NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R & 0x00FFFFFF) | 0x40000000; // priority 2
                                // enable SysTick with core clock and interrupts
    NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC+NVIC_ST_CTRL_INTEN;
    EndCritical(sr);
}

volatile int eventIndex = 0;
volatile int durationCount = 0;
volatile int sequencerEnable = 0;

void SysTick_Handler(void) {
    extern volatile uint8_t wavePointer;
    extern unsigned short wave[];
    
    // Check to see what to do about the sequencer
    volatile int sequencerButtons = Sequencer_In();
    if ((sequencerButtons & 0x10) == 0) {
        sequencerEnable = 0;
    } else if ((sequencerButtons & 0x01) == 0) {
        sequencerEnable = 1;
    }
    
    // If we want the sequencer enabled, go ahead.
    if (sequencerEnable) {
        extern note_t song_1[];
        uint32_t pitch = song_1[eventIndex].pitch;
        uint32_t duration = song_1[eventIndex].duration;
        uint32_t volume = song_1[eventIndex].volume;
        if (durationCount < duration*120000/pitch) {
            Sound_Play(pitch);
            durationCount++;
        } else {
            durationCount = 0;
            eventIndex++;
            if (eventIndex >= 11)
                eventIndex = 0;
        }
        if (pitch != REST || pitch == 0) {
            wavePointer = (wavePointer + 1) & 0x3F;
        }
    } else {
        volatile int buttons = Piano_In();
        extern unsigned int pianoNotes[];
        if (buttons) {
            Sound_Play(pianoNotes[buttons]); // Get the note specified in Piano.c
            wavePointer = (wavePointer + 1) & 0x3F;
        }
    }
    DAC_Out(wave[wavePointer]);
    
    // SysTick automatically acknowledges the ISR completion
}

note_t song_1[] = {
    {G4, 500, 100},
    {D5, 500, 100},
    {Bes4, 750, 100},
    {A4, 250, 100},
    {G4, 250, 100},
    {Bes4, 250, 100},
    {A4, 250, 100},
    {G4, 250, 100},
    {Fis4, 250, 100},
    {A4, 250, 100},
    {D4, 500, 100}
};
