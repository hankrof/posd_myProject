CC    = g++
CFLAG = -Wall -g3 -std=gnu++14

all: shell hw8
shell: mainShell.o term.o atom.o number.o struct.o variable.o number.o list.o\
	global.o parser.o scanner.o	shell.o exp.o
ifeq (${OS}, Windows_NT)
	${CC} ${CFLAG} -o shell.exe mainShell.o term.o atom.o struct.o variable.o number.o\
	 list.o global.o parser.o scanner.o shell.o exp.o -lgtest
else
	${CC} ${CFLAG} -o shell mainShell.o term.o atom.o struct.o variable.o number.o\
	 list.o global.o parser.o scanner.o shell.o exp.o -lgtest -lpthread
endif

hw8: hw8.o term.o atom.o number.o struct.o variable.o number.o list.o\
	 global.o parser.o scanner.o	shell.o exp.o

ifeq (${OS}, Windows_NT)
	${CC} ${CFLAG} -o hw8.exe hw8.o term.o atom.o struct.o variable.o number.o list.o global.o parser.o scanner.o shell.o exp.o -lgtest
else
	${CC} ${CFLAG} -o hw8 hw8.o term.o atom.o struct.o variable.o number.o list.o global.o parser.o scanner.o shell.o exp.o -lgtest -lpthread
endif

mainShell.o:mainShell.cpp exp.h
	${CC} ${CFLAG} -c mainShell.cpp
hw8.o:hw8.cpp expression.h exception.h exp.h
	${CC} ${CFLAG} -c hw8.cpp
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
shell.o: shell.h shell.cpp
	${CC} ${CFLAG} -c shell.cpp
exp.o: exp.h exp.cpp
	${CC} ${CFLAG} -c exp.cpp
clean:
ifeq (${OS}, Windows_NT)
	del hw8.exe *.o
else
	rm shell hw8 *.o
endif
