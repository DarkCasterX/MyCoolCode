# MyCoolCode
Just something to play around with.

So far, all I have is a C implementation of Linked Lists for practice, will add more code with interesting data structure implementations in the future. Feel free to give feddback on how to more efficiently code the data structures of any of the functions I use with them.

----------Compiling instructions-----------

1. Compile listlib.c with the -c switch to create an object file
   which gives access to all the functionality of the header

E.g: gcc listlib.c -c

2. Compile whatever code you made by linking listlib

E.g: gcc code.c -o code listlib.o

3. If you're using a different compiler, search up how to make pure object files (not executables)
   with your compiler of choice. Also, search up how to link your own object files in your
   executables (or binaries).
