*This project has been created as part of the 42 curriculum by abmusleh.*

# so_long

## Description

**so_long** is a simple 2D game project created in C using the MiniLibX (MLX) graphical library. The goal of the project is to create a top-down game where the player controls a character who must traverse a map, collect all collectibles, and reach the exit in the shortest number of moves possible.

This project focuses on the following concepts:
* Window management and event handling (keyboard inputs, window closing).
* Texture rendering and sprite management.
* Map parsing and validation (reading `.ber` files).
* Algorithmic validation (using Flood Fill to ensure a valid path exists).

The game adheres to strict rules regarding map composition (walls, player start, exit, collectibles) and error management.

Controls to play the game:
Key	    Action
W / ↑	Move up
A / ←	Move left
S / ↓	Move down
D / →	Move right
ESC	    Quit the game

The goal is to collect all the collectibles and exit.

## Instructions

`Compilation:` To run this project, we use a C compiler, Makefile, and run the command: `make`.

`Execution:` write "./so_long maps/example.ber" on the terminal after compiling.


### Installation
Installing the *MiniLibX* library is required to compile and run this project. *MiniLibX*is the graphical library provided by 42 and is used to create windows, handle events, and render images.
Once downloaded, place the MiniLibX folder in your project directory.

## Resources

- https://aurelienbrabant.fr/blog/events-with-the-minilibx
- https://www.youtube.com/watch?v=bYS93r6U0zg
- https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx

AI was used strictly as a development aid. It provided assistance in understanding concepts like the mlx library functions and flood fill.