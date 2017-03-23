// Song.c
// This software configures the on-board button and song player
// Runs on LM4F120 or TM4C123
// Program written by: Emily Steck and Trey Boehm
// Date Created: 2017-03-06
// Last Modified: 2017-03-23
// Lab number: 6
// Hardware connections
//     PB0 through PB5: DAC output bits
//     PF1: Start/stop switch

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "Sound.h"

struct note_struct {
    uint32_t pitch;
    uint32_t duration;
    uint8_t volume;
};
typedef struct note_struct note_t;

const note_t song_1[] = {
    {G4, 500, 100},
    {D5, 500, 100},
    {Bes4, 750, 100},
    {A4, 250, 100},
    {G4, 250, 100},
    {Bes4, 250, 100},
    {A4, 250, 100},
    {G4, 250, 100},
    {Fis4, 250, 100},
    {A4, 250, 100},
    {D4, 500, 100}
};
