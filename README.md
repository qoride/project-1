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
# Walkthrough
### Creating a tile
When first running the program, it will automatically run the "help" command for you and it should look like this:
![image](https://github.com/user-attachments/assets/8418cb5d-1da2-4a7c-bb9e-adf6b5c9d1f3)

In order to start, we first need to add a pattern to our empty tile.
To see our list of valid patterns, we type "list" into the input.
![image](https://github.com/user-attachments/assets/a81884eb-4252-479e-8eee-65e1f2f6dd25)

Our first input will be the name of the pattern we want to use.
For this example, let's select the pattern "+" for our tile.
![image](https://github.com/user-attachments/assets/b3be2975-12f6-4acd-ac9a-b72465f32dec)

Now that we have told the program which pattern we are going to use, we use the operation "add" to add it to our empty space.
![image](https://github.com/user-attachments/assets/f6ce8472-f7a4-4167-a7e1-ed59718f96c9)

The final step is to choose a value which will determine how transparent the pattern is. For this example we will use the value 2.
![image](https://github.com/user-attachments/assets/8d950151-52e7-4da2-bc94-fb3273090c9d)

Now we have successfully created our tile, and the program has returned back to the main menu.
### Union and negate operations
Patterns can be compounded onto each other, either adding on to or subtracting from the current tile.
First, let's try adding something else to the tile. In this example let's use the pattern "corners" with a value of 3.
The input and result shoud look like this:
![image](https://github.com/user-attachments/assets/5c10ce62-9b44-47a9-824c-2054c23309cd)

Now that we know how to add, let's learn how to use the subtract operator.
In this example, let's try subtracting the pattern "cross" from the tile with a value of 1.
If done correctly, your new tile should look something like this:
![image](https://github.com/user-attachments/assets/23a1c686-b59f-4528-960f-554b94e9ce4b)

### Extras
We've already covered the main stuff, but there are still a couple of neat features that we have not covered yet.
Let's start by creating our own pattern.
In the main menu, enter the command "make", it should bring up this menu:
![image](https://github.com/user-attachments/assets/0eb352a7-272b-444d-a2f3-10bda40d05fa)

We can name our new pattern whatever we want, with the exceptions being pre-existing patterns or menu options/operations.
In this example, I will be naming the pattern "test", feel free to give it your own name.
![image](https://github.com/user-attachments/assets/1119c50e-d486-49a2-830a-7d63126a6113)

Afterwards, the program will prompt you to enter the values for each cell. 1 for on, and 0 for off.
For our first pattern, let's try filling in the empty spaces in our previous pattern.
To do this, our input for the new pattern should look something like this:
![image](https://github.com/user-attachments/assets/793bc3b2-a951-4862-a0f5-443f5df44857)

Type "Y" to create the pattern, and now we will try adding it to our tile.
(Note: you can always refer back to new patterns you create, and they will show up with the "list" command)
In this example, we'll add our new pattern to the tile with a value of 4 and it should look like this:
![image](https://github.com/user-attachments/assets/00571061-2f0a-4524-801d-b51e372540b8)

Next, let's try out the "flip" command! Input "flip" into the console.
![image](https://github.com/user-attachments/assets/7cb3a013-184a-4fb1-96db-f6f542bd8925)

Once you have gotten comfortable with the interface, you can type "tips" to toggle the tips.
Sadly, all good things must come to an end. Try out the "erase" command and wipe your tile clean.
You can always create more, once you are satisfied use the "quit" command to end the program.
