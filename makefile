CC    = g++ 
CFLAG = -Wall -g -std=gnu++14

hw7: hw7.o term.o atom.o number.o struct.o variable.o number.o list.o global.o parser.o scanner.o node.o iterator.h

ifeq (${OS}, Windows_NT)
	${CC} ${CFLAG} -o hw7.exe hw7.o term.o atom.o struct.o variable.o number.o list.o global.o parser.o scanner.o node.o -lgtest
else
	${CC} ${CFLAG} -o hw7 hw7.o term.o atom.o struct.o variable.o number.o list.o global.o parser.o scanner.o node.o -lgtest -lpthread
endif

hw7.o:hw7.cpp utIterator.h
	${CC} ${CFLAG} -c hw7.cpp
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
node.o: node.h node.cpp
	${CC} ${CFLAG} -c node.cpp

clean:
ifeq (${OS}, Windows_NT)
	del hw7.exe *.o	
else
	rm hw7 *.o	
endif


