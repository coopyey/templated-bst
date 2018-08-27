# templated-bst
A program that templates a binary search tree. Completed the fall of 2017.

This program takes the binary search tree and refactors it into a templated class, testing it with integers as well as the DayOfYear custom type (written in a previous program).

# Program Information
A previous assignment required overloading operators to fit a custom day of year class, while this assignment templates a binary search tree to work with the day of year class. Overloading operators is not required for this assignment and the day of year class only needs to be implemented to work so far as to test the binary search tree. (That being said, being able to print to the screen requires an overload.) 

I have chosen to simply reuse the day of year class from my earlier assignment, so you can find operators for all forms of addition, negation, subtraction, equality, not equal, less/greater than, as well as increments, decrements, file streams, and the index function. These are all fully functional, though not necessarily used within the binary search tree. A simple parsing function can be found within the filestream >> overload.

# Notes
A makefile is included for running compiling and running the program. Simply use `make all` will compile the program. The program was developed in Visual Code on Windows 10 and tested in Cygwin using the g++ compiler, further tested in a Debian lab environment with g++.
