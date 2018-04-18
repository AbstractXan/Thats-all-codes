all: final

final: Graph.o main.o
	g++ main.o Graph.o -o graph

main.o:	main.cpp
	g++ -c main.cpp

Graph.o: Graph.cpp 
	g++ -c Graph.cpp Graph.h
clear: 
	rm *.o graph
