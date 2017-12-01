/* leds.c
 * Fun with syncing LEDs to tracks
 */

#include <stdio.h>
#include "tm4c123gh6pm.h"

extern uint32_t MIDI_Time;
extern uint32_t Durations[4];

void LEDs_Enable(int red, int green, int blue)
{
    int i;
    int leds = (red<<1) + (green<<3) + (blue<<2);
    SYSCTL_RCGC2_R |= 0x20;
    for (i = 0; i < 4; i++) { ; }
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTF_DIR_R |= leds;
    GPIO_PORTF_DEN_R |= leds;
    return;
}

int Color_to_int(char color)
{
    int led_bit;
    if (color == 'r') {
        led_bit = 2;
    } else if (color == 'g') {
        led_bit = 8;
    } else if (color == 'b') {
        led_bit = 4;
    } else {
        led_bit = 0;
    }
    return led_bit;
}
 
void LED_Toggle(char color)
{
    int led_bit = Color_to_int(color);
    GPIO_PORTF_DATA_R ^= led_bit;
    return;
}

void LED_On(char color)
{
    int led_bit = Color_to_int(color);
    GPIO_PORTF_DATA_R |= led_bit;
    return;
}

void LED_Off(char color)
{
    int led_bit = Color_to_int(color);
    GPIO_PORTF_DATA_R &= ~led_bit;
    return;
}

void LED_Dance(void)
{
    if (MIDI_Time % Durations[0] == 0) {
        LED_Toggle('r');
    }
    if (MIDI_Time % Durations[1] == 0) {
        LED_Toggle('g');
    }
    if (MIDI_Time % Durations[2] == 0) {
        LED_Toggle('b');
    }
}

