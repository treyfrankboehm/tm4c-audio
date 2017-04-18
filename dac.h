/* dac.h
 * This software configures DAC output
 * Trey Boehm, 2017-04-17
 * Hardware connections: PB0-PB5 are DAC output bits
 */

#include <stdint.h>

// TODO: Include waves in this file?

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
