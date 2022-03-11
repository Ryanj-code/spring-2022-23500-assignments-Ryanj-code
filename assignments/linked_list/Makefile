main: main.o OList.o Node.o 
	g++ -o main main.o Node.o OList.o

tests: tests.cpp OList.o Node.o
	g++ -o tests tests.o OList.o Node.o


main.o: main.cpp OList.h

tests.o: tests.cpp doctest.h OList.h 

OList.o: OList.cpp OList.h Node.h

Node.o: Node.cpp Node.h


clean: 
	rm -f *.o main tests
