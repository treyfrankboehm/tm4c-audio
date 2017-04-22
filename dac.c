/* dac.c
 * Output voltages to the DAC based on the imported song header file.
 * Trey Boehm, 2017-04-22
 * Hardware connections: PB0-PB5 are DAC output bits
 */

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "dac.h"
#include "lookup.h"
#include "noise.h"

// Global variables that are defined in 4-channel-audio.c:
extern uint32_t Durations[4];
extern uint32_t Pitches[4];
extern uint32_t Event_Lengths[4];
extern uint32_t Event_Indices[4];

typedef struct song_struct {
    uint32_t pitch;
    uint32_t duration;
} Song;
extern Song* Channels[];

// Pointers to the next voltage level in the wave to output
uint8_t Wave_Pointers[4] = {0, 0, 0, 0};
// Pointers to volume levels in corresponding volume envelope
uint8_t Volume_Pointers[4] = {2, 2, 2, 2};
// Which waveform each channel is using
const uint8_t* Waves[4]   = {NoiseWave, OrganWave, HornWave, TriangleWave};
// Which volume envelope each channel is using
const uint8_t* Volumes[4] = {OrganVolume, OrganVolume, OrganVolume, OrganVolume};

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
    uint8_t i;   // Standard iterator
    int16_t tmp; // Used to adjust channel's output (arithmetic ops)
    int8_t sign; // Lookup table is positive numbers only
    uint16_t output = 0;
    for (i = 0; i < 4; i++) {
        tmp = Waves[i][Wave_Pointers[i]]; // Grab the DAC level
        if (tmp == 255) { // Check if it's a noise wave (255)
            output += Rand6();
        } else { // Otherwise, go ahead as normal
            tmp -= 31; // Center wave at 0
            // Get the absolute value and store the sign (Mult6 is uint16_t)
            if (tmp < 0) {
                tmp = -tmp;
                sign = -1;
            } else {
                sign = 1;
            }
            // Use the lookup table to multiply by the volume
            tmp = Mult6((uint8_t)tmp, Volumes[i][Volume_Pointers[i]]);
            tmp >>= 6; // divide by 64
            if (sign == -1) {
                tmp = -tmp; // Restore sign if it was negative
            }
            tmp += 31; // re-center at a positive 6-bit int
            output += tmp; // add to the output
        }
    }
    output >>= 2; // divide by 4 (4 Channels)
    
    GPIO_PORTB_DATA_R = (output&0x3F);
}

