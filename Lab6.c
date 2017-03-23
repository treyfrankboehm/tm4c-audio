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
#include "Sound.h"
#include "Piano.h"
#include "TExaS.h"
#include "dac.h"
#include "SysTickInts.h"

// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

volatile uint32_t HeartBeat_Counter = 0;
void HeartBeat_Init(void);
void HeartBeat_Toggle(void);

int main(void){
    TExaS_Init(SW_PIN_PE3210, DAC_PIN_PB3210, ScopeOn);    // bus clock at 80 MHz
    DAC_Init();
    Piano_Init();
    SysTick_Init(A4);
    HeartBeat_Init();
    // other initialization
    EnableInterrupts();
    while (1) {
        HeartBeat_Counter++;
        if (HeartBeat_Counter > 600000) {
            HeartBeat_Counter = 0;
            HeartBeat_Toggle();
        }
        // Infinite loop. SysTick_Handler is called periodically.
    }
}

void HeartBeat_Init(void) {
    uint8_t i;
    SYSCTL_RCGC2_R |= 0x020;
    for (i = 0; i < 4; i++) ; // Wait for clock to stabilize
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTF_CR_R |= 0x04;
    GPIO_PORTF_DIR_R |= 0x04;
    GPIO_PORTF_DEN_R |= 0x04;
    GPIO_PORTF_PUR_R |= 0x04;
}

void HeartBeat_Toggle(void) {
    uint8_t status = GPIO_PORTF_DATA_R & 0x04;
    if (status == 0x04) {
        GPIO_PORTF_DATA_R &= ~0x04;
    } else {
        GPIO_PORTF_DATA_R |= 0x04;
    }
}
