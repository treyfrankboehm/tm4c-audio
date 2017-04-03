// dac.c
// This software configures DAC output
// Runs on LM4F120 or TM4C123
// Program written by: Emily Steck and Trey Boehm
// Date Created: 2017-03-06
// Last Modified: 2017-04-01
// Lab number: 6
// Hardware connections
//     PB0 through PB5: DAC output bits
//     PE0 through PE2: Synthesizer button inputs

#include <stdint.h>
#include "tm4c123gh6pm.h"

#define REST 44444
#define TUNING_OFFSET 180 // Subtract when reloading timers to account
                          // for the length of the function
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

// Global variables that are defined in 4-channel-audio.c:
extern uint32_t durations[];     // replaces channelX_duration
extern uint32_t pitches[];       // replaces channelX_pitch
extern uint32_t event_lengths[]; // replaces channelX_count
extern uint32_t event_indices[]; // replaces channelX_index

typedef struct song_struct {
    uint32_t pitch;
    uint32_t duration;
} song_t;
extern song_t* channels[];

// Pointers to the next voltage level in the wave to output
uint8_t wave_pointers[4] = {0, 0, 0, 0};

// 6-bit 64-element sine wave, copy/pasted from Valvano's spreadsheet
const uint8_t sine_wave[64] = {
    32,35,38,41,44,47,49,52,54,56,58,59,
    61,62,62,63,63,63,62,62,61,59,58,56,
    54,52,49,47,44,41,38,35,32,29,26,23,
    20,17,15,12,10,8,6,5,3,2,2,1,1,1,2,
    2,3,5,6,8,10,12,15,17,20,23,26,29
};

const uint8_t sawtooth_wave[64] = {
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
    17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,
    33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,
    49,50,51,52,53,54,55,56,57,58,59,60,61,62,63
};

const uint8_t* waves[4] = {sine_wave, sine_wave, sine_wave, sine_wave};

void DAC_Init(void){
    uint8_t i;
    SYSCTL_RCGC2_R |= 0x02;
    for (i = 0; i < 4; i++) ; // Wait for clock to stabilize
    GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTB_DIR_R |= 0x3F;
    GPIO_PORTB_DEN_R |= 0x3F;
    GPIO_PORTB_DATA_R &= ~0x3F; // Start with no sound
}

void DAC_Out(void){
    uint8_t i;
    uint16_t output = 0;
    for (i = 0; i < 4; i++) {
        output += sine_wave[wave_pointers[i]];
    }
    output /= 4;
    //output = sine_wave[wave_pointers[0]];
    GPIO_PORTB_DATA_R = (output&0x3F);
    //GPIO_PORTB_DATA_R &= ~0x3F; // Friendly way to write sound
    //GPIO_PORTB_DATA_R |= (0x3F & output);
}

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
    if (pitches[0] != REST) {
        wave_pointers[0] = (wave_pointers[0]+1) & 0x3F;
    }
    DAC_Out();
    TIMER0_TAILR_R = pitches[0]-TUNING_OFFSET;
    TIMER0_CTL_R = 0x00000001;
}

void Timer1A_Init(uint32_t period) {
    long sr;
    sr = StartCritical(); 
    SYSCTL_RCGCTIMER_R |= 0x02;   // 0) activate TIMER0
    TIMER1_CTL_R = 0x00000000;    // 1) disable TIMER0A during setup
    TIMER1_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
    TIMER1_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
    TIMER1_TAILR_R = period-1;    // 4) reload value
    TIMER1_TAPR_R = 0;            // 5) bus clock resolution
    TIMER1_ICR_R = 0x00000001;    // 6) clear TIMER0A timeout flag
    TIMER1_IMR_R = 0x00000001;    // 7) arm timeout interrupt
    NVIC_PRI5_R = (NVIC_PRI5_R&0x00FFFFFF)|0x00008000; // 8) priority 4
    // interrupts enabled in the main program after all devices initialized
    // vector number 37, interrupt number 21
    NVIC_EN0_R = 1<<21;           // 9) enable IRQ 19 in NVIC
    TIMER1_CTL_R = 0x00000001;    // 10) enable TIMER0A
    EndCritical(sr);
}

void Timer1A_Handler(void) {
    TIMER1_ICR_R = TIMER_ICR_TATOCINT;
    TIMER1_CTL_R = 0x00000000;
    if (pitches[1] != REST) {
        wave_pointers[1] = (wave_pointers[1]+1) & 0x3F;
    }
    DAC_Out();
    // TODO: Change the pitches[i]-1 to reflect length of fxn
    TIMER1_TAILR_R = pitches[1]-TUNING_OFFSET;
    TIMER1_CTL_R = 0x00000001;
}

void Timer2A_Init(uint32_t period) {
    long sr;
    sr = StartCritical(); 
    SYSCTL_RCGCTIMER_R |= 0x04;   // 0) activate TIMER0
    TIMER2_CTL_R = 0x00000000;    // 1) disable TIMER0A during setup
    TIMER2_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
    TIMER2_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
    TIMER2_TAILR_R = period-1;    // 4) reload value
    TIMER2_TAPR_R = 0;            // 5) bus clock resolution
    TIMER2_ICR_R = 0x00000001;    // 6) clear TIMER0A timeout flag
    TIMER2_IMR_R = 0x00000001;    // 7) arm timeout interrupt
    NVIC_PRI5_R = (NVIC_PRI5_R&0x00FFFFFF)|0x80000000; // 8) priority 4
    // interrupts enabled in the main program after all devices initialized
    // vector number 37, interrupt number 21
    NVIC_EN0_R = 1<<23;           // 9) enable IRQ 19 in NVIC
    TIMER2_CTL_R = 0x00000001;    // 10) enable TIMER0A
    EndCritical(sr);
}

void Timer2A_Handler(void) {
    TIMER2_ICR_R = TIMER_ICR_TATOCINT;
    TIMER2_CTL_R = 0x00000000;
    if (pitches[2] != REST) {
        wave_pointers[2] = (wave_pointers[2]+1) & 0x3F;
    }
    DAC_Out();
    TIMER2_TAILR_R = pitches[2]-TUNING_OFFSET;
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
    // vector number 51, interrupt number 35
    NVIC_EN1_R = 1<<(35-32);      // 9) enable IRQ 35 in NVIC
    TIMER3_CTL_R = 0x00000001;    // 10) enable TIMER3A
}

void Timer3A_Handler(void) {
    TIMER3_ICR_R = TIMER_ICR_TATOCINT;
    TIMER3_CTL_R = 0x00000000;
    if (pitches[3] != REST) {
        wave_pointers[3] = (wave_pointers[3]+1) & 0x3F;
    }
    DAC_Out();
    TIMER3_TAILR_R = pitches[3]-TUNING_OFFSET;
    TIMER3_CTL_R = 0x00000001;
}

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

void SysTick_Handler(void) {
    uint8_t i;
    song_t channel;
    extern uint32_t tempo;
    for (i = 0; i < 4; i++)  {
        event_lengths[i]++;
        if (durations[i] - event_lengths[i] == 0) {
            event_indices[i]++;
            event_lengths[i] = 0;
            wave_pointers[0] = 0;
            wave_pointers[1] = 0;
            wave_pointers[2] = 0;
            wave_pointers[3] = 0;
            wave_pointers[i] = 0;
        }
        channel = channels[i][event_indices[i]];
        if (channel.duration == 0 && channel.pitch == 0) {
            event_indices[i] = 0;
        }
    }
    NVIC_ST_RELOAD_R = tempo;
    NVIC_ST_CURRENT_R = 0;
    // SysTick automatically acknowledges the ISR completion
}


void Timers_Init(void) {
    Timer0A_Init(2800);
    Timer1A_Init(2800);
    Timer2A_Init(2800);
    Timer3A_Init(2800);
    SysTick_Init(62500);
}
