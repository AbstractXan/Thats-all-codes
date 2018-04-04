all: tree

tree:	main.o	BST.o
	g++ main.o	BST.o -o tree
	
main.o: main.cpp
	g++  main.cpp -c
	
BST.o: BST.cpp	BST.h
	g++  BST.cpp -c
	
clean:
	-rm -f *.o tree
	
