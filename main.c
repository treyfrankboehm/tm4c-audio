#include <stdint.h>
#include "ST7735.h"
#include "PLL.h"
#include "SysTickInts.h"
#include "tm4c123gh6pm.h"
//#include "Game_Background_4.h"

int main(void) {
    uint8_t i;
    
    PLL_Init();
    ST7735_InitR(INITR_REDTAB);
    
    SYSCTL_RCGC2_R |= 0x20;
    for (i = 0; i < 4; i++) { ; }
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTF_CR_R  |= 0x02;
    GPIO_PORTF_PUR_R |= 0x02;
    GPIO_PORTF_DEN_R |= 0x02;
    GPIO_PORTF_DIR_R |= 0x02;
    
    SysTick_Init(80000000/60);
    
    while (1) { ; }
    
    ST7735_FillScreen(0x0);
    //extern const unsigned short Game_Background_4[];
    //ST7735_DrawBitmap(0, 160, Game_Background_4, 128, 160);
    return 0;
}
