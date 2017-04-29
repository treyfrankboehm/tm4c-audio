/* dac.c
 * Output voltages to the DAC based on the imported song header file.
 * Trey Boehm, 2017-04-25
 * Hardware connections: PB0-PB5 are DAC output bits
 */

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "dac.h"
#include "lookup.h"
#include "percussion.h"
#include "custom_types.h"

// Global variables that are defined in 4-channel-audio.c:
extern uint32_t Event_Indices[4];

extern Song* Channels[];

// Pointers to the next voltage level in the wave to output
uint8_t Wave_Pointers[4] = {0, 0, 0, 0};
// Pointers to volume levels in corresponding volume envelope
uint16_t Volume_Pointers[4] = {2, 2, 2, 2};
// Which waveform each channel is using
const uint8_t* Waves[4]   = {Guitar_Wave_2, SineWave, SawtoothWave, SineWave};
// Which volume envelope each channel is using
const uint8_t* Volumes[4] = {GuitarVolume, SustainVolume, GuitarVolume, Snare_ADSR};
const uint8_t* Percussion_ADSR[] = {Snare_ADSR, HH_ADSR, BD_ADSR};

void DAC_Init(void) {
    uint8_t i;
    SYSCTL_RCGC2_R |= 0x02;
    for (i = 0; i < 4; i++) ; // Wait for clock to stabilize
    GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTB_DIR_R |= 0x3F;
    GPIO_PORTB_DEN_R |= 0x3F;
    GPIO_PORTB_DATA_R &= ~0x3F; // Start with no sound
}

void DAC_Out(void) {
    uint8_t i;   // Standard iterator
    int16_t tmp; // Used to adjust channel's output (arithmetic ops)
    int8_t sign; // Lookup table is positive numbers only
    uint16_t output = 0;
    
    for (i = 0; i < 3; i++) { // Handle the 0-3 (non-drum) channels
        tmp = Waves[i][Wave_Pointers[i]]; // Grab the DAC level
        tmp -= 31; // Center wave at 0
        // Get the absolute value and store the sign (Mult6 is uint16_t)
        if (tmp < 0) {
            tmp = -tmp;
            sign = -1;
        } else {
            sign = 1;
        }
        // Use the lookup table to multiply by the volume
        tmp = Mult6((uint8_t)tmp, Channels[i][Event_Indices[i]].volume);
        tmp >>= 6;
        // Now look at the ADSR envelope
        tmp = Mult6((uint8_t)tmp, Volumes[i][Volume_Pointers[i]]);
        tmp >>= 6; // divide by 64
        if (sign == -1) {
            tmp = -tmp; // Restore sign if it was negative
        }
        tmp += 31; // re-center at a positive 6-bit int
        output += tmp; // add to the output
    }
    // Percussion is complex enough for its own function
    output += Percussion_Handler();
    output >>= 2; // divide by 4 (4 Channels)
    //output = Percussion_Handler();
    GPIO_PORTB_DATA_R = (output&0x3F);
}

