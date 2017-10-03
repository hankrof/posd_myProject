CC    = g++ 
CFLAG = -g3 -std=gnu++14

hw2: hw2.o
ifeq (${OS}, Windows_NT)
	${CC} ${CFLAG} -o hw2 hw2.o -lgtest
else
	${CC} ${CFLAG} -o hw2 hw2.o -lgtest -lpthread
endif

hw2.o:hw2.cpp atom.h Number.h utTerm.h variable.h
	${CC} ${CFLAG} -c hw2.cpp
clean: 
ifeq (${OS}, Windows_NT)
	del hw2.exe *.o	
else
	rm hw2 *.o
endif
