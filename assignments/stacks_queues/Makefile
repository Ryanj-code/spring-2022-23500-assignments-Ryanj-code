main: stack.o queue.o Node.o main.o
	g++ -o main stack.o queue.o Node.o main.o

tests: tests.o stack.o queue.o Node.o
	g++ -o tests stack.o queue.o Node.o tests.o

stack.o: stack.cpp stack.h Node.h
	g++ -c stack.cpp

queue.o: queue.cpp queue.h
	g++ -c queue.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

main.o: main.cpp stack.h queue.h
	g++ -c main.cpp

tests.o: tests.cpp stack.h queue.h
	g++ -c tests.cpp

clean:
	rm -f *.o
