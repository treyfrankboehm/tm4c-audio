/* %s.h: .midi -> .csv -> C struct
 * Copyright (c) 2017 Trey Boehm
 */

#include "SoundMacros.h"
#include "custom_types.h"

const Tempo_Times Tempos[] = {
	{0, 300000},
	{6912, 357142},
};

const Song Channel0[] = {
	{E7, 96, 101},
	{F7, 96, 101},
	{E7, 96, 101},
	{D7, 96, 101},
	{E7, 96, 101},
	{D7, 96, 101},
	{Cis7, 96, 101},
	{D7, 96, 101},
	{E7, 96, 101},
	{D7, 96, 101},
	{Cis7, 96, 101},
	{D7, 96, 101},
	{E7, 96, 101},
	{F7, 96, 101},
	{E7, 96, 101},
	{D7, 96, 101},
	{E7, 96, 101},
	{D7, 96, 101},
	{Cis7, 96, 101},
	{D7, 96, 101},
	{E7, 96, 101},
	{D7, 96, 101},
	{Cis7, 96, 101},
	{D7, 96, 101},
	{E7, 96, 101},
	{F7, 96, 101},
	{E7, 96, 101},
	{D7, 96, 101},
	{E7, 96, 101},
	{D7, 96, 101},
	{Cis7, 96, 101},
	{D7, 96, 101},
	{E7, 96, 101},
	{D7, 96, 101},
	{Cis7, 96, 101},
	{D7, 96, 101},
	{G7, 96, 101},
	{F7, 96, 101},
	{D7, 96, 101},
	{C7, 96, 101},
	{Ais6, 96, 101},
	{G6, 96, 101},
	{Ais6, 96, 101},
	{C7, 96, 101},
	{Cis7, 96, 101},
	{C7, 96, 101},
	{Ais6, 96, 101},
	{G6, 96, 101},
	{F6, 96, 101},
	{D6, 96, 101},
	{Ais6, 96, 101},
	{G6, 96, 101},
	{F6, 96, 101},
	{D6, 96, 101},
	{C6, 96, 101},
	{Ais5, 96, 101},
	{D6, 96, 101},
	{C6, 96, 101},
	{Ais5, 96, 101},
	{G5, 96, 101},
	{REST, 960, 101},
	{G5, 192, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{C6, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{F5, 96, 95},
	{D5, 96, 95},
	{F5, 96, 95},
	{D5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{C6, 96, 95},
	{G5, 96, 95},
	{Cis6, 96, 95},
	{G5, 96, 95},
	{C6, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{D5, 96, 95},
	{D5, 96, 95},
	{G5, 96, 95},
	{D5, 96, 95},
	{F5, 96, 95},
	{D5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{C6, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{F5, 96, 95},
	{D5, 96, 95},
	{F5, 96, 95},
	{D5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{C6, 96, 95},
	{G5, 96, 95},
	{Cis6, 96, 95},
	{G5, 96, 95},
	{C6, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{Ais5, 96, 95},
	{G5, 96, 95},
	{G5, 96, 95},
	{D5, 96, 95},
	{D5, 96, 95},
	{G5, 96, 95},
	{D5, 96, 95},
	{F5, 96, 95},
	{D5, 96, 95},
	{0, 0}
};

const Song Channel1[] = {
	{E6, 96, 101},
	{F6, 96, 101},
	{E6, 96, 101},
	{D6, 96, 101},
	{E6, 96, 101},
	{D6, 96, 101},
	{Cis6, 96, 101},
	{D6, 96, 101},
	{E6, 96, 101},
	{D6, 96, 101},
	{Cis6, 96, 101},
	{D6, 96, 101},
	{E6, 96, 101},
	{F6, 96, 101},
	{E6, 96, 101},
	{D6, 96, 101},
	{E6, 96, 101},
	{D6, 96, 101},
	{Cis6, 96, 101},
	{D6, 96, 101},
	{E6, 96, 101},
	{D6, 96, 101},
	{Cis6, 96, 101},
	{D6, 96, 101},
	{E6, 96, 101},
	{F6, 96, 101},
	{E6, 96, 101},
	{D6, 96, 101},
	{E6, 96, 101},
	{D6, 96, 101},
	{Cis6, 96, 101},
	{D6, 96, 101},
	{E6, 96, 101},
	{D6, 96, 101},
	{Cis6, 96, 101},
	{D6, 96, 101},
	{G6, 96, 101},
	{F6, 96, 101},
	{D6, 96, 101},
	{C6, 96, 101},
	{Ais5, 96, 101},
	{G5, 96, 101},
	{Ais5, 96, 101},
	{C6, 96, 101},
	{Cis6, 96, 101},
	{C6, 96, 101},
	{Ais5, 96, 101},
	{G5, 96, 101},
	{F5, 96, 101},
	{D5, 96, 101},
	{Ais5, 96, 101},
	{G5, 96, 101},
	{F5, 96, 101},
	{D5, 96, 101},
	{C5, 96, 101},
	{Ais4, 96, 101},
	{D5, 96, 101},
	{C5, 96, 101},
	{Ais4, 96, 101},
	{G4, 96, 101},
	{REST, 960, 101},
	{G4, 192, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{C5, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{F4, 96, 95},
	{D4, 96, 95},
	{F4, 96, 95},
	{D4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{C5, 96, 95},
	{G4, 96, 95},
	{Cis5, 96, 95},
	{G4, 96, 95},
	{C5, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{D4, 96, 95},
	{D4, 96, 95},
	{G4, 96, 95},
	{D4, 96, 95},
	{F4, 96, 95},
	{D4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{C5, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{F4, 96, 95},
	{D4, 96, 95},
	{F4, 96, 95},
	{D4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{C5, 96, 95},
	{G4, 96, 95},
	{Cis5, 96, 95},
	{G4, 96, 95},
	{C5, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{Ais4, 96, 95},
	{G4, 96, 95},
	{G4, 96, 95},
	{D4, 96, 95},
	{D4, 96, 95},
	{G4, 96, 95},
	{D4, 96, 95},
	{F4, 96, 95},
	{D4, 96, 95},
	{0, 0}
};

const Song Channel2[] = {
	{REST, 3456, 90},
	{G2, 576, 90},
	{E2, 576, 90},
	{F2, 576, 90},
	{D2, 576, 90},
	{REST, 1152, 90},
	{G2, 1152, 90},
	{Ais2, 192, 90},
	{C3, 192, 90},
	{G2, 1152, 90},
	{F2, 192, 90},
	{D2, 192, 90},
	{G2, 1152, 90},
	{Ais2, 192, 90},
	{C3, 192, 90},
	{Cis3, 192, 90},
	{C3, 192, 90},
	{Ais2, 192, 90},
	{E2, 96, 90},
	{F2, 192, 90},
	{C2, 96, 90},
	{D2, 192, 90},
	{G2, 96, 90},
	{F2, 96, 90},
	{D2, 192, 90},
	{G2, 1152, 90},
	{Ais2, 192, 90},
	{C3, 192, 90},
	{G2, 1152, 90},
	{F2, 192, 90},
	{D2, 192, 90},
	{G2, 1152, 90},
	{Ais2, 192, 90},
	{C3, 192, 90},
	{Cis3, 192, 90},
	{C2, 192, 90},
	{Ais2, 192, 90},
	{E2, 96, 90},
	{F2, 192, 90},
	{C2, 96, 90},
	{D2, 192, 90},
	{G2, 96, 90},
	{F2, 96, 90},
	{D2, 192, 90},
	{0, 0}
};


const Song Channel3[] = {
	{D3, 96, 90},
	{D3, 96, 90},
	{C3, 96, 90},
	{C3, 96, 90},
	{D3, 96, 90},
	{D3, 96, 90},
	{D3, 96, 90},
	{D3, 96, 90},
	{D3, 192, 90},
	{C3, 96, 90},
	{C3, 96, 90},
	{D3, 192, 90},
	{C3, 96, 90},
	{C3, 96, 90},
	{D3, 96, 90},
	{D3, 96, 90},
	{D3, 96, 90},
	{D3, 96, 90},
	{D3, 192, 90},
	{C3, 96, 90},
	{C3, 96, 90},
	{D3, 192, 90},
	{C3, 96, 90},
	{C3, 96, 90},
	{D3, 96, 90},
	{D3, 96, 90},
	{D3, 96, 90},
	{D3, 96, 90},
	{D3, 192, 90},
	{C3, 96, 90},
	{C3, 96, 90},
	{D3, 192, 90},
	{C3, 96, 90},
	{C3, 96, 90},
	{D3, 192, 90},
	{C3, 192, 90},
	{D4, 96, 90},
	{D4, 96, 90},
	{D4, 96, 90},
	{D4, 96, 90},
	{C4, 96, 90},
	{C4, 96, 90},
	{C4, 96, 90},
	{C4, 96, 90},
	{B3, 96, 90},
	{B3, 96, 90},
	{B3, 96, 90},
	{B3, 96, 90},
	{D3, 96, 90},
	{D3, 96, 90},
	{D3, 96, 90},
	{C3, 96, 90},
	{REST, 1152, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{Gis3, 384, 90},
	{0, 0}
};

