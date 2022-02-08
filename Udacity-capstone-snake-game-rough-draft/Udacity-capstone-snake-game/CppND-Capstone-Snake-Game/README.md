# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

Rubric Items Matched
1
Object Oriented Programming - The project uses Object Oriented Programming techniques.
The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.

To meet this requirement, a GetPlayerName method class to the Game class in game.cpp to hold information about the user's name. The class uses the member functions GetPlayerName and SetPlayerName to get and display user's name once game ends(line 98, line 103).

2
Object Oriented Programming - Classes use appropriate access specifiers for class members.
All class data members are explicitly specified as public, protected, or private.

Within game.h, the private variable string player_name is used to store player name(line 26).

3
Object Oriented Programming - Class constructors utilize member initialization lists.
All class members that are set to argument values are initialized through member initialization lists.

Within controller.h the Controller is initialized with the pause state set to false(line 9).

4
Object Oriented Programming - Classes abstract implementation details from their interfaces.
All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.

To meet this requirment, all non-trivial methods have one line comments explaining their function.

5
Loops, Functions, I/O - The project accepts user input and processes the input.
The project accepts input from a user as part of the necessary operation of the program.

The user has the option to enter their name:
![Screenshot (14)](https://user-images.githubusercontent.com/60715092/149426850-050a5039-c597-4e5a-a232-205469468527.png)


The users name will then be displayed at the end of the game as well as total time elapsed:
![Screenshot (18)](https://user-images.githubusercontent.com/60715092/149426859-355e48cc-7f43-4752-9382-f9a2a5b6fcff.png)


The user has the option to choose a difficulty(Easy, Medium, Hard) with corresponding snake starting speeds:
![Screenshot (15)](https://user-images.githubusercontent.com/60715092/149426877-6c3e16ca-a9e0-4515-b2bb-097b99396144.png)

![Screenshot (16)](https://user-images.githubusercontent.com/60715092/149426889-16046cdd-7a9e-4b3c-95a4-9542b65c190d.png)

Once the game has started, the user can either pause the game by pressing "P" or can end the game by pressing "Q":
