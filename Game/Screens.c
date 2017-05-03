/* Screens.c
 * Helper functions to calculate scores, multipliers, and current status
 * Trey Boehm and Emily Steck, 2017-04-23
 * Hardware connections: Refer to ST7735_InitR() (Port A, mainly)
 */
 
#include <stdint.h>
#include "ST7735.h"
#include "ADC.h"
#include "Draw_Sprite.h"
#include "timers.h"

extern uint32_t Score;

void Selection_Screen(void){
		Type_String(45, 40, "start game!!!");
		Wait_1ms(7000);
}

void Success_Screen(void){
		ST7735_FillScreen(0x0000);
		Type_String(75, 40, "congrats.exe");
		Wait_1ms(1500);
		Type_String(65, 40, "final score");
		Wait_1ms(1500);
		Draw_Score();
}
