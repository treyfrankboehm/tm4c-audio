/* Song.c
 * Helper functions to calculate scores, multipliers, and current status
 * Trey Boehm and Emily Steck, 2017-04-23
 * Hardware connections: Refer to ST7735_InitR() (Port A, mainly)
 */

#include <stdint.h>
#include "ST7735.h"
#include "Draw_Sprite.h"
#include "Song.h"
#include "Calculate.h"
#include "Screens.h"
#include "ADC.h"
#include "timers.h"

extern uint8_t Last_Cursor_Level;
extern uint32_t Score;

void Song_Play(void){
		struct Song
		{
				int arrow_num;
				int cursor_level;
				int time;
		};
		int song_arrow[40] = {0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3};
		int song_cursorlevel[40] ={15,45,75,15,45,75,15,45,75,15,45,75,15,45,75,15,45,75,15,45,75,15,45,75,15,45,75,15,45,75,15,45,75,15,45,75,15,45,75,15}; 
		//song_time[40] = 

		struct Song song[40];
		int i;
		int j;
		int y_pos = 168;
		
		for( i = 0; i < 40; i++ )	{
				y_pos = 168;
				int one = 1;
				int two = 1;
				int three = 1;
				int four = 1;
				for( j = 0; j < 440; j++){
						if(one)
								Draw_Arrow(song_cursorlevel[i], y_pos, song_arrow[i]);
						if(two)
								Draw_Arrow(song_cursorlevel[i+1], y_pos+88, song_arrow[i+1]);
						if(three)
								Draw_Arrow(song_cursorlevel[i+2], y_pos+176, song_arrow[i+2]);
						if(four)
								Draw_Arrow(song_cursorlevel[i+3], y_pos+264, song_arrow[i+3]);
						y_pos = (y_pos-1);
						int cursor_level = Last_Cursor_Level;
						if(cursor_level == 1){
								cursor_level = 15;
						}
						if(cursor_level == 2){
								cursor_level = 45;
						}
						if(cursor_level == 3){
								cursor_level = 75;
						}
						if(y_pos == 20)	{
								if(cursor_level == song_cursorlevel[i])	{
										Calculate_Score(100);
										one = 0;
										Calculate_Health(1);
								}	
								else	{
								Calculate_Health(-1);
								}
						}
						else if(y_pos == -68)	{
								if(cursor_level == song_cursorlevel[i+1])	{
										Calculate_Score(100);
										two = 0;
										Calculate_Health(1);
								}
								else	{
								Calculate_Health(-1);
								}
						}
						else if(y_pos == -156)	{
								if(cursor_level == song_cursorlevel[i+2])	{
										Calculate_Score(100);
										three = 0;
										Calculate_Health(1);
								}
								else	{
								Calculate_Health(-1);
								}
						}
						else if(y_pos == -244)	{
								if(cursor_level == song_cursorlevel[i+3])	{
										Calculate_Score(100);
										four = 0;
										Calculate_Health(1);
								}
								else	{
								Calculate_Health(-1);
								}
						}
						Wait_1ms(10);
				}
		}
		Success_Screen();
}