/* Draw_Sprite.h
 * Helper functions to draw sprites on the LCD
 * Trey Boehm and Emily Steck, 2017-04-23
 * Hardware connections: Refer to ST7735_InitR() (Port A, mainly)
 */

#include <stdint.h>

void Draw_Arrow(int x, int y, int arrow_num);

void Draw_Letter(int x, int y, char letter);

void Type_String(int x, int y, char *str);

void Blink_Block(void);

void Draw_Cursor(void);

void Draw_Top_Line(void);

void Draw_Bottom_Line(void);

void Draw_Score(void);

void Draw_Health(int x, int y);
