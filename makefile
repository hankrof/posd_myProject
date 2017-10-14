CC    = g++ 
CFLAG = -Wall -g3 -std=gnu++14


hw3: hw3.o
ifeq (${OS}, Windows_NT)
	${CC} ${CFLAG} -o hw3.exe hw3.o -lgtest
else
	${CC} ${CFLAG} -o hw3 hw3.o -lgtest -lpthread
endif

hw3.o:hw3.cpp atom.h number.h struct.h variable.h utStruct.h utVariable.h
	${CC} ${CFLAG} -c hw3.cpp
clean:
ifeq (${OS}, Windows_NT)
	del hw3.exe *.o	
else
	rm hw3 *.o
endif

