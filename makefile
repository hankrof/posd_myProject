CC    = g++ 
CFLAG = -g3 -std=gnu++14

hw2: hw2.o
ifeq (${OS}, Windows_NT)
	${CC} ${CFLAG} -o hw2 hw2.o -lgtest
else
	${CC} ${CFLAG} -o hw2 hw2.o -lgtest -lpthread
endif

hw2.o:hw2.cpp atom.h number.h utTerm.h variable.h
	${CC} ${CFLAG} -c hw2.cpp
clean:
	rm hw2 *.o
