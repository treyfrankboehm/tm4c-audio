/* Calculate.c
 * Helper functions to calculate scores, multipliers, and current status
 * Trey Boehm and Emily Steck, 2017-04-23
 * Hardware connections: Refer to ST7735_InitR() (Port A, mainly)
 */

#include <stdint.h>
#include "ST7735.h"
#include "ADC.h"
#include "timers.h"

void Calculate_Health(int x){
		if(x>0){
				if(Health<50){
						Health = Health + x;
				}
		}
		else
				if(Health>0){
					Health = Health + x;
				}
				//else 
					//Fail Screen
}