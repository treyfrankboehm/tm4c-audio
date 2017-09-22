/* noise.c
 * Generate pseudo-random numbers for a noise signal
 * Trey Boehm, 2017-04-22
 * Hardware connections: None
 */

#include <stdint.h>

uint32_t Noise_Seed = 0x27d4eb2d;
/*
int Rand6(void) {
    uint32_t a = Noise_Seed;
    a = (a ^ 61) ^ (a >> 16);
    a = a + (a << 3);
    a = a ^ (a >> 4);
    a = a * 0x27d4eb2d;
    a = a ^ (a >> 15);
    Noise_Seed = a;
    a >>= 26;
    return (a&0x3F);
}
*/

int Rand6(void) {
    uint32_t a = Noise_Seed;
    a *= 1664525;
    a += 1013904223;
    Noise_Seed = a;
    a >>= 26;
    a &= 0x3F;
    return a;
}

