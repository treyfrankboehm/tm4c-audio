/* percussion.c
 * Handle percussion instruments as exceptions to the standard DAC rule
 * Trey Boehm, 2017-04-25
 */

#include <stdint.h>
#include "lookup.h"
#include "custom_types.h"
#include "percussion.h"

extern Song *Channels[];
extern uint32_t Event_Indices[];

// Global variables that are defined in dac.c:
extern uint8_t  Wave_Pointers[4];
extern uint16_t Volume_Pointers[4];
extern uint8_t* Waves[4];
extern uint8_t* Volumes[4];
extern uint8_t* Percussion_ADSR[];

static uint32_t NoiseSeed = 0x27d4eb2d;
static uint32_t TimerReloadValue = 2800;

uint8_t Rand6(void) {
    uint32_t a = NoiseSeed;
    a *= 1664525;
    a += 1013904223;
    NoiseSeed = a;
    a >>= 26;
    a &= 0x3F;
    return a;
}

uint16_t Percussion_Period(void) {
    return TimerReloadValue;
}

uint8_t Percussion_Handler(void) {
    uint16_t instrument = Channels[3][Event_Indices[3]].pitch;
    //uint8_t volume = Channels[3][Event_Indices[3]].volume;
    uint16_t dac_out = 0;
    uint8_t adsr_vol;
    if (instrument == 6020) { // Hi-hat
        Volumes[3] = Percussion_ADSR[0];
        dac_out = Rand6();
        TimerReloadValue = ((Rand6() << 5)+600);
    } else if (instrument == 8513) { // Snare
        Volumes[3] = Percussion_ADSR[1];
        dac_out = Rand6();
        TimerReloadValue = (Mult6(Rand6(), Rand6())+600);
    } else if (instrument == 9556) { // Bass drum
        Volumes[3] = Percussion_ADSR[2];
        dac_out = Waves[3][Wave_Pointers[3]];
        //dac_out = Mult6(dac_out, (Rand6() >> 5));
        //dac_out >>= 1;
        TimerReloadValue = 18000;
    }
    adsr_vol = Percussion_ADSR[0][Volume_Pointers[3]];
    if (adsr_vol == 0) {
        Volume_Pointers[3]--; // Stay on the 0 (release) until the end
    }
    dac_out = Mult6(dac_out, adsr_vol);
    dac_out >>= 6;
    return dac_out;
}

