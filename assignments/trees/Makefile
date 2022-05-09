OBJECTS=main.o BSTree.o Node.o

main: $(OBJECTS)
	g++ -o main $(OBJECTS)
BSTree.o: BSTree.cpp Node.h BSTree.h

main.o: main.cpp Node.h BSTree.h

Node.o: Node.cpp Node.h

clean:
	rm -f $(OBJECTS)
