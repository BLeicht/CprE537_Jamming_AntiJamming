# Compiler to use
COMPILER = g++

# Global options for compiler
COPTIONS = -ansi -Wall -Wextra -I./src -std=gnu++11

# VPATH
VPATH = ./src

# Compiler
GCC = $(COMPILER) $(COPTIONS)

# Main target
all: MAIN


MAIN: main.o md5.o packet.o 
	$(GCC) -o main ./src/main.o ./src/md5.o ./src/packet.o
	
main.o: main.cpp packet.hpp packet.cpp
	$(GCC) -c ./src/main.cpp -o ./src/main.o

md5.o: md5.cpp md5.hpp packet.hpp
	$(GCC) -c ./src/md5.cpp -o ./src/md5.o

packet.o: packet.cpp packet.hpp
	$(GCC) -c ./src/packet.cpp -o ./src/packet.o

clean: 
	rm -r ./src/*.o
