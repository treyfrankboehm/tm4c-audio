/* Screens.c
 * Writes various screens
 * Trey Boehm and Emily Steck, 2017-05-03
 * Hardware connections: None
 */
 
#include <stdint.h>
#include "ST7735.h"
#include "ADC.h"
#include "Draw_Sprite.h"
#include "Song.h"
#include "timers.h"

extern uint32_t Score;
extern uint8_t Last_Cursor_Level;

void Selection_Screen(void){
		ST7735_FillScreen(0x0000);
		Type_String(45, 40, "start game!!!");
		Wait_1ms(500);
		Type_String(25, 35, "press any button");
		while(Last_Cursor_Level == 1)	{ ; };	//replace with a button press	
}

void Main_Screen(void)	{	
	Draw_Top_Line();
    Draw_Bottom_Line();
    Draw_Score();
	Draw_Health(120, 53);
    Type_String(100, 7, "yyz.wav");
	Song_Play();
}

void Success_Screen(void){
		ST7735_FillScreen(0x0000);
		Type_String(75, 40, "congrats.exe");
		Wait_1ms(1500);
		Type_String(65, 40, "final score");
		Wait_1ms(1500);
		Draw_Score();	//if we have time -> transition to high score page
		Wait_1ms(1000);
		Type_String(25, 20, "press any button to play again");
		while(Last_Cursor_Level == 1)	{ ; };	//replace with a button press
}

void Fail_Screen(void){
		ST7735_FillScreen(0x0000);
		Type_String(75, 40, "404 error");
		Wait_1ms(1500);
		Type_String(55, 30, "skill not found");
		Wait_1ms(1500);
		Type_String(35, 40, "press any button to try again");
		while(Last_Cursor_Level == 1)	{ ; };	//replace with a button press
}

void HighScore_Screen(void){
		ST7735_FillScreen(0x0000);
		Type_String(90, 30, "1.");
		Type_String(75, 30, "2.");
		Type_String(60, 30, "3.");
		Type_String(45, 30, "4.");
		Type_String(30, 30, "5.");
}
