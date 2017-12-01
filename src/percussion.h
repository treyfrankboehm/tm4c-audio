/* percussion.h
 * Handle percussion instruments as exceptions to the standard DAC rule
 * Trey Boehm, 2017-04-24
 */

#include <stdint.h>

uint8_t Rand6(void);

uint16_t Percussion_Period(void);
uint8_t Percussion_Handler(void);

