# CIS 25 - Project 1
This is a program that's designed to provide an interface with the user in order to design a 5 by 5 tile with varying opacities.

Programmed by Anthony Liu on 9/20/24
# Setup
In order to run this program, simply execute main.cpp and the rest of the input should be done in the console.
The acceptable inputs are already listed in the program with the "list" and "help" functions, but for documentation purposes I will explain them in detail here.
## Menu Options
### help
Typing "help" will give a brief rundown on how to format console inputs, and what commands are available.
### list
Typing "list" prints the current list of valid patterns.
### clear
Typing "clear" will erase your current tile, starting fresh with a blank slate.
### flip
Typing "flip" will invert all the values of your current tile. Blank spaces will become solid, and solid spaces will become blank, etc.
### tips
Typing "tips" will toggle the extra tips added throughout the program.
### make
Typing "make" will open the tile creation sub-menu which allows the user to design their own patterns and add them to the list of valid patterns.
### quit
Typing "quit" will end the program, preventing any communication between the user and the terminal and finalizing your tile's design.
## Tile Operations
### add
Typing "x add y", referencing a pattern from "list" for x, and inputting any numerical value (automatically clamped between 0 to 4) for y will perform a union operation with pattern "x" and your current tile.
### subtract
Typing "x subtract y", does the same as "x add y" but it will perform a negate operation instead.
### show
Typing "x show y", will show you pattern "x" in the console without effecting your actual tile.
# General Info
This program is gives the user the ability to design 5x5 tiles with varying opacity by perform a series of boolean operations. Tile are stored under a structure called tileSpace which contains a 2-dimensional array of integers (0 to 4). In order to display tiles to the user, the program prints each cell of a tile using nested for-loops while passing the value as the index through a list of ASCII symbols to simulate opacity. This program accounts for various edge cases and achieve a balance between being user-friendly while not limiting the artistic creativity of the user.
