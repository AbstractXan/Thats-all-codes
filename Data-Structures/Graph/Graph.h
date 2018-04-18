#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int Adj[100][100];	//Adjacency Matrix
	int n;				//Number of Vertices
	int m;				//Number of Edges
	bool dir;			//If directed graph
	bool EdgeVisit[100][100];	//Edge visit
	bool VertVisit[100];		//Vertices visited
	int max_depth;				//Diameter
	int temp_depth;	
	int radius;					//Radius
	bool connected;				//If graph is connected
	
public:
	Graph(int n);
	void readfromfile(string file, int SIZE);
	void genGraph(int SIZE, int SEED, float threshold);
	void addVertex();
	void addEdge(int a,int b);
	void PrintAdj();
	void printDFS(int i);
	void printStronglyConnected();
	void RecursiveStrongConnect(int i);
	void printEdgeVisit();
	bool isCycle();
	bool stronglyConnected();
	void maxdepth();
	void maxdistance(int a,int b);
	void rad();
	
	
};

