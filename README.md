# CIS 25 - Project 1
This is a program that's designed to provide an interface with the user in order to design a 5 by 5 tile with varying opacities.

Programmed by Anthony Liu on 9/20/24
# Setup
In order to run this program, simply execute main.cpp and the rest of the input should be done in the terminal.
The acceptable inputs are already listed in the program with the "list" and "help" functions, but for redudancy I will explain them in detail here.
## Input
### list
Typing "list" in the terminal will print a list of the names of the current implemented patterns. Use this to reference patterns for operation commands.
### clear
Typing "clear" in the terminal will erase your current tile, starting fresh with a blank slate.
### flip
Typing "flip" in the terminal will invert all the values of your current tile. Blank spaces will become solid, and solid spaces will become blank, etc.
### help
Typing "help" in the terminal will print a guide on how to format your inputs to perform commands and operations via. the terminal.
### quit
Typing "quit" in the terminal will end the program, preventing any communication between the user and the terminal and finalizing your tile's design.
### add
Typing "x add y", referencing a pattern from "list" for x, and inputting any numerical value (automatically clamped between 0 to 4) for y will perform the add operation onto your tile. This adds y to every value of your tile that intersects with x.
### subtract
Typing "x subtract y", referencing a pattern from "list" for x, and inputting any numerical value (automatically clamped between 0 to 4) for y will perform the subtract operation onto your tile. This subtracts y to every value of your tile that intersects with x.
### show
Typing "x show y", referencing a pattern from "list" for x, and inputting any numerical value (automatically clamped between 0 to 4) for y will output the referenced pattern to the terminal with a value of y. This has no effect on your current tile.
# General Info
This program is able to draw 5x5 tiles with varying opacity by storing tiles with a 2-dimensional array of integers with values ranging from 0 to 4. When printing out a tile, the program references a character from a list of ASCII symbols that represent opacity, and pritns out the index based on the value of the tile. This is how the program is able to seemingly blend patterns together at different potencies. The addition and subtraction operations are pretty simple, iterating through every value of the current tile and adding or subtracting values referenced from a prefrabricated pattern onto the original tile. Pairing all of these methods with a simple user interface using the terminal allows the user to design small tiles however they wish.
