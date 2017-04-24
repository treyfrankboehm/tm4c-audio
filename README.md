# 4-channel-audio

## Goal: Feed MIDIs with up to 4 channels into the script `midistruct.py`. These header files with structs can be included as songs and played by the 6-bit DAC.

## To-do:
* Improve volume envelopes to make more realistic instruments (try to implement one cymbal and one drum before merging with master).
* Allow multiple tempos per song.
* Each MIDI event (note) specifies its relative volume.
* Generate a noise signal to use with percussive sounds.
* Make a way to handle multiple songs (instead of Channel0, Channel1... have each `.h` file name `filename-Channel0` or whatever the case may be. Then have pointers to those that can be reassigned instead of referring directly to them. Not this branch).
* `cat * | grep -i 'todo'`

## Specific issues in `percussion` breanch
* To get actual noise, the reload value for the ISR must also be random. Possible fix: dedicated percussion channel[s].
* Maybe write such that percussion instruments have a set length at which they are allowed to sustain before decaying.
* No idea what the frequency-time plot of drums, cymbals, etc actually look like.

