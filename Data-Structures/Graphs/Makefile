all: Graph

Graph: main.o Graph.o
	g++ main.o Graph.o -o graph

main.o: main.cpp
	g++ main.cpp -c

Graph.o: graphADT.h Graph.cpp
	g++ Graph.cpp -c

clean:
	rm -f *.o graph
