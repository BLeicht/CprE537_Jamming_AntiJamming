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
HEADER =	./src/md5.h



MAIN: ./src/main.o ./src/md5.o
	$(GCC) -o main ./src/main.o ./src/md5.o
	
main.o: ./src/main.cpp ./src/md5.h
	$(GCC) -c ./src/main.cpp

md5.o:	./src/md5.cpp ./src/md5.h
	$(GCC) -c ./src/md5.cpp

clean: 
	rm ./src/*.o
