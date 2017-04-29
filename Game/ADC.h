/* ADC.h
 * Provide functions that initialize and read from ADC0.
 * Trey Boehm (tfb356) and Emily Steck (els2676), 2017-04-23
 * Hardware connections: PE2 is AIN1
 */

#include <stdint.h>

// The coordinates for the cursor at a given position
#define CURSOR_X_POS 20
#define CURSOR_Y_1_POS 10
#define CURSOR_Y_2_POS 43
#define CURSOR_Y_3_POS 76

/* ADC_Init(): Initialize AIN1 for ADC0 on PE2
 * Input: none
 * Output: none
 */
void ADC_Init(void);

/* ADC_In(): Busy-wait analog to digital conversion
 * Input: none
 * Output: 12-bit result of ADC conversion
 */
uint32_t ADC_In(void);

/* Read_Cursor_Level(): Get the level at which the user wants the cursor
 * Input: none
 * Output: Either 1, 2, or 3 (highest, middle, or lowest level)
 */
uint8_t Read_Cursor_Level(void);
