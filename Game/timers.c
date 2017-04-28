/* timers.c
 * Initialize timers 0A, 1A, 2A, 3A and define ISRs
 * Trey Boehm, 2017-04-27
 * Hardware connections: None
 */

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "timers.h"

long StartCritical(void);
void EndCritical(long sr);

void Blink_Block(void);

void Timer0A_Init(uint32_t period) {
    long sr;
    sr = StartCritical(); 
    SYSCTL_RCGCTIMER_R |= 0x01;   // 0) activate TIMER0
    TIMER0_CTL_R = 0x00000000;    // 1) disable TIMER0A during setup
    TIMER0_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
    TIMER0_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
    TIMER0_TAILR_R = period-1;    // 4) reload value
    TIMER0_TAPR_R = 0;            // 5) bus clock resolution
    TIMER0_ICR_R = 0x00000001;    // 6) clear TIMER0A timeout flag
    TIMER0_IMR_R = 0x00000001;    // 7) arm timeout interrupt
    NVIC_PRI4_R = (NVIC_PRI4_R&0x00FFFFFF)|0x80000000; // 8) priority 4
    // interrupts enabled in the main program after all devices initialized
    // vector number 35, interrupt number 19
    NVIC_EN0_R = 1<<19;           // 9) enable IRQ 19 in NVIC
    TIMER0_CTL_R = 0x00000001;    // 10) enable TIMER0A
    EndCritical(sr);
}

void Timer0A_Handler(void) {
    TIMER0_ICR_R = TIMER_ICR_TATOCINT;
    TIMER0_CTL_R = 0x00000000;
    Blink_Block();
    TIMER0_TAILR_R = BLINK_PERIOD;
    TIMER0_CTL_R = 0x00000001;
}

void Timer1A_Init(uint32_t period) {
    long sr;
    sr = StartCritical(); 
    SYSCTL_RCGCTIMER_R |= 0x02;   // 0) activate TIMER1
    TIMER1_CTL_R = 0x00000000;    // 1) disable TIMER1A during setup
    TIMER1_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
    TIMER1_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
    TIMER1_TAILR_R = period-1;    // 4) reload value
    TIMER1_TAPR_R = 0;            // 5) bus clock resolution
    TIMER1_ICR_R = 0x00000001;    // 6) clear TIMER1A timeout flag
    TIMER1_IMR_R = 0x00000001;    // 7) arm timeout interrupt
    NVIC_PRI5_R = (NVIC_PRI5_R&0x00FFFFFF)|0x00008000; // 8) priority 4
    // interrupts enabled in the main program after all devices initialized
    // vector number 37, interrupt number 21
    NVIC_EN0_R = 1<<21;           // 9) enable IRQ 21 in NVIC
    TIMER1_CTL_R = 0x00000001;    // 10) enable TIMER1A
    EndCritical(sr);
}

void Timer1A_Handler(void) {
    TIMER1_ICR_R = TIMER_ICR_TATOCINT;
    TIMER1_CTL_R = 0x00000000;
    TIMER1_TAILR_R = BLINK_PERIOD;
    TIMER1_CTL_R = 0x00000001;
}

void Timer2A_Init(uint32_t period) {
    long sr;
    sr = StartCritical(); 
    SYSCTL_RCGCTIMER_R |= 0x04;   // 0) activate TIMER2
    TIMER2_CTL_R = 0x00000000;    // 1) disable TIMER2A during setup
    TIMER2_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
    TIMER2_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
    TIMER2_TAILR_R = period-1;    // 4) reload value
    TIMER2_TAPR_R = 0;            // 5) bus clock resolution
    TIMER2_ICR_R = 0x00000001;    // 6) clear TIMER2A timeout flag
    TIMER2_IMR_R = 0x00000001;    // 7) arm timeout interrupt
    NVIC_PRI5_R = (NVIC_PRI5_R&0x00FFFFFF)|0x80000000; // 8) priority 4
    // interrupts enabled in the main program after all devices initialized
    // interrupt number 23
    NVIC_EN0_R = 1<<23;           // 9) enable IRQ 23 in NVIC
    TIMER2_CTL_R = 0x00000001;    // 10) enable TIMER2A
    EndCritical(sr);
}

void Timer2A_Handler(void) {
    TIMER2_ICR_R = TIMER_ICR_TATOCINT;
    TIMER2_CTL_R = 0x00000000;
    // periodic task
    TIMER2_TAILR_R = BLINK_PERIOD;
    TIMER2_CTL_R = 0x00000001;
}

void Timer3A_Init(uint32_t period){
    SYSCTL_RCGCTIMER_R |= 0x08;   // 0) activate TIMER3
    TIMER3_CTL_R = 0x00000000;    // 1) disable TIMER3A during setup
    TIMER3_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
    TIMER3_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
    TIMER3_TAILR_R = period-1;    // 4) reload value
    TIMER3_TAPR_R = 0;            // 5) bus clock resolution
    TIMER3_ICR_R = 0x00000001;    // 6) clear TIMER3A timeout flag
    TIMER3_IMR_R = 0x00000001;    // 7) arm timeout interrupt
    NVIC_PRI8_R = (NVIC_PRI8_R&0x00FFFFFF)|0x80000000; // 8) priority 4
    // interrupts enabled in the main program after all devices initialized
    // interrupt number 35
    NVIC_EN1_R = 1<<(35-32);      // 9) enable IRQ 35 in NVIC
    TIMER3_CTL_R = 0x00000001;    // 10) enable TIMER3A
}

void Timer3A_Handler(void) {
    TIMER3_TAILR_R = BLINK_PERIOD; // Percussive instruments are often untuned
    TIMER3_CTL_R = 0x00000001;
}

