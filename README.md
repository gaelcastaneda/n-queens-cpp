# N-Queens Problem in C++

This project solves the classic 8-Queens problem using recursion and backtracking. The program displays each valid solution graphically on a chessboard and stores all solutions in a text file.

## Problem Description

The objective is to place eight queens on an 8x8 chessboard so that no two queens attack each other. This means that no two queens can share the same:

* Row
* Column
* Diagonal

## Features

* Solves the 8-Queens problem using recursive backtracking.
* Displays each solution graphically using `graphics.h`.
* Uses an image to represent each queen.
* Saves all solutions to a `soluciones.txt` file.
* Allows the user to navigate through solutions one by one.

## Technologies Used

* C++
* Recursion
* Backtracking
* Graphics Programming with `graphics.h`
* File Handling

## Core Algorithm

The program uses backtracking to:

1. Place a queen in a safe position.
2. Mark occupied columns and diagonals.
3. Recursively continue to the next row.
4. Backtrack when no valid position is available.
5. Record every complete solution.

## Output

* Graphical visualization of each valid board configuration.
* Text file containing all discovered solutions.
* Interactive display controlled by keyboard input.

## What I Learned

* Recursive algorithms
* Backtracking techniques
* Constraint satisfaction problems
* File input/output
* Graphical programming in C++

## Academic Context

This project was developed as part of the Computer Systems Engineering program at ESCOM - Instituto Politécnico Nacional.

## Author

Gael Ignacio Castañeda Noguerón
