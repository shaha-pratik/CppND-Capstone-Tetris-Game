# CPPND: Capstone Tetis Game

This is a repo for my the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). 

[Tetris](https://en.wikipedia.org/wiki/Tetris) is a tile-matching video game created by Russian software engineer Alexey Pajitnov in 1984. It has been published by several companies, most prominently during a war for the appropriation of the game's rights in the late 1980s.

# Steps for creating game

## Step 1:

This game has total 7 peices (square, L, mirrored-L, N, mirrored-N and T, I) as shown in figure below: 

<src = img >

So in the code we have used the bits for reprentation of the block 5x5:

As:
1. Square represented as:

| 0 | 0 | 0 | 0 | 0 |
|---|---|---|---|---|
| 0 | 0 | 1 | 1 | 0 |
| 0 | 0 | 1 | 1 | 0 |
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |


2. L-Shape represented as:

| 0 | 0 | 1 | 0 | 0 |
|---|---|---|---|---|
| 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 1 | 1 | 0 |
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |

3. mirrored-L

| 0 | 0 | 1 | 0 | 0 |
|---|---|---|---|---|
| 0 | 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |

4. N

| 0 | 0 | 0 | 0 | 0 |
|---|---|---|---|---|
| 0 | 0 | 0 | 1 | 0 |
| 0 | 0 | 1 | 1 | 0 |
| 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |

5. mirrored-N

| 0 | 0 | 0 | 0 | 0 |
|---|---|---|---|---|
| 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 1 | 1 | 0 |
| 0 | 0 | 0 | 1 | 0 |
| 0 | 0 | 0 | 0 | 0 |

6. T

| 0 | 0 | 0 | 0 | 0 |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 1 | 0 |
| 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 |

7. I

| 0 | 0 | 0 | 0 | 0 |
|---|---|---|---|---|
| 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 |

In this 1 means white pixel or block is present and 0 means black pixel or block is not present. In the each piece middle pixel will act as rotation point

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

## Make
This project uses [Make](https://www.gnu.org/software/make/). The Makefile has four targets:
* `build` compiles the source code and generates an executable
* `format` applies [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) to style the source code
* `debug` compiles the source code and generates an executable, including debugging symbols
* `clean` deletes the `build/` directory, including all of the build artifacts

## Locally Execution Step
1. Clone the repository in local system.
2. Go to the top folder layout and type `make build`, it will compile the code and generate an executable
3. `make run` will start the game.

## Class Structure

I have used [plantuml](https://www.plantuml.com) for generation of the class diagrams. For the help of for generation of the diagram, here is the [help](https://www.plantuml.com/class-diagram) document.

<img>

## Keyboard Interaction

|Keyboard Key| Action |
|---|---|
|A| Movement Left|
|D| Movement Right|
|S| Movement Down|
|Q| Rotation Clockwise|
|E| Rotation Anticlockwise|
|Space| Fast Movement|

## Score Mechanism

Each line destroyed will get you 10 points and the end of the game it will display the score on terminal.

## Rubric Point Met

### Compiling and Testing (All Rubric Points REQUIRED)

| Criteria | Met |
|---|---|
|The submission must compile and run|Make file is created and code is excuted|

### Loops, Functions, I/O

| Criteria | File| Line |
|---|---|---|
|The project demonstrates an understanding of C++ functions and control structures|all|-|
|The project reads data from a file and process the data, or the program writes data to a file|-|-|
|The project accepts user input and processes the input|game.cpp| 108-191|

### Object Oriented Programming
|Criteria | File | Line |
| --- | --- | --- |
|The project uses Object Oriented Programming techniques| all| - |
|Classes use appropriate access specifiers for class members| all| - |
|Class constructors utilize member initialization lists.|game.cpp board.cpp| 3-14 3-7 |
|Classes abstract implementation details from their interfaces|-|-|
|Classes encapsulate behavior|all|-|
|Classes follow an appropriate inheritance hierarchy|all|-|
|Overloaded functions allow the same function to operate on different parameters|-|-|
|Derived class functions override virtual base class functions|-|-|
|Templates generalize functions in the project|-|-|

### Memory Management
|Criteria | File | Line |
| --- | --- | --- |
|The project makes use of references in function declarations|all|-|
|The project uses destructors appropriately|renderer.cpp|-|
|The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate|board|-|
|The project follows the Rule of 5.|all|-|
|The project uses move semantics to move data, instead of copying it, where possible.|all|-|
|The project uses smart pointers instead of raw pointers.|-|-|

### Concurrency
|Criteria | File |
|---|---|
|The project uses multithreading.|-|
|A promise and future is used in the project|-|
|A mutex or lock is used in the project|-|
|A condition variable is used in the project.|-|



