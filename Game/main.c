#include <stdint.h>
#include "ST7735.h"
#include "PLL.h"
#include "SysTickInts.h"
#include "tm4c123gh6pm.h"
#include "Draw_Sprite.h"
#include "Calculate.h"
#include "Song.h"
#include "timers.h"

void EnableInterrupts(void);
void ADC_Init(void);

int main(void) {
    uint8_t i;
    
    PLL_Init();
    ST7735_InitR(INITR_REDTAB);
    ST7735_FillScreen(0x0000); // Black background
    
    ADC_Init();
    
    SYSCTL_RCGCGPIO_R |= 0x20;
    for (i = 0; i < 4; i++) { ; }
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTF_CR_R  |= 0x02;
    GPIO_PORTF_PUR_R |= 0x02;
    GPIO_PORTF_DEN_R |= 0x02;
    GPIO_PORTF_DIR_R |= 0x02;
    
    SysTick_Init(80000000/30);
    Timer0A_Init(BLINK_PERIOD);
    Timer1A_Init(ONE_MILLISECOND);
    EnableInterrupts();
    
    Draw_Top_Line();
    Draw_Bottom_Line();
    Draw_Score();
		Draw_Health(120, 53);
    Type_String(100, 7, "yyz.wav");
    
    while (1 != 0) { ; }
    
    //extern const unsigned short Game_Background_4[];
    //ST7735_DrawBitmap(0, 160, Game_Background_4, 128, 160);
    
    return 0;
}
