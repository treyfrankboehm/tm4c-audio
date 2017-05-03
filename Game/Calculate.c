/* Calculate.c
 * Helper functions to calculate scores, multipliers, and current status
 * Trey Boehm and Emily Steck, 2017-04-23
 * Hardware connections: Refer to ST7735_InitR() (Port A, mainly)
 */

#include <stdint.h>
#include "ST7735.h"
#include "Draw_Sprite.h"
#include "Screens.h"
#include "ADC.h"
#include "timers.h"

extern uint16_t Health;
extern uint32_t Score;

void Calculate_Health(int x){
		if(x == 1){
				if(Health<50){
						Health += x;
						Draw_Health(120,53);
				}
		}
		else if(x == -1){
				if(Health>0){
						Health += x;
						Draw_Health(120,53);
				}
				else 
						Fail_Screen();
		}
}

void Calculate_Score(int x){
		Score += x;
		Draw_Score();
}
