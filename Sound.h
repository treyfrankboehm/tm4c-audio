// Sound.h
// This module contains the SysTick ISR that plays sound
// Runs on LM4F120 or TM4C123
// Program written by: Emily Steck and Trey Boehm
// Date Created: 2017-03-06
// Last Modified: 2017-03-21
// Lab number: 6
#include <stdint.h>
// Header files contain the prototypes for public functions
// this file explains what the module does

// Macros for notes. The periods and frequencies copied/pasted from
// Valvano's spreadsheet: Period = 80,000,000/64/Freq = 1,250,000/Freq
// Each macro includes the pitch, a possible modifier, and the standard
// octave designation. "is" indicates "sharp" and "es" indicates "flat"
#define REST    4444   // Musical silence is an exception
#define C7      597    // 2093 Hz
#define B6      633    // 1975.5 Hz
#define Bes6    670    // 1864.7 Hz
#define Ais6    670    // 1864.7 Hz
#define A6      710    // 1760 Hz
#define Aes6    752    // 1661.2 Hz
#define Gis6    752    // 1661.2 Hz
#define G6      797    // 1568 Hz
#define Ges6    845    // 1480 Hz
#define Fis6    845    // 1480 Hz
#define F6      895    // 1396.9 Hz
#define E6      948    // 1318.5 Hz
#define Ees6    1004   // 1244.5 Hz
#define Dis6    1004   // 1244.5 Hz
#define D6      1064   // 1174.7 Hz
#define Des6    1127   // 1108.7 Hz
#define Cis6    1127   // 1108.7 Hz
#define C6      1194   // 1046.5 Hz
#define B5      1265   // 987.8 Hz
#define Bes5    1341   // 932.3 Hz
#define Ais5    1341   // 932.3 Hz
#define A5      1420   // 880 Hz
#define Aes5    1505   // 830.6 Hz
#define Gis5    1505   // 830.6 Hz
#define G5      1594   // 784 Hz
#define Ges5    1689   // 740 Hz
#define Fis5    1689   // 740 Hz
#define F5      1790   // 698.5 Hz
#define E5      1896   // 659.3 Hz
#define Ees5    2009   // 622.3 Hz
#define Dis5    2009   // 622.3 Hz
#define D5      2128   // 587.3 Hz
#define Des5    2255   // 554.4 Hz
#define Cis5    2255   // 554.4 Hz
#define C5      2389   // 523.3 Hz
#define B4      2531   // 493.9 Hz
#define Bes4    2681   // 466.2 Hz
#define Ais4    2681   // 466.2 Hz
#define A4      2841   // 440 Hz
#define Aes4    3010   // 415.3 Hz
#define Gis4    3010   // 415.3 Hz
#define G4      3189   // 392 Hz
#define Ges4    3378   // 370 Hz
#define Fis4    3378   // 370 Hz
#define F4      3579   // 349.2 Hz
#define E4      3792   // 329.6 Hz
#define Ees4    4018   // 311.1 Hz
#define Dis4    4018   // 311.1 Hz
#define D4      4257   // 293.7 Hz
#define Des4    4510   // 277.2 Hz
#define Cis4    4510   // 277.2 Hz
#define C4      4778   // 261.6 Hz
#define B3      5062   // 246.9 Hz
#define Bes3    5363   // 233.1 Hz
#define Ais3    5363   // 233.1 Hz
#define A3      5682   // 220 Hz
#define Aes3    6020   // 207.7 Hz
#define Gis3    6020   // 207.7 Hz
#define G3      6378   // 196 Hz
#define Ges3    6757   // 185 Hz
#define Fis3    6757   // 185 Hz
#define F3      7159   // 174.6 Hz
#define E3      7584   // 164.8 Hz
#define Ees3    8035   // 155.6 Hz
#define Dis3    8035   // 155.6 Hz
#define D3      8513   // 146.8 Hz
#define Des3    9019   // 138.6 Hz
#define Cis3    9019   // 138.6 Hz
#define C3      9556   // 130.8 Hz

// **************Sound_Init*********************
// Initialize Systick periodic interrupts
// Called once, with sound initially off
// Input: interrupt period
//           Units to be determined by YOU
//           Maximum to be determined by YOU
//           Minimum to be determined by YOU
// Output: none
void Sound_Init(uint32_t period);

// **************Sound_Play*********************
// Start sound output, and set Systick interrupt period 
// Input: interrupt period
//           Units to be determined by YOU
//           Maximum to be determined by YOU
//           Minimum to be determined by YOU
//         input of zero disable sound output
// Output: none
void Sound_Play(uint32_t period);

// Initialize buttons to start/stop song
void Sequencer_Init(void);

uint8_t Sequencer_In(void);
