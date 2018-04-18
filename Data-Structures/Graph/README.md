Priyansh Sangule
CS16B021

The code is an implementation of Graph ADT where the graph is randomly generated as an Adjacency Matrix.


>	void genGraph(int SIZE, int SEED, float threshold);
Generates a graph of number of vertices equal to SIZE using seed SEED and adds edge when linking probability is below threshlod

>	void addVertex();
Adds vertex to graph

>	void addEdge(int a,int b);
Adds edge to graph

>	void PrintAdj();
Prints adjacency matrix
	
>	void printDFS(int i);
Prints DFS for the graph

>	void printStronglyConnected();
Prints strongly connected components of the graph

>	void RecursiveStrongConnect(int i);
Recursively prints strongly connected components of the graph

>	void printEdgeVisit();
Prints Edge Visit Matrix where a[i][j] = 1 means that i->j edge has been traversed.

>	bool isCycle();
Returns true if graph is a cycle

>	bool stronglyConnected();
Returns true if graph is strongly connected

>	void maxdepth();
Finds diameter by finding maximum depth of all the traversals in the graph

>	void rad();
Finds radius of the graph by finding minimum distance between points in the graph
	
