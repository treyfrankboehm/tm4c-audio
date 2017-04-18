/* dac.c
 * This software configures DAC output
 * Trey Boehm, 2017-04-17
 * Hardware connections: PB0-PB5 are DAC output bits
 */

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "dac.h"

// Sloppy code to avoid including SoundMacros.h in two files (TODO)
#define REST 44444
// Subtract when reloading timers 0-3 to account for function length
#define TUNING_OFFSET 179
// Needed for SysTick_Init()
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode

// These are defined in 4-channel-audio.c
extern uint32_t Durations[];
extern uint32_t Pitches[];
extern uint32_t Event_Lengths[];
extern uint32_t Event_Indices[];
extern uint32_t Tempo;

typedef struct song_struct {
    uint32_t pitch;
    uint32_t duration;
} Song;
extern Song* Channels[];

// Pointers to the next voltage level in the wave to output
static uint8_t WavePointers[4] = {0, 0, 0, 0};

static const uint8_t SineWave[64] = {
    32,35,38,41,44,47,49,52,54,56,58,59,
    61,62,62,63,63,63,62,62,61,59,58,56,
    54,52,49,47,44,41,38,35,32,29,26,23,
    20,17,15,12,10,8,6,5,3,2,2,1,1,1,2,
    2,3,5,6,8,10,12,15,17,20,23,26,29
};

static const uint8_t SawtoothWave[64] = {
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
    17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,
    33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,
    49,50,51,52,53,54,55,56,57,58,59,60,61,62,63
};

static const uint8_t TriangleWave[64] = {
    32,34,36,38,40,42,44,48,50,52,54,56,58,60,62,63,
    62,60,58,56,54,52,50,48,46,44,42,40,38,36,34,32,
    30,28,26,24,22,20,18,16,14,12,10,8,6,4,2,0,
    2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32
};

static const uint8_t PulseEighthWave[64] = {
    63,63,63,63,63,63,63,63,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

static const uint8_t PulseQuarterWave[64] = {
    63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

static const uint8_t PulseHalfWave[64] = {
    63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,
    63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

static const uint8_t OrganWave[64] = {
    31,36,41,46,50,54,57,60,62,63,63,63,61,60,57,54,
    51,47,43,40,36,33,29,27,25,23,22,21,21,22,23,24,
    26,27,29,31,32,33,34,34,34,34,33,31,29,26,24,21,
    18,15,12,10,8,6,5,5,6,7,9,11,14,18,22,27
};

static const uint8_t HornWave[64] = {
  30,30,31,32,33,36,40,50,60,61,63,
  52,40,28,15,13,10,10,10,11,12,13,
  14,15,16,18,19,24,29,31,33,35,
  37,40,43,46,49,51,53,50,47,51,
  55,50,45,38,31,22,13,8,4,2,
  0,1,2,4,6,9,12,14,17,22,26,28
};

static const uint8_t TrumpetWave[64] = {
  48,49,50,51,52,53,53,52,49,45,41,
  33,25,21,20,25,41,52,61,63,63,58,
  53,51,49,49,49,49,50,50,49,49,
  48,48,48,48,49,49,49,49,48,48,
  48,48,49,50,51,51,50,50,50,50,
  50,50,51,50,50,50,49,48,48,48,49,48
};

static const uint8_t BassoonWave[64] = {
  31,35,35,35,33,33,32,31,29,27,26,
  27,31,42,58,63,52,29,9,0,1,6,
  13,20,30,39,45,47,43,36,28,21,
  14,9,7,11,20,30,38,41,38,30,
  24,21,21,22,22,22,24,26,28,29,
  30,32,35,37,36,33,32,32,32,31,29,28
};

static const uint8_t FluteWave[64] = {
  25,31,36,39,42,46,50,54,57,59,62,
  62,63,62,62,59,56,53,51,47,43,39,
  35,32,29,27,25,23,21,20,20,19,
  17,18,18,17,16,15,15,14,13,12,
  10,8,6,5,4,3,2,2,1,1,
  2,3,3,5,6,8,9,12,14,16,19,22
};

static const uint8_t GuitarWave[64] = {
  21,21,21,19,16,11,6,1,0,2,8,
  17,28,37,43,46,48,45,40,32,22,12,
  7,7,13,24,38,51,60,63,59,51,
  43,34,28,24,22,21,21,21,23,27,
  29,32,33,32,29,23,18,12,10,8,
  10,12,12,12,12,12,13,16,18,21,21,21
};

//const uint8_t* waves[4] = {PulseEighthWave, PulseQuarterWave, PulseHalfWave, TriangleWave};
//const uint8_t* waves[4] = {TriangleWave, TriangleWave, TriangleWave, TriangleWave};
//const uint8_t* waves[4] = {OrganWave, OrganWave, OrganWave, TriangleWave};
const uint8_t* waves[4] = {OrganWave, TrumpetWave, HornWave, TriangleWave};

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

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
        output += waves[i][WavePointers[i]];
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
    if (Pitches[0] != REST) {
        WavePointers[0] = (WavePointers[0]+1) & 0x3F;
    }
    DAC_Out();
    TIMER0_TAILR_R = Pitches[0]-TUNING_OFFSET;
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
    if (Pitches[1] != REST) {
        WavePointers[1] = (WavePointers[1]+1) & 0x3F;
    }
    DAC_Out();
    TIMER1_TAILR_R = Pitches[1]-TUNING_OFFSET;
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
    // vector number 37, interrupt number 23
    NVIC_EN0_R = 1<<23;           // 9) enable IRQ 23 in NVIC
    TIMER2_CTL_R = 0x00000001;    // 10) enable TIMER2A
    EndCritical(sr);
}

void Timer2A_Handler(void) {
    TIMER2_ICR_R = TIMER_ICR_TATOCINT;
    TIMER2_CTL_R = 0x00000000;
    if (Pitches[2] != REST) {
        WavePointers[2] = (WavePointers[2]+1) & 0x3F;
    }
    DAC_Out();
    TIMER2_TAILR_R = Pitches[2]-TUNING_OFFSET;
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
    if (Pitches[3] != REST) {
        WavePointers[3] = (WavePointers[3]+1) & 0x3F;
    }
    DAC_Out();
    TIMER3_TAILR_R = Pitches[3]-TUNING_OFFSET;
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
    Song channel;
    for (i = 0; i < 4; i++)  {
        Event_Lengths[i]++;
        if (Durations[i] - Event_Lengths[i] == 0) {
            Event_Indices[i]++;
            Event_Lengths[i] = 0;
            // Update the pitch and duration for this channel
            Pitches[i]   = Channels[i][Event_Indices[i]].pitch;
            Durations[i] = Channels[i][Event_Indices[i]].duration;
            switch (i) {
                case 0: Timer0A_Handler();
                case 1: Timer1A_Handler();
                case 2: Timer2A_Handler();
                case 3: Timer3A_Handler();
            }
        }
        channel = Channels[i][Event_Indices[i]];
        if (channel.duration == 0 && channel.pitch == 0) {
            Event_Indices[i] = 0;
        }
    }
    NVIC_ST_RELOAD_R = Tempo;
    NVIC_ST_CURRENT_R = 0;
    // SysTick automatically acknowledges the ISR completion
}


void Timers_Init(void) {
    Timer0A_Init(2800);
    Timer1A_Init(2800);
    Timer2A_Init(2800);
    Timer3A_Init(2800);
    SysTick_Init(Tempo);
}
