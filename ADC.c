/* ADC.c
 * Provide functions that initialize and read from ADC0.
 * Trey Boehm (tfb356) and Emily Steck (els2676), 2017-04-23
 * Hardware connections: PE2 is AIN1
 */
 
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ADC.h"

// These are the ADC_In() cutoffs for which level the cursor is at
#define CURSOR_LEVEL_1 1365
#define CURSOR_LEVEL_2 2731

/* ADC_Init(): Initialize AIN1 for ADC0 on PE2
 * Input: none
 * Output: none
 */
void ADC_Init(void){ 
    int i;
    
	SYSCTL_RCGCGPIO_R |= 0x010; // Start the clock on port E
	while((SYSCTL_RCGCGPIO_R&0x010) == 0) { ; } // Stabilize
	GPIO_PORTE_DIR_R &= ~0x02; 
	GPIO_PORTE_AFSEL_R |= 0x02;
	GPIO_PORTE_DEN_R &= ~0x02;
	GPIO_PORTE_AMSEL_R |= 0x02;
	SYSCTL_RCGCADC_R |= 0x01;
    
    for (i = 0; i < 4; i++) { ; } // Stabilize
	
	ADC0_PC_R = 0x01;
	ADC0_SSPRI_R = 0x0123;
	ADC0_ACTSS_R &= ~0x0008;
	ADC0_EMUX_R &= ~0xF000;
	ADC0_SSMUX3_R = (ADC0_SSMUX3_R&0xFFFFFFF0)+1; //Ain1=Pe2
	ADC0_SSCTL3_R = 0x0006;
    // from Schuyler on Piazza: enable over-sampling by averaging 16 samples
    ADC0_SAC_R = 0x04;
	ADC0_IM_R &= ~0x0008;
	ADC0_ACTSS_R |= 0x0008;
}

/* ADC_In(): Busy-wait analog to digital conversion
 * Input: none
 * Output: 12-bit result of ADC conversion
 */
uint32_t ADC_In(void) {
    uint32_t data;
    ADC0_PSSI_R = 0x0008;
    while((ADC0_RIS_R&0x08)==0) { ; }
    data = ADC0_SSFIFO3_R&0xFFF;
    ADC0_ISC_R = 0x0008;
    return data;
}

uint8_t Read_Cursor_Level(void) {
    uint32_t level = ADC_In();
    if (level < CURSOR_LEVEL_1) {
        return 1;
    } else if (level > CURSOR_LEVEL_2) {
        return 3;
    } else {
        return 2; // Must be between (1) and (3)
    }
}
