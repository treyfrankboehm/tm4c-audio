/* custom_types.h
 * typedefs for song and tempo structs
 */

#include <stdint.h>

#ifndef CUSTOM_TYPES_H
#define CUSTOM_TYPES_H
typedef struct song_t {
    uint16_t pitch;
    uint16_t duration;
    uint8_t volume;
} Song;


typedef struct tempo_times_t{
    uint32_t time;
    uint32_t tempo;
} Tempo_Times;
#endif

