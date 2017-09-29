# tm4c-audio: Making cool sounds and music on a TM4C microcontroller

## About
This repo is based on code that I wrote starting with lab 6 ("Piano DAC") in EE 319K during spring 2017. I continued to develop this code substantially during the following weeks.

## Hardware and Dependencies
I'm currently developing this project on Debian 9.1, so the dependencies reflect that.
- [Texas Instruments TM4C123GH6PM Microcontroller](http://www.ti.com/product/tm4c123gh6pm)
- [Tiva C Series Launchpad Evaluation Board Software](http://www.ti.com/tool/sw-ek-tm4c123gxl)
- [lm4flash](https://github.com/utzig/lm4tools) (available in Debian main repo, too)
- The circuit (see included schematics)

## How it works
First I use [Lilypond](http://lilypond.org/) to transcribe a song and create a MIDI file. I have not tested MIDIs generated with DAWs or other programs. Then I run that through a Python script I wrote. It uses the [midicsv](https://www.fourmilab.ch/webtools/midicsv/) tool to get the MIDI into a parseable format and then grabs the fields that I'm interested in. Finally it formats this in a C struct that can be used by the rest of the code. Currently the program supports 4 different events at any given time, so it works well for things like lead, guitar, bass, and percussion. The bulk of the program happens in `dac.c` and the `SysTick_Handler()` function in `timers.c`. There's a constantly running global timer that lets us run through the song and then a timer for each instrument that goes through the waveforms. The global timer (SysTick) also deals with the volume envelopes. Percussion instruments are handled in a different file that uses random number generation. All computations must be extremely fast because the processor only runs at 80 MHz. C8, for example, takes only about 300 clock cycles before it moves to the next sample!

## What comes next?
I plan to do a few things with hardware before making a bunch of big software changes. Of course, each of those will probably require another branch. The order of things is:
0. Some basic housekeeping to clean up the codebase. Also figure out how to cross-compile for ARM on Linux and see if there's a JTAG programmer that will work.
1. Get the original code working with the 6-bit DAC it was designed for.
2. Upgrade the DAC to 8-bits.
3. Make another branch that uses the [TLV 5616](http://www.ti.com/product/TLV5616), a 12-bit DAC IC made by Texas Instruments that [Valvano](http://users.ece.utexas.edu/~valvano/) gave me.
4. Add a way to better handle multiple songs. Perhaps even implement a way to select and play different songs using some buttons and an LCD.

## Bugs
- `cat *.c *.h | grep -Ei 'todo|fixme'`

