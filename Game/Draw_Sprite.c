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
#include "Sprites\alphanumeric.h"
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

void Draw_Letter(int x, int y, char letter) {
    if (letter-0x30 < 10) { // We've got a number
        ST7735_DrawBitmap(x, y, Alphanumerics[letter-'0'], 9, 7);
    } else { // We've got a letter (for now -- TODO: add hyphen and period)
        ST7735_DrawBitmap(x, y, Alphanumerics[letter-'a'+10], 11, 7);
    }
}
