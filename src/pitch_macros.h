/* pitch_macros.h
 * This header file contains macros defining wait times for pitches
 * Trey Boehm, 2017-04-24
 * Hardware connections: None
 */

/* The periods and frequencies copied/pasted from Valvano's spreadsheet.
 * Period = 80,000,000/64/Freq = 1,250,000/Freq
 * Each macro includes the pitch, a possible modifier, and the standard
 * octave designation. "is" indicates "sharp" and "es" indicates "flat".
 */
//const int REST = 44444; // Musical silence is an exception
#ifndef PITCH_MACROS_H
#define PITCH_MACROS_H 1
#define REST 44444

#define C8      299    // 4186 Hz
#define B7      316    // 3951.1 Hz
#define Bes7    335    // 3729.3 Hz
#define Ais7    335    // 3729.3 Hz
#define A7      355    // 3520 Hz
#define Aes7    376    // 3322.4 Hz
#define Gis7    376    // 3322.4 Hz
#define G7      399    // 3136 Hz
#define Ges7    422    // 2960 Hz
#define Fis7    422    // 2960 Hz
#define F7      447    // 2793.8 Hz
#define E7      474    // 2637 Hz
#define Ees7    502    // 2489 Hz
#define Dis7    502    // 2489 Hz
#define D7      532    // 2349.3 Hz
#define Des7    564    // 2217.5 Hz
#define Cis7    564    // 2217.5 Hz
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
#define B2      10124
#define Ais2    10726
#define A2      11364
#define Gis2    12039
#define G2      12755
#define Fis2    13514
#define F2      14317
#define E2      15169
#define Dis2    16071
#define D2      17026
#define Cis2    18039
#define C2      19111
#define B1      20248
#define Ais1    21452
#define A1      22727
#define Gis1    24079
#define G1      25511
#define Fis1    27027
#define F1      28635
#define E1      30337
#define Dis1    32141
#define D1      34052
#define Cis1    36077
#define C1      38223

// Percussion macros (MIDI just uses pitches for different instruments)
#define SNARE D3
#define BASS_DRUM C3
#define HI_HAT_PEDAL Gis3
#define TOM_HIGH D4
#define TOM_MID_HIGH C4
#define TOM_MID_LOW B3


#endif

