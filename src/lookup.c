/* lookup.c
 * Lookup table functions to multiply unsigned 6-bit integers quickly.
 * Trey Boehm, 2017-04-22
 * Hardware connections: None
 */

#include <stdint.h>
#include "lookup.h"
 
uint16_t Mult6(uint8_t x, uint8_t y) {
    return MultLookup[x][y];
}

