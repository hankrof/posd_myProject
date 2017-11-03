CC    = g++ 
CFLAG = -Wall -g3 -std=gnu++14

hw5: hw5.o term.o atom.o number.o struct.o variable.o number.o list.o global.o parser.o scanner.o 

ifeq (${OS}, Windows_NT)
	${CC} ${CFLAG} -o hw5.exe hw5.o term.o atom.o struct.o variable.o number.o list.o global.o parser.o scanner.o -lgtest
else
	${CC} ${CFLAG} -o hw5 hw5.o term.o atom.o struct.o variable.o number.o list.o global.o parser.o scanner.o -lgtest -lpthread
endif

hw5.o:hw5.cpp utParser.h utScanner.h
	${CC} ${CFLAG} -c hw5.cpp
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
global.o:global.h global.cpp
	${CC} ${CFLAG} -c global.cpp
variable.o:variable.h variable.cpp
	${CC} ${CFLAG} -c variable.cpp
scanner.o: scanner.h scanner.cpp
	${CC} ${CFLAG} -c scanner.cpp
parser.o: parser.h parser.cpp
	${CC} ${CFLAG} -c parser.cpp
clean:
ifeq (${OS}, Windows_NT)
	del hw5.exe *.o	
else
	rm hw5 *.o
endif

