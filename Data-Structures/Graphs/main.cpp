#include<bits/stdc++.h>
#include"graphADT.h"
using namespace std;
int main(int argc,char* argv[]){
		assert(argc==3);
		Graph G(atoi(argv[1]));
		G.GenerateFromFile(argv[2]);
		G.printGraph();
		G.insertV("a");
		G.printGraph();

		cout<<"\nVertices in graph are: \n";
		G.printVertLabels();
		G.insertE("v1","a",3);
		G.printGraph();

		cout<<"\nIs empty: "<<G.isEmpty();
		cout<<"\nIs complete: "<<G.isComplete();
		G.removeE("v1","a");
		G.printGraph();
		G.removeE("v1","v1");
		G.printGraph();
	cout<<"\n";
}