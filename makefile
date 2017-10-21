CC    = g++ 
CFLAG = -Wall -g3 -std=gnu++14

hw4: hw4.o term.o atom.o number.o struct.o variable.o number.o list.o
ifeq (${OS}, Windows_NT)
	${CC} ${CFLAG} -o hw4.exe hw4.o term.o atom.o struct.o variable.o number.o list.o -lgtest
else
	${CC} ${CFLAG} -o hw4 hw4.o term.o atom.o struct.o variable.o number.o list.o  -lgtest -lpthread
endif

hw4.o:hw4.cpp utList.h
	${CC} ${CFLAG} -c hw4.cpp
term.o:term.h term.cpp
	${CC} ${CFLAG} -c term.cpp
atom.o:atom.h atom.cpp
	${CC} ${CFLAG} -c atom.cpp
number.o:number.h number.cpp
	${CC} ${CFLAG} -c number.cpp
struct.o:struct.h struct.cpp
	${CC} ${CFLAG} -c struct.cpp
list.o:list.h list.cpp
	${CC} ${CFLAG} -c list.cpp
variable.o:variable.h variable.cpp
	${CC} ${CFLAG} -c variable.cpp
clean:
ifeq (${OS}, Windows_NT)
	del hw4.exe *.o	
else
	rm hw4 *.o
endif

