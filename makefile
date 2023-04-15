# Compiler to use
COMPILER = g++

# Global options for compiler
COPTIONS = -ansi -Wall -Wextra -Ihlib/

# Compiler :)
GCC = $(COMPILER) $(COPTIONS)

# Specifies directories make should search for files
VPATH = hlib

# Main target
all: MD5 MAIN

# Header files
HEADER =	hlib/hashlibpp.h \
		hlib/hl_exception.h \
		hlib/hl_hashwrapper.h \
		hlib/hl_md5.h \
		hlib/hl_md5wrapper.h \
		hlib/hl_types.h \
		hlib/hl_wrapperfactory.h



MAIN: main.o hl_md5.o hl_md5wrapper.o hl_wrapperfactory.o
	$(GCC) -o main main.o hl_md5.o hl_md5wrapper.o hl_wrapperfactory.o

main.o: main.cpp hlib/hashlibpp.h
	$(GCC) -c main.cpp

MD5:	hl_md5.o hl_md5wrapper.o hl_wrapperfactory.o
	$(GCC) -c hlib/hl_md5.cpp

hl_md5.o: hl_md5.cpp hl_md5.h
	$(GCC) -c hlib/hl_md5.cpp

hl_md5wrapper.o: hl_md5wrapper.cpp hl_md5wrapper.h
	$(GCC) -c hlib/hl_md5wrapper.cpp

hl_wrapperfactory.o: hl_wrapperfactory.cpp hl_wrapperfactory.h hashlibpp.h
	$(GCC) -c hlib/hl_wrapperfactory.cpp

clean: 
	rm *.o
