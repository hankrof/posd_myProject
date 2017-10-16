CC    = g++ 
CFLAG = -Wall -g3 -std=gnu++14

hw3: hw3.o term.o atom.o number.o struct.o variable.o number.o
ifeq (${OS}, Windows_NT)
	${CC} ${CFLAG} -o hw3.exe hw3.o term.o atom.o struct.o variable.o number.o -lgtest
else
	${CC} ${CFLAG} -o hw3 hw3.o term.o atom.o struct.o variable.o number.o  -lgtest -lpthread
endif

hw3.o:hw3.cpp utStruct.h utVariable.h
	${CC} ${CFLAG} -c hw3.cpp
term.o:term.h term.cpp
	${CC} ${CFLAG} -c term.cpp
atom.o:atom.h atom.cpp
	${CC} ${CFLAG} -c atom.cpp
number.o:number.h number.cpp
	${CC} ${CFLAG} -c number.cpp
struct.o:struct.h struct.cpp
	${CC} ${CFLAG} -c struct.cpp
variable.o:variable.h variable.cpp
	${CC} ${CFLAG} -c variable.cpp
clean:
ifeq (${OS}, Windows_NT)
	del hw3.exe *.o	
else
	rm hw3 *.o
endif

