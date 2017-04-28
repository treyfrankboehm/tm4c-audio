# Lab 10: A Super-Cool Retro Rhythm Game

The project is split up into two different folders, "Game" and "Audio". This is because we are using two boards and it is easiest to just separate those into different Keil uVision projects. As the names suggest, Game contains everything related to drawing sprites on the LCD, moving things around, handling game logic and inputs, etc. Audio contains everything related to playing the music. This is split up like this because the rate at which the interrupt service routines run must be very predictable and being off by even a few clock cycles leads to nasty, out of tune music.

## To-do:
### Game folder:
* Make the type string function go slower so that each character can be observed entering the screen one-by-one.
* Re-do the 'y' bitmap and add: . , - \_ ! % &
* Create structs and arrays that hold the "song". Each struct will probably contain a direction, cursor level, and time. The "song" array will define the speed at which they approach (one, two, or three pixels probably). The name of the song (to be displayed up top and on the selection screen) and high scores will need to be defined elsewhere and have the array associated with them.
### Audio folder:
* Make a way to handle multiple songs (instead of Channel0, Channel1... have each `.h` file name `filename-Channel0` or whatever the case may be. Then have pointers to those that can be reassigned instead of referring directly to them. Not this branch).
* `cat * | grep -i 'todo'`
