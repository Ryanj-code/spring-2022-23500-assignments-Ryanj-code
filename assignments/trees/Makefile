OBJECTS=main.o BSTree.o Node.o

main: $(OBJECTS)
	g++ -o main $(OBJECTS)

tests: tests.o BSTree.o Node.o doctest.h
	g++ -o tests tests.o BSTree.o Node.o 

BSTree.o: BSTree.cpp Node.h BSTree.h

main.o: main.cpp Node.h BSTree.h

tests.o: tests.cpp Node.h BSTree.h

Node.o: Node.cpp Node.h

clean:
	rm -f $(OBJECTS)
