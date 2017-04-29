/* Draw_Sprite.c
 * Helper functions to draw sprites on the LCD
 * Trey Boehm and Emily Steck, 2017-04-23
 * Hardware connections: Refer to ST7735_InitR() (Port A, mainly)
 */

#include <stdint.h>
#include <time.h>
#include "ST7735.h"
#include "Sprites\Up_Arrow.h"
#include "Sprites\Left_Arrow.h"
#include "Sprites\Right_Arrow.h"
#include "Sprites\Down_Arrow.h"
#include "Sprites\alphanumeric.h"
#include "Draw_Sprite.h"
#include "ADC.h"
#include "timers.h"

#define HAKEN_GREEN 0x07E6

extern uint8_t Last_Cursor_Level;
extern uint16_t Block_X_Pos;
extern uint16_t Block_Y_Pos;
extern uint8_t  Block_Status;

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

void Type_String(int x, int y, char *str) {
    int i;
    int offset = 0;
    char letter;
    for (i = 0; str[i]; i++) {
        letter = str[i];
        if (letter != ' ') {
            Draw_Letter(x, y+offset, letter);
						while (time(0) < 1);	//should delay 1 second, needs to be tested
        } else {
            ST7735_FillRect(x, y+offset-7, 11, 8, ST7735_BLACK);
        }
        offset += 8;
    }
    Block_X_Pos = x;
    Block_Y_Pos = y+offset+3;
}

/* Blinks the little cursor block after the song name. Uses global
 * variables.
 */
void Blink_Block(void) {
    if (Block_Status) {
        ST7735_FillRect(Block_X_Pos, Block_Y_Pos-8, 11, 9, HAKEN_GREEN);
        Block_Status = 0;
    } else {
        ST7735_FillRect(Block_X_Pos, Block_Y_Pos-8, 11, 9, ST7735_BLACK);
        Block_Status = 1;
    }
}

/* This function is called every SysTick interrupt. It checks if the ADC
 * has changed positions. If so, it draws over the old one and re-draws
 * the new one. If not, nothing happens. Call this BEFORE calling the
 * function to draw the arrows.
 */
void Draw_Cursor(void) {
    uint8_t cursor_level = Read_Cursor_Level();
    if (cursor_level != Last_Cursor_Level) {
        switch (cursor_level) {
            case 1:
                ST7735_FillRect(CURSOR_Y_2_POS, CURSOR_X_POS-16, 16, 16, ST7735_BLACK);
                ST7735_FillRect(CURSOR_Y_3_POS, CURSOR_X_POS-16, 16, 16, ST7735_BLACK);
                ST7735_DrawBitmap(CURSOR_Y_1_POS, CURSOR_X_POS, Up_Arrow, 16, 16);
                break;
            case 2:
                ST7735_FillRect(CURSOR_Y_1_POS, CURSOR_X_POS-16, 16, 16, ST7735_BLACK);
                ST7735_FillRect(CURSOR_Y_3_POS, CURSOR_X_POS-16, 16, 16, ST7735_BLACK);
                ST7735_DrawBitmap(CURSOR_Y_2_POS, CURSOR_X_POS, Up_Arrow, 16, 16);
                break;
            case 3:
                ST7735_FillRect(CURSOR_Y_1_POS, CURSOR_X_POS-16, 16, 16, ST7735_BLACK);
                ST7735_FillRect(CURSOR_Y_2_POS, CURSOR_X_POS-16, 16, 16, ST7735_BLACK);
                ST7735_DrawBitmap(CURSOR_Y_3_POS, CURSOR_X_POS, Up_Arrow, 16, 16);
                break;
        }
    }
    Last_Cursor_Level = cursor_level;
    // otherwise, nothing happens
}
