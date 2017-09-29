# variable definitions
CC     = g++
CFLAGS = -g
LIBS   =

# target to build "all"
all: BST.exe

# target for building Inserting 
BST.exe: BST.o main.o
	${CC} -o $@ $^ ${CFLAGS} ${LIBS}

# dependencies for the objects
BST.o: BST.cpp BST.h
main.o: main.cpp BST.cpp

# target to clean up extra files
clean:
	${RM} BST.exe *.o 

# generic target to compile a .cpp file to a .o file with the same name
.cpp.o:
	${CC} ${CFLAGS} -c $<

