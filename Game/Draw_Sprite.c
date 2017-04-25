/* Sprite_Draw.c
 * Helper functions to draw sprites on the LCD
 * Trey Boehm and Emily Steck, 2017-04-23
 * Hardware connections: Refer to ST7735_InitR() (Port A, mainly)
 */

#include <stdint.h>
#include "ST7735.h"
#include "Sprites\Up_Arrow.h"
#include "Sprites\Left_Arrow.h"
#include "Sprites\Right_Arrow.h"
#include "Sprites\Down_Arrow.h"
#include "Draw_Sprite.h"

void Draw_Arrow(int x, int y, int arrow_num) {
    switch (arrow_num) {
        case 0:
            ST7735_DrawBitmap(x, y, Up_Arrow, 16, 16);
            break;
        case 1:
            ST7735_DrawBitmap(x, y, Left_Arrow, 16, 16);
            break;
        case 2:
            ST7735_DrawBitmap(x, y, Right_Arrow, 16, 16);
            break;
        case 3:
            ST7735_DrawBitmap(x, y, Down_Arrow, 16, 16);
            break;
        default:
            break;
    }
}
