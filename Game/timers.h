/* timers.h
 * Initialize timers 0A, 1A, 2A, 3A and define ISRs
 * Trey Boehm, 2017-04-27
 * Hardware connections: None
 */

#include <stdint.h>

#define BLINK_PERIOD 40000000
#define ONE_MILLISECOND 50000

void Timer0A_Init(uint32_t period);
void Timer0A_Handler(void);

void Timer1A_Init(uint32_t period);
void Timer1A_Handler(void);

void Timer2A_Init(uint32_t period);
void Timer2A_Handler(void);

void Timer3A_Init(uint32_t period);
void Timer3A_Handler(void);

void Wait_1ms(unsigned int count);
