1-D/2-D Convolution
-------------------

A Simple C Program that performs convolution on an array of 25 sensor values.



File Description
-----------------

main.c - source file where the main source code exists.
kernel.c - source file where kernel functions are defined.
kernel.h - function prototypes of kernel.c are defined
Makefile - Makefile to compile main
Readme.txt - basic description of the folder.

File dependencies
-----------------

kernel.h ---------------------> kernel.c
kernel.h kernel.c-------------> main.c

Commands
--------

$ make main
Compiles main.c and generates an executable called 'main'

$ ./main
Executes the program