/* Screens.h
 * Helper functions to calculate scores, multipliers, and current status
 * Trey Boehm and Emily Steck, 2017-04-23
 * Hardware connections: Refer to ST7735_InitR() (Port A, mainly)
 */

#include <stdint.h>

void Selection_Screen(void);

void Main_Screen(void);

void Success_Screen(void);

void Fail_Screen(void);

void HighScore_Screen(void);
