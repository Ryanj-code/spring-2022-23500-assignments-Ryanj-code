main: main.o OList.o Node.o
	g++ -o main main.o Node.o OList.o

tests: tests.o OList.o Node.o
	g++ -o tests tests.o OList.o Node.o

main.o: main.cpp Node.h
	g++ -c main.cpp

tests.o: tests.cpp OList.h
	g++ -c tests.cpp

OList.o: OList.cpp OList.h Node.h
	g++ -c OList.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm -rf *.o main tests
