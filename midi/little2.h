/* little2.h: .midi -> .csv -> C struct
 * Copyright (c) 2017 Trey Boehm
 */

#include "SoundMacros.h"

#define TEMPO 714285

typedef struct song_struct {
    uint32_t pitch;
    uint32_t duration;
} Song;


const Song Channel0 = {
	{G5, 480},
	{REST, 480},
	{Ais5, 720},
	{REST, 240},
	{G5, 240},
	{REST, 240},
	{A5, 240},
	{REST, 240},
	{Fis5, 240},
	{REST, 240},
	{D5, 480},
	{REST, 240},
	{D5, 240},
	{REST, 240},
	{D5, 240},
	{REST, 240},
	{A5, 120},
	{REST, 120},
	{A5, 240},
	{REST, 240},
	{G5, 240},
	{REST, 120},
	{G5, 120},
	{REST, 240},
	{D5, 120},
	{REST, 120},
	{Ais5, 240},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{E6, 120},
	{REST, 120},
	{E6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{E6, 120},
	{REST, 240},
	{A5, 240},
	{REST, 240},
	{E6, 240},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 360},
	{F6, 60},
	{REST, 60},
	{A6, 120},
	{REST, 120},
	{A6, 120},
	{REST, 120},
	{A6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{Cis6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{Cis6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{Cis6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{Cis6, 120},
	{REST, 120},
	{A6, 120},
	{REST, 120},
	{Cis6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{Cis6, 120},
	{REST, 120},
	{A5, 240},
	{REST, 240},
	{G5, 240},
	{REST, 240},
	{F5, 240},
	{REST, 240},
	{D6, 240},
	{REST, 240},
	{Dis6, 240},
	{REST, 480},
	{Dis6, 240},
	{REST, 240},
	{G6, 480},
	{REST, 240},
	{C6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{Fis6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{E6, 120},
	{REST, 120},
	{G6, 2880},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 480},
	{C6, 480},
	{REST, 480},
	{C6, 720},
	{REST, 480},
	{A5, 480},
	{REST, 240},
	{G5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{A5, 240},
	{REST, 240},
	{Cis6, 240},
	{REST, 240},
	{A6, 120},
	{REST, 120},
	{A6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 480},
	{REST, 480},
	{E6, 720},
	{REST, 240},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{Ais6, 30},
	{REST, 30},
	{A6, 3000},
	{REST, 120},
	{A6, 120},
	{REST, 120},
	{A6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{F6, 1200},
	{REST, 240},
	{G6, 240},
	{REST, 240},
	{Dis6, 1200},
	{REST, 240},
	{F6, 240},
	{REST, 240},
	{D6, 600},
	{REST, 120},
	{Fis6, 120},
	{REST, 120},
	{C6, 600},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Fis5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{E5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{Ais5, 720},
	{REST, 240},
	{G5, 240},
	{REST, 240},
	{A5, 240},
	{REST, 240},
	{Fis5, 240},
	{REST, 240},
	{D5, 480},
	{REST, 240},
	{D5, 240},
	{REST, 240},
	{D5, 240},
	{REST, 240},
	{A5, 120},
	{REST, 120},
	{A5, 240},
	{REST, 240},
	{G5, 240},
	{REST, 120},
	{G5, 120},
	{REST, 240},
	{D5, 120},
	{REST, 120},
	{Ais5, 240},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{E6, 120},
	{REST, 120},
	{E6, 120},
	{REST, 360},
	{D6, 60},
	{REST, 60},
	{F6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{A5, 240},
	{REST, 480},
	{Gis5, 240},
	{REST, 240},
	{Dis6, 480},
	{REST, 240},
	{F5, 240},
	{REST, 480},
	{F5, 240},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{E6, 120},
	{REST, 120},
	{E6, 120},
	{REST, 360},
	{D6, 60},
	{REST, 60},
	{F6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{F6, 240},
	{REST, 240},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{G6, 30},
	{REST, 30},
	{F6, 2040},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{C6, 360},
	{REST, 120},
	{Ais6, 120},
	{REST, 120},
	{Ais6, 120},
	{REST, 120},
	{Ais6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{A6, 120},
	{REST, 120},
	{A6, 120},
	{REST, 120},
	{A6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{F6, 600},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{Dis6, 1080},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{Gis6, 120},
	{REST, 120},
	{B5, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{G5, 480},
	{REST, 480},
	{G6, 480},
	{REST, 720},
	{D6, 240},
	{REST, 240},
	{Dis6, 240},
	{REST, 240},
	{C6, 240},
	{REST, 240},
	{D6, 240},
	{REST, 480},
	{C6, 240},
	{REST, 240},
	{D6, 240},
	{REST, 240},
	{Dis6, 240},
	{REST, 120},
	{C6, 120},
	{REST, 240},
	{G5, 240},
	{REST, 240},
	{G5, 120},
	{REST, 120},
	{D6, 240},
	{REST, 120},
	{D6, 120},
	{REST, 240},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{B5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{E5, 120},
	{REST, 120},
	{Fis5, 120},
	{REST, 120},
	{Fis5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{A4, 120},
	{REST, 120},
	{Ais4, 240},
	{REST, 240},
	{A4, 240},
	{REST, 240},
	{G5, 960},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{E6, 120},
	{REST, 120},
	{E6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 480},
	{G6, 240},
	{REST, 240},
	{Ais6, 1440},
	{REST, 960},
	{G6, 960},
	{REST, 480},
	{G6, 1200},
	{REST, 240},
	{G6, 240},
	{REST, 240},
	{Ais6, 120},
	{REST, 120},
	{G6, 120},
	{REST, 120},
	{Fis6, 120},
	{REST, 120},
	{Fis6, 120},
	{REST, 120},
	{A6, 120},
	{REST, 120},
	{Fis6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{Fis5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{Fis5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{Fis5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{Fis5, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{Fis5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{Fis5, 120},
	{REST, 120},
	{Ais5, 240},
	{REST, 240},
	{A5, 240},
	{REST, 240},
	{G6, -119040},
	{0, 0}
};

const Song Channel1 = {
	{A5, 480},
	{REST, 720},
	{E5, 240},
	{REST, 240},
	{F5, 240},
	{REST, 240},
	{D5, 240},
	{REST, 240},
	{E5, 240},
	{REST, 480},
	{D5, 240},
	{REST, 240},
	{E5, 240},
	{REST, 240},
	{F5, 240},
	{REST, 120},
	{D5, 120},
	{REST, 240},
	{A4, 240},
	{REST, 240},
	{A4, 120},
	{REST, 120},
	{E5, 240},
	{REST, 120},
	{E5, 120},
	{REST, 240},
	{E5, 120},
	{REST, 120},
	{E5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{E5, 120},
	{REST, 120},
	{Cis5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{A5, 240},
	{REST, 240},
	{Fis5, 240},
	{REST, 240},
	{G5, 1200},
	{REST, 240},
	{G5, 240},
	{REST, 240},
	{Ais5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{C6, 360},
	{REST, 60},
	{C6, 60},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{Dis6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 480},
	{C5, 480},
	{REST, 480},
	{C5, 600},
	{REST, 120},
	{Fis5, 120},
	{REST, 240},
	{G5, 120},
	{REST, 120},
	{G5, 240},
	{REST, 120},
	{Fis5, 120},
	{REST, 240},
	{G5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 480},
	{C5, 480},
	{REST, 9840},
	{A5, 240},
	{REST, 240},
	{C6, 240},
	{REST, 1200},
	{G5, 240},
	{REST, 240},
	{Ais5, 240},
	{REST, 1440},
	{G5, 960},
	{REST, 480},
	{G5, 15360},
	{REST, 480},
	{F5, 480},
	{REST, 720},
	{C5, 240},
	{REST, 240},
	{D5, 240},
	{REST, 240},
	{Ais4, 240},
	{REST, 240},
	{C5, 480},
	{REST, 240},
	{F5, 20400},
	{REST, 240},
	{Ais5, 240},
	{REST, 240},
	{G5, 1200},
	{REST, 240},
	{A5, 240},
	{REST, 240},
	{F5, 1200},
	{REST, 240},
	{G5, 240},
	{REST, 240},
	{Dis5, 1080},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{B4, 480},
	{REST, 1200},
	{C5, 240},
	{REST, 240},
	{F5, 840},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{B4, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{Gis5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{B4, 240},
	{REST, 240},
	{G4, 4080},
	{REST, 240},
	{F5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{Dis5, 1200},
	{REST, 240},
	{A4, 240},
	{REST, 240},
	{Ais4, 1200},
	{REST, 240},
	{G4, 240},
	{REST, 240},
	{A4, 1200},
	{REST, 240},
	{Fis4, 240},
	{REST, 240},
	{G4, 960},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{G4, 120},
	{REST, 120},
	{A4, 120},
	{REST, 120},
	{C5, 120},
	{REST, 240},
	{D5, 240},
	{REST, 240},
	{D5, 480},
	{REST, 240},
	{C5, 240},
	{REST, 480},
	{F5, 240},
	{REST, 240},
	{G5, 480},
	{REST, 240},
	{E5, 240},
	{REST, 360},
	{Dis6, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{Gis6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{F6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 960},
	{D6, 960},
	{REST, 960},
	{Ais5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{D6, 120},
	{REST, 120},
	{Ais5, 240},
	{REST, 240},
	{C6, 240},
	{REST, 240},
	{A5, 720},
	{REST, 240},
	{D5, 4080},
	{REST, 240},
	{Dis5, 240},
	{REST, 240},
	{D5, -106560},
	{0, 0}
};

const Song Channel2 = {
	{D5, 480},
	{REST, 720},
	{A4, 240},
	{REST, 240},
	{Ais4, 240},
	{REST, 240},
	{G4, 240},
	{REST, 240},
	{A4, 240},
	{REST, 480},
	{G4, 240},
	{REST, 240},
	{A4, 240},
	{REST, 240},
	{Ais4, 240},
	{REST, 120},
	{G4, 120},
	{REST, 240},
	{D4, 240},
	{REST, 240},
	{D4, 120},
	{REST, 120},
	{A4, 240},
	{REST, 120},
	{A4, 120},
	{REST, 240},
	{A4, 120},
	{REST, 120},
	{A4, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{G4, 120},
	{REST, 120},
	{A4, 120},
	{REST, 120},
	{Fis4, 120},
	{REST, 120},
	{G4, 120},
	{REST, 120},
	{G4, 120},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{E5, 120},
	{REST, 120},
	{Cis5, 120},
	{REST, 120},
	{D5, 240},
	{REST, 240},
	{D5, 240},
	{REST, 240},
	{F5, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{G5, 360},
	{REST, 60},
	{G5, 60},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{E5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 240},
	{E5, 120},
	{REST, 120},
	{Cis5, 360},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{G4, 120},
	{REST, 120},
	{G4, 120},
	{REST, 120},
	{G4, 120},
	{REST, 120},
	{Dis4, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{A4, 120},
	{REST, 120},
	{F4, 120},
	{REST, 120},
	{F4, 120},
	{REST, 120},
	{F4, 120},
	{REST, 120},
	{D4, 120},
	{REST, 120},
	{Ais3, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{Dis5, 600},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{D5, 480},
	{REST, 480},
	{D5, 480},
	{REST, 720},
	{A4, 240},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{G4, 120},
	{REST, 120},
	{G4, 120},
	{REST, 120},
	{Fis4, 120},
	{REST, 120},
	{D4, 120},
	{REST, 120},
	{Fis4, 120},
	{REST, 120},
	{D4, 120},
	{REST, 120},
	{A4, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 360},
	{Ais4, 60},
	{REST, 60},
	{D5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{Fis4, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{G4, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{Fis4, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{Fis4, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{Fis4, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{Fis4, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{Fis4, 120},
	{REST, 120},
	{G4, 240},
	{REST, 240},
	{C5, 120},
	{REST, 120},
	{G4, 120},
	{REST, 120},
	{Ais4, 600},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{A4, 600},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{G4, 600},
	{REST, 120},
	{A4, 120},
	{REST, 120},
	{F4, 720},
	{REST, 240},
	{F4, 240},
	{REST, 240},
	{D4, 240},
	{REST, 240},
	{Ais3, 1200},
	{REST, 240},
	{Ais4, 240},
	{REST, 240},
	{G4, 960},
	{REST, 480},
	{F4, 480},
	{REST, 240},
	{F4, 240},
	{REST, 240},
	{F4, 240},
	{REST, 240},
	{C5, 120},
	{REST, 120},
	{C5, 240},
	{REST, 240},
	{Ais4, 240},
	{REST, 120},
	{Ais4, 120},
	{REST, 240},
	{F4, 120},
	{REST, 120},
	{D5, 240},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{F4, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{C5, 120},
	{REST, 240},
	{G5, 480},
	{REST, 240},
	{A4, 240},
	{REST, 480},
	{F4, 240},
	{REST, 240},
	{F5, 240},
	{REST, 240},
	{E5, 240},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 120},
	{G5, 120},
	{REST, 360},
	{F5, 60},
	{REST, 60},
	{A5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{A4, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{Ais4, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{A4, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{D5, 1200},
	{REST, 240},
	{C5, 240},
	{REST, 240},
	{A4, 1200},
	{REST, 240},
	{Ais4, 240},
	{REST, 240},
	{G4, 1200},
	{REST, 240},
	{Gis4, 240},
	{REST, 240},
	{F4, 480},
	{REST, 600},
	{G4, 120},
	{REST, 120},
	{B4, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{C5, 120},
	{REST, 960},
	{G4, 240},
	{REST, 240},
	{B4, 480},
	{REST, 8880},
	{G4, 240},
	{REST, 240},
	{C4, 240},
	{REST, 1200},
	{F4, 240},
	{REST, 240},
	{Ais3, 240},
	{REST, 1200},
	{Dis4, 240},
	{REST, 240},
	{A3, 240},
	{REST, 960},
	{G3, 120},
	{REST, 120},
	{A3, 120},
	{REST, 120},
	{D4, 120},
	{REST, 120},
	{D3, 120},
	{REST, 120},
	{Ais3, 240},
	{REST, 240},
	{Fis3, 240},
	{REST, 240},
	{G4, 480},
	{REST, 480},
	{G4, 480},
	{REST, 480},
	{Ais4, 480},
	{REST, 480},
	{C5, 480},
	{REST, 480},
	{D5, 480},
	{REST, 240},
	{Fis5, 240},
	{REST, 480},
	{A5, 240},
	{REST, 240},
	{C6, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{C6, 120},
	{REST, 120},
	{F5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{Ais5, 120},
	{REST, 120},
	{Dis5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{A5, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{G4, 120},
	{REST, 120},
	{D5, 120},
	{REST, 120},
	{Fis5, 120},
	{REST, 120},
	{E5, 120},
	{REST, 120},
	{G5, 720},
	{REST, 240},
	{G5, 480},
	{REST, 240},
	{D5, 240},
	{REST, 720},
	{Fis4, 240},
	{REST, 480},
	{C5, 480},
	{REST, 480},
	{C5, 480},
	{REST, 480},
	{A4, 480},
	{REST, 480},
	{A4, 480},
	{REST, 240},
	{Ais4, 240},
	{REST, 240},
	{A4, 240},
	{0, 0}
};

const Song Channel3 = {
	{REST, 31680},
	{D4, 480},
	{REST, 480},
	{F4, 720},
	{REST, 240},
	{D4, 240},
	{REST, 240},
	{E4, 240},
	{REST, 240},
	{Cis4, 240},
	{REST, 240},
	{A3, 480},
	{REST, 240},
	{A3, 240},
	{REST, 240},
	{A3, 240},
	{REST, 240},
	{E4, 120},
	{REST, 120},
	{E4, 240},
	{REST, 240},
	{D4, 240},
	{REST, 120},
	{D4, 120},
	{REST, 240},
	{A3, 120},
	{REST, 120},
	{F4, 240},
	{REST, 120},
	{D4, 120},
	{REST, 240},
	{A3, 240},
	{REST, 240},
	{G3, 240},
	{REST, 480},
	{D3, 8880},
	{REST, 240},
	{G4, 240},
	{REST, 240},
	{Dis4, 480},
	{REST, 480},
	{D3, 240},
	{REST, 240},
	{D4, 5760},
	{REST, 960},
	{Ais3, 960},
	{REST, 480},
	{Ais3, 240},
	{REST, 240},
	{G3, 480},
	{REST, 16320},
	{Ais3, 480},
	{REST, 480},
	{D4, 720},
	{REST, 240},
	{Ais3, 240},
	{REST, 240},
	{C4, 240},
	{REST, 240},
	{A3, 240},
	{REST, 240},
	{F3, 480},
	{REST, 240},
	{F3, 240},
	{REST, 240},
	{F3, 240},
	{REST, 240},
	{C4, 120},
	{REST, 120},
	{C4, 240},
	{REST, 240},
	{Ais3, 240},
	{REST, 120},
	{Ais3, 120},
	{REST, 240},
	{F3, 120},
	{REST, 120},
	{D4, 240},
	{REST, 120},
	{Ais3, 120},
	{REST, 240},
	{F3, 240},
	{REST, 240},
	{Dis4, 240},
	{REST, 240},
	{F3, 240},
	{REST, 960},
	{C4, 960},
	{REST, 960},
	{Ais3, 960},
	{REST, 960},
	{Gis3, 960},
	{REST, 480},
	{G3, 480},
	{REST, 960},
	{F3, 960},
	{REST, 1920},
	{C3, 240},
	{REST, 240},
	{C4, 240},
	{REST, 240},
	{Dis4, 480},
	{REST, 480},
	{G4, 600},
	{REST, 120},
	{F4, 120},
	{REST, 120},
	{Dis4, 120},
	{REST, 120},
	{F4, 120},
	{REST, 120},
	{B3, 120},
	{REST, 120},
	{F4, 120},
	{REST, 120},
	{C4, 120},
	{REST, 120},
	{F4, 120},
	{REST, 120},
	{B3, 120},
	{REST, 120},
	{F4, 120},
	{REST, 120},
	{Dis4, 120},
	{REST, 120},
	{B4, 120},
	{REST, 120},
	{F4, 120},
	{REST, 120},
	{B4, 120},
	{REST, 120},
	{G4, 120},
	{REST, 120},
	{B4, 120},
	{REST, 120},
	{G4, 120},
	{REST, 120},
	{A4, 120},
	{REST, 120},
	{C4, 240},
	{REST, 240},
	{F4, 240},
	{REST, 240},
	{C4, 16320},
	{REST, 480},
	{D5, 480},
	{REST, 720},
	{A4, 240},
	{REST, 240},
	{Ais4, 240},
	{REST, 240},
	{G4, 240},
	{REST, 240},
	{A4, 240},
	{REST, 480},
	{G4, 240},
	{REST, 240},
	{A4, 240},
	{REST, 240},
	{Ais4, 240},
	{REST, 120},
	{G4, 120},
	{REST, 240},
	{D4, 240},
	{REST, 240},
	{D4, 120},
	{REST, 120},
	{A4, 240},
	{REST, 120},
	{A4, 120},
	{REST, 240},
	{A4, 120},
	{REST, 120},
	{A4, 240},
	{REST, 240},
	{G4, 240},
	{REST, 240},
	{C4, 240},
	{REST, 240},
	{0, 0}
};

