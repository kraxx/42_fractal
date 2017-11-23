# 42_fractal
Fractal generator. Wows and bedazzles. Built as part of 42 Coding University's graphics branch.
## Getting started
From the root directory, run:
```
make
```
To run the program, enter:
```
./fract_ol [fractal name]
```
Current list of fractals:
```
julia
mandelbrot
ship
menace
crevice
fish
time
ray
```
## Interacting with the fractal
Play with and explore the various preset fractals!
```
KEYS:

[↑][↓][←][→][LEFT CLICK]   Translate fractal
[I]                        Invert controls
[RIGHT CLICK]              Adjust Z constant
[WHEEL UP/DOWN][HOME][END] Zoom about mouse cursor
[+][-]                     Zoom about center
[*][/]                     Increase/decrease fractal iterations
[[][]]                     Increase/decrease windowsize
[NUMPAD 0]                 Reset image
[1-8]                      Change fractal
[FN][DEL]                  Increase/decrease pulse speed
[P]                        Switch on/cycle through colour pulsers
[O]                        Switch off pulser
[A][S] + [NUMPAD 1-9]      Set gradient colour 1/2
[Z]                        Switch on custom fractal gradient
[X]                        Cycle fractal contrasted colours
[C]                        Cycle fractal smooth colours
[V]                        Randomize fractal colours
[ESC]                      Exit program
```
## Background
The graphics are written using minilibx, a library written on top of openGL. For every pixel on the display window, the current fractal's iteration count is calculated and assigned a colour based on the count. By default, there are 16 different colours cycled through; so, every 16 iterations represents a full cycle of colours.
The image is stored in a char buffer, and drawn to the window whenever a change prompts it to do so. The pixel calculations are multithreaded using libpthread, allowing for multiple (default 32) calculations to be run in parallel.
