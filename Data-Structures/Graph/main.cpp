#include<bits/stdc++.h>
#include"Graph.h"
using namespace std;	
int main(int argc, char** argv)
{
	assert(argc<=5);
	int SIZE = atoi(argv[1]);
	int SEED = atoi(argv[2]);
	float threshold = atof(argv[3]);
	Graph g(SIZE);
	g.genGraph(SIZE,SEED,threshold);
	//g.readfromfile(argv[4],SIZE);
	g.PrintAdj();
	if(g.isCycle())
	{
		cout<<"\nGraph is a cycle";
	}
	else
	{
		cout<<"\nGraph is not a cycle";
	}
	
	cout<<endl;
	
	g.printStronglyConnected();
	g.maxdepth();
	g.rad();
	if(g.stronglyConnected())
	{
		cout<<"\nGraph is strongly connected";
	}
	else
	{
		cout<<"\nGraph is not strongly connected";
	}

	cout<<"\n";
	return 0;	
}

