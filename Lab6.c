// Lab6.c
// Runs on LM4F120 or TM4C123
// Use SysTick interrupts to implement a 4-key digital piano
// MOOC lab 13 or EE319K lab6 starter
// Program written by: Emily Steck and Trey Boehm
// Date Created: 2017-03-06
// Last Modified: 2017-03-21
// Lab number: 6
// Hardware connections
//     PB0 through PB5: DAC output bits
//     PE0 through PE2: Synthesizer button inputs


#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "Sound.h"
#include "Piano.h"
#include "TExaS.h"
#include "dac.h"
#include "SysTickInts.h"

#define TEMPO 84

// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

const unsigned int songNotes[] = {
    A5, Fis5, Gis5, E5, Fis5, D5, D5, A5, A5, Fis5, Gis5, E5, D5, B4
};

int main(void){
    //int i, j;
    TExaS_Init(SW_PIN_PE3210, DAC_PIN_PB3210, ScopeOn);    // bus clock at 80 MHz
    Piano_Init();
    Sound_Init(1023);
    // other initialization
    EnableInterrupts();
    while (1) {
        GPIO_PORTE_DATA_R &= ~0x07;
    }
    /*
        for (i = 0; i < sizeof(songNotes)/sizeof(int); i++) {
            for (j = 0; j < (18000000/(songNotes[i]*TEMPO)); j++) {
                Sound_Play(songNotes[i]);
            }
        }
    }
    */
}


