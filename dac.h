// dac.h
// This software configures DAC output
// Runs on LM4F120 or TM4C123
// Program written by: Emily Steck and Trey Boehm
// Date Created: 2017-03-06
// Last Modified: 2017-03-19
// Lab number: 6
// Hardware connections
//     PB0 through PB5: DAC output bits
//     PE0 through PE2: Synthesizer button inputs
#include <stdint.h>

void DAC_Init(void);

void DAC_Out(void);

void Timer0A_Init(uint32_t period);
void Timer0A_Handler(void);

void Timer1A_Init(uint32_t period);
void Timer1A_Handler(void);

void Timer2A_Init(uint32_t period);
void Timer2A_Handler(void);

void Timer3A_Init(uint32_t period);
void Timer3A_Handler(void);

void SysTick_Init(uint32_t period);
void SysTick_Handler(void);

void Timers_Init(void);
