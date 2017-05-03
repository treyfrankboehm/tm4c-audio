/* globals.c
 * Define global variables to easily be included in other files.
 * Trey Boehm (tfb356) and Emily Steck (els2676), 2017-04-23
 * Hardware connections: None.
 */

#include <stdint.h>

// Track where the cursor is
uint8_t Last_Cursor_Level = 1;

// Track where the blinky green block after the song title is
uint16_t Block_X_Pos = 255;
uint16_t Block_Y_Pos = 255;
// Indicates whether the block was last "on" or "off" (1 or 0)
uint8_t  Block_Status = 0;

uint32_t Score = 12345;

uint16_t Health = 42;
