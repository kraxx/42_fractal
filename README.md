# 42_fractal
Fractal generator. Wows and bedazzles. Built as part of 42 Coding University's graphics branch.
<img src="/images/image1.png" alt="Julia 1" width=800 height=800 /><img src="/images/image5.png" alt="Eye of C'thun" width=800 height=800 />
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
<img src="/images/image2.png" alt="Julia 2" width=290 height=290 /><img src="/images/image3.png" alt="Mandelbrot" width=290 height=290 /><img src="/images/image4.png" alt="Burning Ship" width=290 height=290 />

The graphics are written using minilibx, a library written on top of openGL. For every pixel on the display window, the current fractal's iteration count is calculated and assigned a colour based on the count. By default, there are 16 different colours cycled through; so, every 16 iterations represents a full cycle of colours.
The image is stored in a char buffer, and drawn to the window whenever a change prompts it to do so. The pixel calculations are multithreaded using POSIX threads, allowing for multiple calculations to be run in parallel.
