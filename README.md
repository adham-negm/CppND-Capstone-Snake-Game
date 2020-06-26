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
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Added Feature

* Added a new type of food that acts as a powerup 
* There are 4 types of powerups and they're spawned randomely every fifth food placement
* each power have a different color and effect
  * Red 	 -> Increases snake length
  * Green	 -> Decrease snake length
  * Blue 	 -> Decrease snake speed
  * Purple -> Increase snake speed

## Rubric Points

* The project demonstrates an understanding of C++ functions and control structures. can be seen in snake.cpp line 70 in function "SuperGrow"


* The project uses Object Oriented Programming techniques. snake.h line 18 in the new class "Food"

* Classes use appropriate access specifiers for class members. snake.h line 18 in the new class "Food"

* Class constructors utilize member initialization lists. snake.h line 18 in the new class "Food"  

* Classes encapsulate behavior. snake.h line 18 in the new class "Food" encapsulate "FoodType"

* The project uses multithreading. game.cpp line 118 in creating a thread to perform the enlargment function



























