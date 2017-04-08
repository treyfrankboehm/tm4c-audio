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

// Can't include SoundMacros.h and define multiple times
#define REST 44444
// Subtract when reloading timers 0-3 to account for function length
#define TUNING_OFFSET 179
// Needed for SysTick_Init()
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

const uint8_t triangle_wave[64] = {
    32,34,36,38,40,42,44,48,50,52,54,56,58,60,62,63,
    62,60,58,56,54,52,50,48,46,44,42,40,38,36,34,32,
    30,28,26,24,22,20,18,16,14,12,10,8,6,4,2,0,
    2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32
};

const uint8_t pulse_eighth_wave[64] = {
    63,63,63,63,63,63,63,63,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

const uint8_t pulse_quarter_wave[64] = {
    63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

const uint8_t pulse_half_wave[64] = {
    63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,
    63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

const uint8_t organ_wave[64] = {
    31,36,41,46,50,54,57,60,62,63,63,63,61,60,57,54,
    51,47,43,40,36,33,29,27,25,23,22,21,21,22,23,24,
    26,27,29,31,32,33,34,34,34,34,33,31,29,26,24,21,
    18,15,12,10,8,6,5,5,6,7,9,11,14,18,22,27
};

const uint8_t new_wave[64] ={
    31,39,47,53,58,61,62,62,60,57,52,47,42,38,35,32,
    31,32,35,38,42,47,52,57,60,62,62,61,58,53,47,39,
    31,24,16,10,5,2,1,1,3,6,11,16,21,25,28,31,
    31,31,28,25,21,16,11,6,3,1,1,2,5,10,16,24
};

const uint8_t horn_wave[64] = {
  30,30,31,32,33,36,40,50,60,61,63,
  52,40,28,15,13,10,10,10,11,12,13,
  14,15,16,18,19,24,29,31,33,35,
  37,40,43,46,49,51,53,50,47,51,
  55,50,45,38,31,22,13,8,4,2,
  0,1,2,4,6,9,12,14,17,22,26,28
};

const uint8_t trumpet_wave[64] = {
  48,49,50,51,52,53,53,52,49,45,41,
  33,25,21,20,25,41,52,61,63,63,58,
  53,51,49,49,49,49,50,50,49,49,
  48,48,48,48,49,49,49,49,48,48,
  48,48,49,50,51,51,50,50,50,50,
  50,50,51,50,50,50,49,48,48,48,49,48
};

const uint8_t bassoon_wave[64] = {
  31,35,35,35,33,33,32,31,29,27,26,
  27,31,42,58,63,52,29,9,0,1,6,
  13,20,30,39,45,47,43,36,28,21,
  14,9,7,11,20,30,38,41,38,30,
  24,21,21,22,22,22,24,26,28,29,
  30,32,35,37,36,33,32,32,32,31,29,28
};

const uint8_t flute_wave[64] = {
  25,31,36,39,42,46,50,54,57,59,62,
  62,63,62,62,59,56,53,51,47,43,39,
  35,32,29,27,25,23,21,20,20,19,
  17,18,18,17,16,15,15,14,13,12,
  10,8,6,5,4,3,2,2,1,1,
  2,3,3,5,6,8,9,12,14,16,19,22
};

const uint8_t guitar_wave[64] = {
  21,21,21,19,16,11,6,1,0,2,8,
  17,28,37,43,46,48,45,40,32,22,12,
  7,7,13,24,38,51,60,63,59,51,
  43,34,28,24,22,21,21,21,23,27,
  29,32,33,32,29,23,18,12,10,8,
  10,12,12,12,12,12,13,16,18,21,21,21
};

//const uint8_t* waves[4] = {pulse_eighth_wave, pulse_quarter_wave, pulse_half_wave, triangle_wave};
//const uint8_t* waves[4] = {triangle_wave, triangle_wave, triangle_wave, triangle_wave};
//const uint8_t* waves[4] = {organ_wave, organ_wave, organ_wave, triangle_wave};
const uint8_t* waves[4] = {guitar_wave, guitar_wave, guitar_wave, guitar_wave};
//const uint8_t* waves[4] = {organ_wave, trumpet_wave, horn_wave, triangle_wave};

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
        output += waves[i][wave_pointers[i]];
    }
    output >>= 2;
    GPIO_PORTB_DATA_R = (output&0x3F);
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
            // Phase-lock all channels 
            //wave_pointers[0] = 0;
            //wave_pointers[1] = 0;
            //wave_pointers[2] = 0;
            //wave_pointers[3] = 0;
            // Update the pitch and duration for this channel
            pitches[i]   = channels[i][event_indices[i]].pitch;
            durations[i] = channels[i][event_indices[i]].duration;
            switch (i) {
                case 0: Timer0A_Handler();
                case 1: Timer1A_Handler();
                case 2: Timer2A_Handler();
                case 3: Timer3A_Handler();
            }
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
    extern uint32_t tempo;
    Timer0A_Init(2800);
    Timer1A_Init(2800);
    Timer2A_Init(2800);
    Timer3A_Init(2800);
    SysTick_Init(tempo);
}
