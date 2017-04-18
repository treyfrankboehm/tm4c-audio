/* little.h: .midi -> .csv -> C struct
 * Copyright (c) 2017 Trey Boehm
 */

#include "SoundMacros.h"
#include <stdint.h>

#define TEMPO 714285

typedef struct song_struct {
    uint32_t pitch;
    uint32_t duration;
} Song;


const Song Channel0[] = {
	{G5, 384},
	{D6, 384},
	{Ais5, 576},
	{A5, 192},
	{G5, 192},
	{Ais5, 192},
	{A5, 192},
	{G5, 192},
	{Fis5, 192},
	{A5, 192},
	{D5, 384},
	{G5, 192},
	{D5, 192},
	{A5, 192},
	{D5, 192},
	{Ais5, 192},
	{A5, 96},
	{G5, 96},
	{A5, 192},
	{D5, 192},
	{G5, 192},
	{D5, 96},
	{G5, 96},
	{A5, 192},
	{D5, 96},
	{A5, 96},
	{Ais5, 192},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{D5, 96},
	{D6, 96},
	{C6, 96},
	{Ais5, 96},
	{A5, 96},
	{G5, 96},
	{Ais5, 96},
	{A5, 96},
	{G5, 96},
	{Fis5, 96},
	{A5, 96},
	{G5, 96},
	{D5, 96},
	{G5, 96},
	{A5, 96},
	{Ais5, 96},
	{C6, 96},
	{D6, 96},
	{E6, 96},
	{F6, 96},
	{E6, 96},
	{D6, 96},
	{F6, 96},
	{E6, 96},
	{D6, 96},
	{Cis6, 96},
	{E6, 96},
	{D6, 192},
	{A4, 192},
	{D5, 192},
	{E5, 192},
	{F5, 96},
	{G5, 96},
	{F5, 96},
	{G5, 96},
	{G5, 288},
	{F5, 48},
	{G5, 48},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{Ais5, 96},
	{A5, 96},
	{G5, 96},
	{F5, 96},
	{E5, 96},
	{F5, 96},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{Cis5, 96},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{D5, 96},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{C5, 96},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{F5, 96},
	{D5, 96},
	{Cis5, 96},
	{D5, 96},
	{G5, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{A5, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{G5, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{A4, 192},
	{F5, 192},
	{G4, 192},
	{E5, 192},
	{F4, 192},
	{A4, 192},
	{D5, 192},
	{F5, 192},
	{Dis5, 192},
	{A5, 192},
	{REST, 192},
	{Dis5, 192},
	{D5, 192},
	{G5, 192},
	{REST, 192},
	{D5, 192},
	{C5, 96},
	{Ais4, 96},
	{C5, 96},
	{D5, 96},
	{C5, 96},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{Ais4, 96},
	{G5, 96},
	{Fis5, 96},
	{G5, 96},
	{A4, 96},
	{F5, 96},
	{E5, 96},
	{F5, 96},
	{G5, 768},
	{REST, 1536},
	{Ais4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Fis4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{G4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Fis4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Ais4, 384},
	{C5, 384},
	{D5, 384},
	{C5, 384},
	{REST, 192},
	{Ais4, 192},
	{REST, 192},
	{A4, 192},
	{REST, 192},
	{F4, 192},
	{G4, 96},
	{A4, 96},
	{Ais4, 96},
	{G4, 96},
	{A4, 192},
	{D5, 192},
	{Cis5, 192},
	{E5, 192},
	{A5, 96},
	{Ais5, 96},
	{A5, 96},
	{G5, 96},
	{F5, 96},
	{E5, 96},
	{D5, 96},
	{Cis5, 96},
	{D5, 192},
	{REST, 192},
	{Ais4, 192},
	{REST, 192},
	{E5, 192},
	{REST, 384},
	{A5, 192},
	{A5, 3168},
	{G5, 96},
	{A5, 96},
	{Ais5, 96},
	{A5, 96},
	{G5, 96},
	{F5, 96},
	{E5, 96},
	{F5, 768},
	{REST, 192},
	{D5, 192},
	{G5, 192},
	{F5, 192},
	{Dis5, 960},
	{C5, 192},
	{F5, 192},
	{Dis5, 192},
	{D5, 480},
	{G5, 96},
	{Fis5, 96},
	{G5, 96},
	{C5, 480},
	{Ais4, 96},
	{A4, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{Fis4, 96},
	{A4, 96},
	{G4, 96},
	{D4, 96},
	{E4, 96},
	{Fis4, 96},
	{G4, 96},
	{D4, 96},
	{G4, 96},
	{A4, 96},
	{Ais4, 96},
	{G4, 96},
	{Ais4, 96},
	{C5, 96},
	{D5, 96},
	{A4, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 576},
	{A4, 192},
	{G4, 192},
	{Ais4, 192},
	{A4, 192},
	{G4, 192},
	{Fis4, 192},
	{A4, 192},
	{D4, 384},
	{G4, 192},
	{D4, 192},
	{A4, 192},
	{D4, 192},
	{Ais4, 192},
	{A4, 96},
	{G4, 96},
	{A4, 192},
	{D4, 192},
	{G4, 192},
	{D4, 96},
	{G4, 96},
	{A4, 192},
	{D4, 96},
	{A4, 96},
	{Ais4, 192},
	{A4, 96},
	{G4, 96},
	{A4, 96},
	{D4, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{Fis4, 96},
	{A4, 96},
	{G4, 96},
	{Ais4, 96},
	{C5, 96},
	{D5, 96},
	{Dis5, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{Fis4, 96},
	{A4, 96},
	{Ais4, 96},
	{C5, 96},
	{D5, 96},
	{A4, 96},
	{G4, 96},
	{F4, 96},
	{Dis4, 96},
	{G4, 96},
	{A4, 96},
	{Ais4, 96},
	{C5, 96},
	{G4, 96},
	{F4, 96},
	{Dis4, 96},
	{D4, 96},
	{F4, 96},
	{G4, 96},
	{A4, 96},
	{Ais4, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{C5, 96},
	{D5, 96},
	{Dis5, 96},
	{F5, 96},
	{G5, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{C5, 96},
	{Ais4, 96},
	{F4, 96},
	{G4, 96},
	{A4, 96},
	{Ais4, 96},
	{C5, 96},
	{Ais4, 96},
	{C5, 96},
	{D5, 96},
	{E5, 96},
	{D5, 96},
	{E5, 96},
	{E5, 288},
	{D5, 48},
	{E5, 48},
	{F5, 96},
	{Dis5, 96},
	{F5, 96},
	{G5, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{F5, 96},
	{Dis5, 96},
	{F5, 96},
	{A4, 96},
	{F5, 96},
	{Dis5, 96},
	{F5, 96},
	{Ais4, 96},
	{F5, 96},
	{Dis5, 96},
	{F5, 96},
	{A4, 96},
	{F5, 96},
	{Dis5, 96},
	{F5, 96},
	{D5, 96},
	{Ais4, 96},
	{A4, 96},
	{Ais4, 96},
	{Dis5, 96},
	{Ais4, 96},
	{A4, 96},
	{Ais4, 96},
	{F5, 96},
	{Ais4, 96},
	{A4, 96},
	{Ais4, 96},
	{Dis5, 96},
	{Ais4, 96},
	{A4, 96},
	{Ais4, 96},
	{Ais4, 96},
	{C5, 96},
	{Ais4, 96},
	{D5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{C5, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{Ais4, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{Ais4, 96},
	{A4, 192},
	{F5, 192},
	{REST, 192},
	{Gis4, 192},
	{G4, 192},
	{Dis5, 192},
	{REST, 192},
	{G4, 192},
	{F4, 192},
	{D5, 192},
	{REST, 192},
	{F4, 192},
	{Dis4, 96},
	{G4, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{F4, 96},
	{Dis4, 96},
	{D4, 96},
	{Dis4, 96},
	{F4, 96},
	{G4, 96},
	{A4, 96},
	{Ais4, 96},
	{C5, 96},
	{A4, 96},
	{Ais4, 96},
	{F4, 96},
	{G4, 96},
	{A4, 96},
	{Ais4, 96},
	{C5, 96},
	{Ais4, 96},
	{C5, 96},
	{D5, 96},
	{E5, 96},
	{D5, 96},
	{E5, 96},
	{E5, 288},
	{D5, 48},
	{E5, 48},
	{F5, 96},
	{E5, 96},
	{F5, 96},
	{G5, 96},
	{F5, 192},
	{F5, 192},
	{F5, 3168},
	{Dis5, 96},
	{F5, 96},
	{G5, 96},
	{C5, 288},
	{A5, 96},
	{Ais5, 96},
	{A5, 96},
	{Ais5, 96},
	{C6, 96},
	{Ais5, 96},
	{A5, 96},
	{G5, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{Dis5, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{Ais5, 96},
	{A5, 96},
	{G5, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{G5, 96},
	{F5, 96},
	{G5, 96},
	{Gis5, 96},
	{G5, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{B4, 96},
	{C5, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Dis5, 96},
	{C5, 96},
	{F5, 480},
	{Gis5, 96},
	{G5, 96},
	{F5, 96},
	{Dis5, 864},
	{C5, 96},
	{D5, 96},
	{Dis5, 96},
	{F5, 96},
	{G5, 96},
	{Gis5, 96},
	{F5, 96},
	{B5, 96},
	{C6, 96},
	{D6, 96},
	{B5, 96},
	{G5, 192},
	{REST, 192},
	{C5, 384},
	{G5, 384},
	{Dis5, 576},
	{D5, 192},
	{C5, 192},
	{Dis5, 192},
	{D5, 192},
	{C5, 192},
	{B4, 192},
	{D5, 192},
	{G4, 384},
	{C5, 192},
	{G4, 192},
	{D5, 192},
	{G5, 192},
	{Dis6, 192},
	{D6, 96},
	{C6, 96},
	{D6, 192},
	{G5, 192},
	{C6, 192},
	{G5, 96},
	{C6, 96},
	{D6, 192},
	{G5, 96},
	{D6, 96},
	{Dis6, 192},
	{D6, 96},
	{C6, 96},
	{D6, 96},
	{G5, 96},
	{G6, 96},
	{F6, 96},
	{Dis6, 96},
	{D6, 96},
	{C6, 96},
	{Dis6, 96},
	{D6, 96},
	{C6, 96},
	{B5, 96},
	{D6, 96},
	{C6, 96},
	{G6, 96},
	{Dis6, 96},
	{G6, 96},
	{C6, 96},
	{Dis6, 96},
	{G5, 96},
	{Ais5, 96},
	{A5, 96},
	{C6, 96},
	{A5, 96},
	{C6, 96},
	{F5, 96},
	{A5, 96},
	{C5, 96},
	{E5, 96},
	{D5, 96},
	{F6, 96},
	{D6, 96},
	{F6, 96},
	{Ais5, 96},
	{D6, 96},
	{F5, 96},
	{A5, 96},
	{G5, 96},
	{Ais5, 96},
	{G5, 96},
	{Ais5, 96},
	{Dis5, 96},
	{G5, 96},
	{Ais4, 96},
	{D5, 96},
	{C5, 96},
	{Dis6, 96},
	{C6, 96},
	{Dis6, 96},
	{A5, 96},
	{C6, 96},
	{E5, 96},
	{G5, 96},
	{Fis5, 96},
	{A5, 96},
	{Fis5, 96},
	{A5, 96},
	{D5, 96},
	{F5, 96},
	{A4, 96},
	{C5, 96},
	{Ais4, 192},
	{G5, 192},
	{A4, 192},
	{Fis5, 192},
	{G5, 384},
	{REST, 384},
	{G4, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{D5, 96},
	{A4, 96},
	{D4, 96},
	{C5, 96},
	{Ais4, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{F5, 96},
	{C5, 96},
	{F4, 96},
	{Dis5, 96},
	{D5, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{G5, 96},
	{D5, 96},
	{G4, 96},
	{F5, 96},
	{E5, 96},
	{G5, 96},
	{F5, 96},
	{Dis5, 96},
	{A5, 96},
	{Dis5, 96},
	{A4, 96},
	{G5, 96},
	{Fis5, 384},
	{G5, 192},
	{A5, 192},
	{Ais5, 1152},
	{A5, 768},
	{G5, 768},
	{Fis5, 384},
	{G5, 384},
	{REST, 576},
	{D5, 192},
	{G5, 192},
	{A5, 192},
	{Ais5, 96},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{Fis5, 96},
	{G5, 96},
	{Fis5, 96},
	{G5, 96},
	{A5, 96},
	{G5, 96},
	{Fis5, 96},
	{E5, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{Ais4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Fis4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{G4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Fis4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Ais4, 96},
	{G4, 96},
	{Fis4, 96},
	{G4, 96},
	{C5, 96},
	{G4, 96},
	{Fis4, 96},
	{G4, 96},
	{D5, 96},
	{G4, 96},
	{Fis4, 96},
	{G4, 96},
	{C5, 96},
	{G4, 96},
	{Fis4, 96},
	{G4, 96},
	{Ais4, 192},
	{G5, 192},
	{A4, 192},
	{Fis5, 192},
	{G5, 1536},
	{0, 0}
};

const Song Channel1[] = {
	{REST, 7680},
	{D5, 384},
	{A5, 384},
	{F5, 576},
	{E5, 192},
	{D5, 192},
	{F5, 192},
	{E5, 192},
	{D5, 192},
	{Cis5, 192},
	{E5, 192},
	{A4, 384},
	{D5, 192},
	{A4, 192},
	{E5, 192},
	{A4, 192},
	{F5, 192},
	{E5, 96},
	{D5, 96},
	{E5, 192},
	{A4, 192},
	{D5, 192},
	{A4, 96},
	{D5, 96},
	{E5, 192},
	{A4, 96},
	{E5, 96},
	{F5, 192},
	{E5, 96},
	{D5, 96},
	{E5, 96},
	{A4, 96},
	{A5, 96},
	{G5, 96},
	{F5, 96},
	{E5, 96},
	{D5, 96},
	{F5, 96},
	{E5, 96},
	{D5, 96},
	{Cis5, 96},
	{E5, 96},
	{D5, 96},
	{A4, 96},
	{D5, 96},
	{E5, 96},
	{F5, 96},
	{G5, 96},
	{A5, 96},
	{B5, 96},
	{C6, 96},
	{Ais5, 96},
	{C6, 96},
	{D6, 96},
	{C6, 96},
	{Ais5, 96},
	{A5, 96},
	{C6, 96},
	{Ais5, 96},
	{A5, 96},
	{Ais5, 96},
	{C6, 96},
	{Ais5, 96},
	{A5, 96},
	{G5, 96},
	{Ais5, 96},
	{A5, 192},
	{G5, 192},
	{Fis5, 192},
	{D5, 192},
	{G5, 384},
	{REST, 576},
	{D4, 192},
	{G4, 192},
	{A4, 192},
	{Ais4, 96},
	{C5, 96},
	{Ais4, 96},
	{C5, 96},
	{C5, 288},
	{Ais4, 48},
	{C5, 48},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{Ais4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Fis4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{G4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Fis4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{REST, 96},
	{G5, 96},
	{Fis5, 96},
	{G5, 96},
	{REST, 96},
	{G5, 96},
	{Fis5, 96},
	{G5, 96},
	{REST, 96},
	{G5, 96},
	{Fis5, 96},
	{G5, 96},
	{REST, 96},
	{G5, 96},
	{Fis5, 96},
	{G5, 96},
	{D5, 384},
	{C5, 384},
	{Ais4, 384},
	{REST, 7488},
	{A4, 192},
	{D5, 192},
	{C5, 192},
	{Ais4, 960},
	{G4, 192},
	{C5, 192},
	{Ais4, 192},
	{A4, 1152},
	{G4, 768},
	{Fis4, 384},
	{G4, 192},
	{REST, 12096},
	{Ais4, 384},
	{F5, 384},
	{D5, 576},
	{C5, 192},
	{Ais4, 192},
	{D5, 192},
	{C5, 192},
	{Ais4, 192},
	{A4, 192},
	{C5, 192},
	{REST, 192},
	{F5, 192},
	{F5, 3840},
	{REST, 12480},
	{F5, 192},
	{Ais5, 192},
	{A5, 192},
	{G5, 960},
	{C5, 192},
	{A5, 192},
	{G5, 192},
	{F5, 960},
	{Ais4, 192},
	{G5, 192},
	{F5, 192},
	{Dis5, 864},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{B4, 384},
	{C5, 384},
	{REST, 576},
	{C6, 192},
	{Gis5, 192},
	{F5, 672},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{B4, 96},
	{D5, 96},
	{C5, 96},
	{G4, 96},
	{C5, 96},
	{D5, 96},
	{Dis5, 96},
	{F5, 96},
	{Dis5, 96},
	{F5, 96},
	{G5, 96},
	{Dis5, 96},
	{C5, 96},
	{Dis5, 96},
	{Gis5, 96},
	{F5, 96},
	{G5, 96},
	{Gis5, 96},
	{D5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{B4, 192},
	{D5, 192},
	{G5, 3264},
	{G6, 192},
	{F6, 96},
	{Dis6, 96},
	{D6, 96},
	{F6, 96},
	{Dis6, 384},
	{REST, 576},
	{C6, 192},
	{A5, 192},
	{F5, 192},
	{Ais5, 960},
	{Ais5, 192},
	{G5, 192},
	{Dis5, 192},
	{C6, 960},
	{C6, 192},
	{Fis5, 192},
	{D5, 192},
	{G5, 384},
	{REST, 384},
	{G4, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{D5, 96},
	{A4, 96},
	{D4, 96},
	{C5, 96},
	{Ais4, 192},
	{D5, 192},
	{A4, 192},
	{D5, 384},
	{G5, 192},
	{C5, 192},
	{F5, 384},
	{F5, 192},
	{D5, 192},
	{G5, 384},
	{G5, 192},
	{Dis5, 192},
	{A5, 288},
	{Dis6, 96},
	{D6, 96},
	{C6, 96},
	{Ais5, 96},
	{D6, 96},
	{A5, 96},
	{D6, 96},
	{G5, 96},
	{Gis6, 96},
	{G6, 96},
	{F6, 96},
	{G6, 96},
	{F6, 96},
	{Dis6, 96},
	{D6, 96},
	{Dis6, 768},
	{D6, 768},
	{C6, 768},
	{Ais5, 96},
	{D6, 96},
	{C6, 96},
	{Ais5, 96},
	{A5, 96},
	{Ais5, 96},
	{G5, 96},
	{A5, 96},
	{Ais5, 96},
	{C6, 96},
	{Ais5, 96},
	{C6, 96},
	{D6, 96},
	{Dis6, 96},
	{D6, 96},
	{C6, 96},
	{Ais5, 192},
	{D6, 192},
	{C6, 192},
	{Ais5, 192},
	{A5, 384},
	{REST, 192},
	{D5, 192},
	{D5, 3264},
	{Dis5, 192},
	{Dis5, 192},
	{D5, 192},
	{D5, 1536},
	{0, 0}
};

const Song Channel2[] = {
	{REST, 17664},
	{G4, 384},
	{D5, 384},
	{Ais4, 576},
	{A4, 192},
	{G4, 192},
	{Ais4, 192},
	{A4, 192},
	{G4, 192},
	{Fis4, 192},
	{A4, 192},
	{D4, 384},
	{G4, 192},
	{D4, 192},
	{A4, 192},
	{D4, 192},
	{Ais4, 192},
	{A4, 96},
	{G4, 96},
	{A4, 192},
	{D4, 192},
	{G4, 192},
	{D4, 96},
	{G4, 96},
	{A4, 192},
	{D4, 96},
	{A4, 96},
	{Ais4, 192},
	{A4, 96},
	{G4, 96},
	{A4, 96},
	{D4, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{Fis4, 96},
	{A4, 96},
	{G4, 96},
	{D4, 96},
	{G4, 96},
	{A4, 96},
	{Ais4, 96},
	{C5, 96},
	{D5, 96},
	{E5, 96},
	{F5, 96},
	{E5, 96},
	{D5, 96},
	{F5, 96},
	{E5, 96},
	{D5, 96},
	{Cis5, 96},
	{E5, 96},
	{D5, 192},
	{A4, 192},
	{D5, 192},
	{E5, 192},
	{F5, 96},
	{G5, 96},
	{F5, 96},
	{G5, 96},
	{G5, 288},
	{F5, 48},
	{G5, 48},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{Ais5, 96},
	{A5, 96},
	{G5, 96},
	{F5, 96},
	{E5, 96},
	{F5, 96},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{Cis5, 96},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{D5, 96},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{Cis5, 96},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{F5, 96},
	{D5, 96},
	{Cis5, 96},
	{D5, 96},
	{G5, 96},
	{D5, 96},
	{Cis5, 96},
	{D5, 96},
	{A5, 96},
	{D5, 96},
	{Cis5, 96},
	{D5, 96},
	{G5, 96},
	{D5, 96},
	{Cis5, 96},
	{D5, 96},
	{F5, 192},
	{E5, 96},
	{D5, 96},
	{Cis5, 288},
	{D5, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{E5, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{F4, 96},
	{G4, 96},
	{A4, 96},
	{G4, 96},
	{F4, 96},
	{Dis4, 96},
	{D4, 96},
	{C4, 96},
	{Ais3, 96},
	{C4, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{F4, 96},
	{Dis4, 96},
	{F4, 96},
	{G4, 96},
	{F4, 96},
	{Dis4, 96},
	{D4, 96},
	{C4, 96},
	{Ais3, 96},
	{Ais4, 96},
	{C5, 96},
	{D5, 96},
	{Dis5, 384},
	{REST, 96},
	{A4, 96},
	{Ais4, 96},
	{C5, 96},
	{D5, 384},
	{G4, 384},
	{D5, 384},
	{Ais4, 576},
	{A4, 192},
	{G4, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{Fis4, 96},
	{G4, 96},
	{E4, 96},
	{Fis4, 96},
	{G4, 96},
	{D4, 96},
	{E4, 96},
	{Fis4, 96},
	{G4, 96},
	{D4, 96},
	{G4, 96},
	{A4, 96},
	{Ais4, 96},
	{C5, 96},
	{Ais4, 96},
	{C5, 96},
	{A4, 288},
	{Ais4, 48},
	{C5, 48},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{Ais4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Fis4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{G4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Fis4, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Ais4, 96},
	{G4, 96},
	{Fis4, 96},
	{G4, 96},
	{C5, 96},
	{G4, 96},
	{Fis4, 96},
	{G4, 96},
	{D5, 96},
	{G4, 96},
	{Fis4, 96},
	{G4, 96},
	{C5, 96},
	{G4, 96},
	{Fis4, 96},
	{G4, 96},
	{G4, 192},
	{Ais4, 192},
	{C5, 96},
	{Ais4, 96},
	{G4, 96},
	{C5, 96},
	{Ais4, 480},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 480},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 480},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{F4, 576},
	{E4, 192},
	{F4, 192},
	{Dis4, 192},
	{D4, 192},
	{C4, 192},
	{Ais3, 384},
	{REST, 576},
	{C5, 192},
	{Ais4, 192},
	{A4, 192},
	{G4, 768},
	{F4, 384},
	{F4, 384},
	{Ais4, 192},
	{F4, 192},
	{C5, 192},
	{F4, 192},
	{D5, 192},
	{C5, 96},
	{Ais4, 96},
	{C5, 192},
	{F4, 192},
	{Ais4, 192},
	{F4, 96},
	{Ais4, 96},
	{C5, 192},
	{F5, 96},
	{C5, 96},
	{D5, 192},
	{C5, 96},
	{Ais4, 96},
	{C5, 96},
	{F4, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{C5, 96},
	{Ais4, 192},
	{G5, 192},
	{REST, 192},
	{G4, 192},
	{A4, 192},
	{F5, 192},
	{REST, 192},
	{F4, 192},
	{G4, 192},
	{F5, 192},
	{C5, 192},
	{E5, 192},
	{F5, 96},
	{Dis5, 96},
	{F5, 96},
	{G5, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{Dis5, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{D5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{C5, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{A4, 96},
	{C5, 96},
	{Ais4, 96},
	{C5, 96},
	{D5, 96},
	{Ais4, 96},
	{C5, 96},
	{D5, 96},
	{Dis5, 96},
	{C5, 96},
	{D5, 96},
	{C5, 96},
	{Ais4, 96},
	{C5, 96},
	{D5, 96},
	{Dis5, 96},
	{D5, 96},
	{Dis5, 96},
	{F5, 96},
	{G5, 96},
	{F5, 96},
	{G5, 96},
	{G5, 288},
	{F5, 48},
	{G5, 48},
	{A5, 96},
	{G5, 96},
	{A5, 96},
	{Ais5, 96},
	{A5, 96},
	{G5, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{F5, 96},
	{Dis5, 96},
	{F5, 96},
	{A4, 96},
	{F5, 96},
	{Dis5, 96},
	{F5, 96},
	{Ais4, 96},
	{F5, 96},
	{Dis5, 96},
	{F5, 96},
	{A4, 96},
	{F5, 96},
	{Dis5, 96},
	{F5, 96},
	{D5, 96},
	{Ais5, 96},
	{A5, 96},
	{Ais5, 96},
	{Dis5, 96},
	{Ais5, 96},
	{A5, 96},
	{Ais5, 96},
	{F4, 96},
	{Ais5, 96},
	{A5, 96},
	{Ais5, 96},
	{Dis5, 96},
	{Ais5, 96},
	{A5, 96},
	{Ais5, 96},
	{Ais5, 96},
	{D6, 96},
	{C6, 96},
	{Ais5, 96},
	{A5, 96},
	{G5, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 960},
	{G4, 192},
	{C5, 192},
	{Ais4, 192},
	{A4, 960},
	{F4, 192},
	{Ais4, 192},
	{A4, 192},
	{G4, 960},
	{Dis4, 192},
	{Gis4, 192},
	{G4, 192},
	{F4, 384},
	{G4, 480},
	{G4, 96},
	{A4, 96},
	{B4, 96},
	{C5, 96},
	{D5, 96},
	{Dis5, 96},
	{C5, 96},
	{Gis4, 768},
	{G4, 192},
	{A4, 192},
	{B4, 384},
	{C5, 192},
	{REST, 6912},
	{G4, 192},
	{Dis4, 192},
	{C4, 192},
	{F5, 384},
	{REST, 576},
	{F5, 192},
	{D5, 192},
	{Ais4, 192},
	{Dis5, 384},
	{REST, 576},
	{Dis5, 192},
	{C5, 192},
	{A4, 192},
	{D5, 384},
	{REST, 384},
	{G4, 96},
	{Ais4, 96},
	{A4, 96},
	{G4, 96},
	{D5, 96},
	{A4, 96},
	{D4, 96},
	{C5, 96},
	{Ais4, 192},
	{D5, 192},
	{Fis4, 192},
	{D5, 192},
	{G4, 384},
	{Fis4, 384},
	{G4, 384},
	{A4, 384},
	{Ais4, 384},
	{B4, 384},
	{C5, 384},
	{Cis5, 384},
	{D5, 384},
	{E5, 192},
	{Fis5, 192},
	{G5, 384},
	{A5, 192},
	{Ais5, 192},
	{C6, 96},
	{G5, 96},
	{F5, 96},
	{Dis5, 96},
	{C6, 96},
	{A5, 96},
	{F5, 96},
	{A5, 96},
	{Ais5, 96},
	{F5, 96},
	{Dis5, 96},
	{D5, 96},
	{Ais5, 96},
	{G5, 96},
	{Dis5, 96},
	{G5, 96},
	{A5, 96},
	{Dis5, 96},
	{D5, 96},
	{C5, 96},
	{A5, 96},
	{Fis5, 96},
	{D5, 96},
	{Fis5, 96},
	{G4, 96},
	{Ais4, 96},
	{D5, 96},
	{G5, 96},
	{Fis5, 96},
	{G5, 96},
	{E5, 96},
	{Fis5, 96},
	{G5, 576},
	{Fis5, 192},
	{G5, 384},
	{A5, 192},
	{D5, 192},
	{Ais4, 384},
	{REST, 192},
	{Fis4, 192},
	{G4, 192},
	{REST, 192},
	{C5, 192},
	{REST, 192},
	{Ais4, 192},
	{REST, 192},
	{C5, 192},
	{REST, 192},
	{Ais4, 192},
	{REST, 192},
	{A4, 192},
	{REST, 192},
	{G4, 192},
	{REST, 192},
	{A4, 192},
	{REST, 192},
	{G4, 192},
	{Ais4, 192},
	{C5, 192},
	{A4, 192},
	{Ais4, 1536},
	{0, 0}
};

const Song Channel3[] = {
	{REST, 25344},
	{D4, 384},
	{A4, 384},
	{F4, 576},
	{E4, 192},
	{D4, 192},
	{F4, 192},
	{E4, 192},
	{D4, 192},
	{Cis4, 192},
	{E4, 192},
	{A3, 384},
	{D4, 192},
	{A3, 192},
	{E4, 192},
	{A3, 192},
	{F4, 192},
	{E4, 96},
	{D4, 96},
	{E4, 192},
	{A3, 192},
	{D4, 192},
	{A3, 96},
	{D4, 96},
	{E4, 192},
	{A3, 96},
	{E4, 96},
	{F4, 192},
	{E4, 96},
	{D4, 96},
	{E4, 192},
	{A3, 192},
	{D4, 192},
	{G3, 192},
	{A3, 384},
	{D3, 384},
	{REST, 6720},
	{G3, 192},
	{G4, 192},
	{F4, 192},
	{Dis4, 192},
	{REST, 192},
	{Dis3, 192},
	{REST, 192},
	{D3, 192},
	{D4, 192},
	{D4, 4608},
	{C4, 768},
	{Ais3, 768},
	{A3, 384},
	{Ais3, 192},
	{A3, 192},
	{G3, 384},
	{F3, 384},
	{REST, 12672},
	{Ais3, 384},
	{F4, 384},
	{D4, 576},
	{C4, 192},
	{Ais3, 192},
	{D4, 192},
	{C4, 192},
	{Ais3, 192},
	{A3, 192},
	{C4, 192},
	{F3, 384},
	{Ais3, 192},
	{F3, 192},
	{C4, 192},
	{F3, 192},
	{D4, 192},
	{C4, 96},
	{Ais3, 96},
	{C4, 192},
	{F3, 192},
	{Ais3, 192},
	{F3, 96},
	{Ais3, 96},
	{C4, 192},
	{F3, 96},
	{C4, 96},
	{D4, 192},
	{C4, 96},
	{Ais3, 96},
	{C4, 192},
	{F3, 192},
	{D4, 192},
	{Dis4, 192},
	{F4, 192},
	{F3, 192},
	{Ais3, 384},
	{REST, 384},
	{C4, 384},
	{REST, 384},
	{F3, 384},
	{REST, 384},
	{Ais3, 384},
	{REST, 384},
	{Dis3, 384},
	{REST, 384},
	{Gis3, 384},
	{REST, 384},
	{D3, 384},
	{G3, 384},
	{C3, 384},
	{REST, 384},
	{F3, 384},
	{REST, 384},
	{G3, 1536},
	{C3, 192},
	{G3, 192},
	{C4, 192},
	{D4, 192},
	{Dis4, 384},
	{F4, 384},
	{G4, 480},
	{G4, 96},
	{F4, 96},
	{G4, 96},
	{Dis4, 96},
	{G4, 96},
	{F4, 96},
	{G4, 96},
	{B3, 96},
	{G4, 96},
	{F4, 96},
	{G4, 96},
	{C4, 96},
	{G4, 96},
	{F4, 96},
	{G4, 96},
	{B3, 96},
	{G4, 96},
	{F4, 96},
	{G4, 96},
	{Dis4, 96},
	{C5, 96},
	{B4, 96},
	{C5, 96},
	{F4, 96},
	{C5, 96},
	{B4, 96},
	{C5, 96},
	{G4, 96},
	{C5, 96},
	{B4, 96},
	{C5, 96},
	{G4, 96},
	{B4, 96},
	{A4, 96},
	{B4, 96},
	{C4, 192},
	{Dis4, 192},
	{F4, 192},
	{G4, 192},
	{C4, 384},
	{REST, 12672},
	{G4, 384},
	{D5, 384},
	{Ais4, 576},
	{A4, 192},
	{G4, 192},
	{Ais4, 192},
	{A4, 192},
	{G4, 192},
	{Fis4, 192},
	{A4, 192},
	{D4, 384},
	{G4, 192},
	{D4, 192},
	{A4, 192},
	{D4, 192},
	{Ais4, 192},
	{A4, 96},
	{G4, 96},
	{A4, 192},
	{D4, 192},
	{G4, 192},
	{D4, 96},
	{G4, 96},
	{A4, 192},
	{D4, 96},
	{A4, 96},
	{Ais4, 192},
	{A4, 96},
	{G4, 96},
	{A4, 192},
	{D4, 192},
	{G4, 192},
	{Dis4, 192},
	{C4, 192},
	{D4, 192},
	{G3, 1536},
	{0, 0}
};

