/* Song.c
 * Helper functions to calculate scores, multipliers, and current status
 * Trey Boehm and Emily Steck, 2017-04-23
 * Hardware connections: Refer to ST7735_InitR() (Port A, mainly)
 */

#include <stdint.h>
#include "ST7735.h"
#include "ADC.h"
#include "timers.h"

void Song_Play(void){
		struct Song
		{
				int arrow_num;
				int cursor_level;
				int time;
		};
		song_arrow[40] = 
		song_cursorlevel[40] = 
		song_time[40] = 

		struct Song song[40];
		int i;
		for( i = 0; i < 40; i++ )	{
				song[i]
				Draw_Arrow(cursor_level, y_pos, arrow_num);
		}
}
