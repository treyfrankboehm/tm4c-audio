/* Buttons.c
 * Read input from the three buttons on the protoboard
 * Trey Boehm and Emily Steck, 2017-05-03
 * PD0, PD1, and PD2 are positive-logic switches
 */

#include <stdint.h>

void Buttons_Init(void);

uint8_t Buttons_In(void);
