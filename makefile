# Compiler to use
COMPILER = g++

# Global options for compiler
COPTIONS = -ansi -Wall -Wextra -Ihlib/

# Compiler :)
GCC = $(COMPILER) $(COPTIONS)

# Specifies directories make should search for files
#VPATH

# Main target
all: MAIN

# Header files
HEADER =	md5.h



MAIN: main.o md5.o
	$(GCC) -o main main.o md5.o
	
main.o: main.cpp md5.h
	$(GCC) -c main.cpp

md5.o:	md5.cpp md5.h
	$(GCC) -c md5.cpp

clean: 
	rm *.o
