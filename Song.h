/* %.h: .midi -> .csv -> homemade C struct
 * Copyright (c) 2017 Trey Boehm
 * Include this file in Sound.c to make the note macros useful.
 */
 
#include <stdint.h>
#include "SoundMacros.h"

#ifndef __SONG_H__
#define __SONG_H__

struct song_struct {
    uint32_t pitch;
    uint32_t duration;
};
typedef struct song_struct song_t;

const song_t channel0[] = {
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 192},
	{D6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{G6, 192},
	{A6, 384},
	{Fis6, 384},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 192},
	{D6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{G6, 192},
	{A6, 384},
	{B6, 384},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 192},
	{D6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{G6, 192},
	{A6, 384},
	{Fis6, 384},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 384},
	{D6, 192},
	{E6, 384},
	{G6, 384},
	{A6, 384},
	{REST, 192},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 192},
	{D6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{G6, 192},
	{A6, 384},
	{Fis6, 384},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 192},
	{D6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{G6, 192},
	{A6, 384},
	{B6, 384},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 192},
	{D6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{G6, 192},
	{A6, 384},
	{Fis6, 384},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 192},
	{D6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{G6, 192},
	{A6, 384},
	{B6, 384},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 192},
	{D6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{G6, 192},
	{A6, 384},
	{Fis6, 384},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 192},
	{D6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{G6, 192},
	{A6, 384},
	{B6, 384},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 192},
	{D6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{G6, 192},
	{A6, 384},
	{Fis6, 384},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 192},
	{D6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{G6, 192},
	{A6, 384},
	{B6, 384},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 192},
	{D6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{G6, 192},
	{A6, 384},
	{Fis6, 384},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 192},
	{D6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{G6, 192},
	{A6, 384},
	{B6, 384},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 192},
	{D6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{G6, 192},
	{A6, 384},
	{Fis6, 384},
	{G6, 192},
	{REST, 192},
	{E6, 192},
	{REST, 192},
	{Fis6, 384},
	{D6, 192},
	{E6, 384},
	{G6, 384},
	{A6, 384},
	{0, 0}
};

const song_t channel1[] = {
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 192},
	{REST, 192},
	{A5, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 192},
	{REST, 192},
	{D6, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 192},
	{REST, 192},
	{A5, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 384},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 192},
	{REST, 192},
	{A5, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 192},
	{REST, 192},
	{D6, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 192},
	{REST, 192},
	{A5, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 192},
	{REST, 192},
	{D6, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 192},
	{REST, 192},
	{A5, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 192},
	{REST, 192},
	{D6, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 192},
	{REST, 192},
	{A5, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 192},
	{REST, 192},
	{D6, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 192},
	{REST, 192},
	{A5, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 192},
	{REST, 192},
	{D6, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 192},
	{REST, 192},
	{A5, 192},
	{B5, 192},
	{REST, 192},
	{G5, 192},
	{REST, 192},
	{A5, 192},
	{REST, 192},
	{Fis5, 192},
	{G5, 192},
	{REST, 192},
	{B5, 192},
	{REST, 192},
	{Cis6, 384},
	{0, 0}
};

const song_t channel2[] = {
	{E5, 768},
	{D5, 576},
	{E5, 384},
	{D5, 384},
	{B4, 384},
	{D5, 192},
	{E5, 768},
	{Fis5, 384},
	{G5, 192},
	{A5, 192},
	{REST, 1152},
	{E5, 768},
	{D5, 576},
	{E5, 384},
	{D5, 384},
	{B4, 384},
	{D5, 192},
	{E5, 768},
	{Fis5, 384},
	{D5, 192},
	{E5, 192},
	{REST, 1152},
	{E5, 768},
	{D5, 576},
	{E5, 384},
	{D5, 384},
	{B4, 384},
	{D5, 192},
	{E5, 768},
	{Fis5, 384},
	{G5, 192},
	{A5, 192},
	{REST, 576},
	{B4, 192},
	{D5, 192},
	{G5, 192},
	{E5, 768},
	{D5, 576},
	{E5, 384},
	{D5, 384},
	{B4, 384},
	{D5, 192},
	{E5, 768},
	{Fis5, 384},
	{D5, 192},
	{E5, 192},
	{REST, 1152},
	{E5, 768},
	{D5, 576},
	{E5, 384},
	{D5, 384},
	{B4, 384},
	{D5, 192},
	{E5, 768},
	{Fis5, 384},
	{G5, 192},
	{A5, 192},
	{REST, 576},
	{D5, 192},
	{F5, 192},
	{G5, 192},
	{E5, 0},
	{REST, 768},
	{E5, 0},
	{D5, 0},
	{REST, 576},
	{D5, 0},
	{E5, 0},
	{REST, 384},
	{E5, 0},
	{D5, 0},
	{REST, 384},
	{D5, 0},
	{B4, 0},
	{REST, 384},
	{B4, 0},
	{D5, 0},
	{REST, 192},
	{D5, 0},
	{G5, 0},
	{REST, 768},
	{G5, 0},
	{Fis5, 0},
	{REST, 384},
	{Fis5, 0},
	{D5, 0},
	{REST, 192},
	{D5, 0},
	{E5, 0},
	{REST, 192},
	{E5, 0},
	{REST, 576},
	{B4, 192},
	{D5, 192},
	{G5, 192},
	{0, 0}
};

const song_t channel3[] = {
	{B5, 1152},
	{Fis5, 192},
	{A5, 384},
	{G5, 384},
	{Fis5, 192},
	{G5, 768},
	{Fis5, 384},
	{D5, 192},
	{D5, 192},
	{REST, 1536},
	{B5, 960},
	{A5, 192},
	{G5, 384},
	{Fis5, 192},
	{G5, 384},
	{Fis5, 192},
	{E5, 576},
	{Fis5, 384},
	{G5, 384},
	{A5, 192},
	{REST, 6912},
	{B5, 1152},
	{A5, 192},
	{G5, 192},
	{Fis5, 192},
	{G5, 384},
	{Fis5, 192},
	{E5, 576},
	{Fis5, 384},
	{G5, 384},
	{A5, 192},
	{REST, 1536},
	{B5, 576},
	{A5, 384},
	{G5, 384},
	{B5, 384},
	{G5, 384},
	{Fis5, 192},
	{G5, 192},
	{Fis5, 192},
	{E5, 384},
	{Fis5, 384},
	{D5, 192},
	{D5, 192},
	{0, 0}
};
#endif
