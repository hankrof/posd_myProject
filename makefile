INC_DIR = include
CC		= g++
CFLAG   = -Wall -g3 -std=gnu++0x

all: hw1

hw1: main.o Shapes.o Media.o
ifeq (${OS}, Windows_NT)
	${CC} -o hw1 main.o Shapes.o Media.o -lgtest
else
	${CC} -o hw1 main.o Shapes.o Media.o -lgtest -lpthread
endif
	
main.o: main.cpp utSort.h
	${CC} ${CFLAG} -c main.cpp
Shapes.o: $(INC_DIR)/Shapes.h Shapes.cpp
	${CC} ${CFLAG} -c Shapes.cpp
Media.o: $(INC_DIR)/Media.h Media.cpp
	${CC} ${CFLAG} -c Media.cpp

clean:	
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw1
endif
