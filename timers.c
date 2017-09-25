/* timers.c
 * Initialize timers 0A, 1A, 2A, 3A, SysTick and define ISRs
 * Trey Boehm, 2017-04-25
 * Hardware connections: None
 */

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "timers.h"
#include "custom_types.h"
#include "percussion.h"

// SysTick_Init() uses these
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode

// Subtract this when reloading TAIL_R to account for ISR length
#define TUNING_OFFSET 62

// Global variables that are defined in 4-channel-audio.c:
extern uint32_t Durations[4];
extern uint32_t Pitches[4];
extern uint32_t Event_Lengths[4];
extern uint32_t Event_Indices[4];

// Global variables that are defined in dac.c:
extern uint8_t  Wave_Pointers[4];
extern uint16_t Volume_Pointers[4];
extern uint8_t* Waves[4];
extern uint8_t* Volumes[4];

// Global variable defined in pitch_macros.h
extern int REST;

extern Song* Channels[];
extern Tempo_Times Tempos[];

uint32_t Tempo_Index = 0;
uint32_t MIDI_Time   = 0;

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

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
        Wave_Pointers[0] = (Wave_Pointers[0]+1) & 0x3F;
    }
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
        Wave_Pointers[1] = (Wave_Pointers[1]+1) & 0x3F;
    }
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
    // interrupt number 23
    NVIC_EN0_R = 1<<23;           // 9) enable IRQ 23 in NVIC
    TIMER2_CTL_R = 0x00000001;    // 10) enable TIMER2A
    EndCritical(sr);
}

void Timer2A_Handler(void) {
    TIMER2_ICR_R = TIMER_ICR_TATOCINT;
    TIMER2_CTL_R = 0x00000000;
    if (Pitches[2] != REST) {
        Wave_Pointers[2] = (Wave_Pointers[2]+1) & 0x3F;
    }
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
    // interrupt number 35
    NVIC_EN1_R = 1<<(35-32);      // 9) enable IRQ 35 in NVIC
    TIMER3_CTL_R = 0x00000001;    // 10) enable TIMER3A
}

void Timer3A_Handler(void) {
    TIMER3_ICR_R = TIMER_ICR_TATOCINT;
    TIMER3_CTL_R = 0x00000000;
    if (Pitches[3] != REST) {
        Wave_Pointers[3] = (Wave_Pointers[3]+1) & 0x3F;
    }
    //TIMER3_TAILR_R = Pitches[3]-TUNING_OFFSET;
    TIMER3_TAILR_R = Percussion_Period(); // Percussive instruments are often untuned
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
    uint32_t sust_index;
    uint32_t vol_length;
    uint32_t decay_time;
    uint32_t time;
    uint32_t tempo;
    //Song channel;

    for (i = 0; i < 4; i++)  {
        Event_Lengths[i]++;
        
        // check if we're at sustain volume
        sust_index = Volumes[i][0];
        vol_length = Volumes[i][1];
        decay_time = vol_length - sust_index;
        if (Event_Lengths[i] >= sust_index) {
            // check if it's time to decay
            if (Durations[i] - Event_Lengths[i] <= decay_time) {
                Volume_Pointers[i]++;
            }
        } else {
            // if not at sustain, just increment
            Volume_Pointers[i]++;
        }
        
        if (Durations[i] - Event_Lengths[i] <= 0) {
            // Go to the next event and reset counter
            Event_Indices[i]++;
            Event_Lengths[i] = 0;
            // Start at the beginning of volume envelope
            Volume_Pointers[i] = 2;
            // Update the pitch and duration for this Channel
            Pitches[i]   = Channels[i][Event_Indices[i]].pitch;
            Durations[i] = Channels[i][Event_Indices[i]].duration;
            switch (i) {
                case 0: Timer0A_Handler();
                case 1: Timer1A_Handler();
                case 2: Timer2A_Handler();
                case 3: Timer3A_Handler();
            }
        }
    }
    // Check if a new tempo is needed
    time = Tempos[Tempo_Index+1].time;
    MIDI_Time++;
    if (MIDI_Time == time) {
        Tempo_Index++;
    }
    tempo = Tempos[Tempo_Index].tempo/5;

    NVIC_ST_RELOAD_R = tempo;
    NVIC_ST_CURRENT_R = 0;
    // SysTick automatically acknowledges the ISR completion
}

