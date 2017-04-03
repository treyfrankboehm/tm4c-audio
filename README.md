# 4-channel-audio

## This is a fork of our 319K lab 6 repo. The goal is to provide the ability to convert 4-channel MIDIs to a header file with structs that is parseable by the program to play with a six bit DAC.

## To-do:
* Each channel specifies a waveform (patch) to use
* Each MIDI event (note) specifies the relative volume 
* Find the source of pulsing/thumping/clicking sound
* Add more note macros to allow lower pitches
* Fine-tune the TUNING_OFFSET macro value in dac.c
* Get rid of raspy/clashing sounds that come with multi-channel
