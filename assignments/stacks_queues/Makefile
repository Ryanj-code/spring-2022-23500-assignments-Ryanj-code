main: stack.o queue.o Node.o main.o
	g++ -o main stack.o queue.o Node.o main.o

tests: tests.o stack.o queue.o Node.o
	g++ -o tests stack.o queue.o Node.o tests.o

stack.o: stack.cpp stack.h Node.h

queue.o: queue.cpp queue.h

Node.o: Node.cpp Node.h

main.o: main.cpp stack.h queue.h

tests.o: tests.cpp stack.h queue.h

clean:
	rm -f *.o
