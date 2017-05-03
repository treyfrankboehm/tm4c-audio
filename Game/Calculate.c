/* Calculate.c
 * Helper functions to calculate scores, multipliers, and current status
 * Trey Boehm and Emily Steck, 2017-04-23
 * Hardware connections: Refer to ST7735_InitR() (Port A, mainly)
 */

#include <stdint.h>
#include "ST7735.h"
#include "Draw_Sprite.h"
#include "ADC.h"
#include "timers.h"

extern uint16_t Health;

void Calculate_Health(int x){
		if(x>0){
				if(Health<50){
						Health = Health + x;
						Draw_Health(120,53);
				}
		}
		else{
				if(Health>0){
					Health = Health + x;
					Draw_Health(120,53);
				}
				//else 
					//Fail Screen
		}
}
