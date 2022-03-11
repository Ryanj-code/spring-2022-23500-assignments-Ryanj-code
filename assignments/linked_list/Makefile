OBJECTS = OList.o Node.o 
CXXFLAGS=
LDFLAGS=
CXX=g++

main: main.o OList.o Node.o 
	$(CXX) -o main main.o $(OBJECTS)
	
tests: tests.cpp OList.o Node.o
	$(CXX) -o tests tests.o $(OBJECTS)

main.o: main.cpp OList.h

OList.o: OList.cpp OList.h Node.h

Node.o: Node.cpp Node.h

clean: 
	rm -f *.o
