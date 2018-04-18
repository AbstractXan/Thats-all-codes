#include<bits/stdc++.h>
#include"Graph.h"
using namespace std;

Graph::Graph(int SIZE)
{
	for(int i=0;i<n;i++)
	{
	VertVisit[i]=false;			//Reset vertex visits to false
	for(int j=0;j<n;j++){
		
		Adj[i][j]=0;			//Reset all adj matrix values to 0
		EdgeVisit[i][j]=false;	//Reset all edge visit valuse to 0
		}
	}
	
	n=SIZE;
	m=0;
	dir=false;
	max_depth=0;
	radius=INT_MAX;
	temp_depth=0;
	connected=true;
}

void Graph::readfromfile(string file, int SIZE)
{
	ifstream f;
	f.open(file.c_str());
	
	while(!f.eof())
	{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
		f>>Adj[i][j];			//Reset all adj matrix values to 0
		}
	}
	}
	f.close();
}

void Graph::genGraph(int SIZE, int SEED, float threshold)
{
	srand(SEED);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
				continue;
				
			float lp=((rand()%100)/100.0);
			if(lp<threshold)
				addEdge(i,j);
			else
				continue;
		}
	}

}

void Graph::addEdge(int a,int b)
{
	Adj[a][b]=1;
	//if(!dir)
	//	Adj[b][a]=1;
	m++;
}

void Graph::PrintAdj()
{
	cout<<"\nAdj Matrix is :\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		cout<<Adj[i][j];
		cout<<"\t";
		}
		cout<<endl;
	}
}

void Graph::printDFS(int i)
{
	temp_depth++;
	VertVisit[i]=true;
	cout<<i<<" ";
	for(int j=0;j<n;j++){		//For every destination
			if(i==j)			//If i==j ignore self loops
				continue;

			if(Adj[i][j]!=0)
			{
				if(VertVisit[j]==false)	//If not visited
				{
					EdgeVisit[i][j]=true;	
					printDFS(j);
					
				}
			}

		}
	
}

void Graph::printStronglyConnected()
{
	int k;
	for(int i=0; i<n;i++)
	{
	for(int j=0;j<n;j++){		//For every destination
			if(i==j)
				continue;
				
			if(Adj[i][j]!=0&&Adj[j][i]==0)
			{
				dir=true;
				k++;
				cout<<"\nStrongly connected: ";
				cout<<i<<" -> ";
				RecursiveStrongConnect(j); //If strongly connected
			}
		}
	
	}
	cout<<"\n"<<k<<" strongly connected components found\n";
	cout<<endl;
}


void Graph::RecursiveStrongConnect(int i)
{	temp_depth++;
	cout<<i;
	for(int j=0; j<n; j++)	
	{
		if(i==j)
			continue;
		if(Adj[i][j]!=0&&Adj[j][i]==0)
		{
			cout<<" -> ";
			RecursiveStrongConnect(j);
		}
		
	}
}

//Prints current edge visit state
void Graph::printEdgeVisit()
{
	cout<<"Edge visited: \n";
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++){
		cout<<EdgeVisit[i][j];	//Print Edge status
		cout<<"\t";
		}
		cout<<endl;
	}
}

//CHECK IS GRAPH IS A CYCLE
bool Graph::isCycle()
{
	
	
	cout<<"\nPrinting DFS: ";
	for(int i=0;i<n;i++)
	{
		if(VertVisit[i]==false)
		{
			if(i>0 && stronglyConnected()==false)
				connected=false;	//If not undirected , not travered in the first go, not connected
				
			temp_depth=0;
			cout<<"\nTaking root "<<i<<" : ";
			
			if(!stronglyConnected())
				printDFS(i);	
			else
				RecursiveStrongConnect(i);
			
			if(max_depth<temp_depth)
			{
				max_depth=temp_depth;
			}

		}
	}
	
	if(temp_depth<3)
	return false;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(Adj[i][j]!=0 && EdgeVisit[i][j]==0)
			{
				return true;
			}
		}
		
	}
	return false;

}

bool Graph::stronglyConnected()
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(Adj[i][j]!=0 && Adj[j][i]!=0)
			{
				return false;
			}
		}
		
	}
	return true;
}

void Graph::maxdepth()
{
	if(connected==false)
	{
		cout<<"Diameter : Infinite\n";
		return;
	}
	///PRINTING DIAMETER
	cout<<"Diameter : "<<max_depth-1<<"\n";
}

void Graph::rad()
{
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		
		temp_depth=0;
		if(!stronglyConnected())
			printDFS(i);	
		else
			RecursiveStrongConnect(i);
			
		if(max_depth<temp_depth)
			{
				max_depth=temp_depth;
			}
		if(radius>temp_depth)
			{
				radius=temp_depth;
			}

	}
	cout<<"\nThe radius is : "<<radius;
}

