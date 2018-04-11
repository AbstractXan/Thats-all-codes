#include<bits/stdc++.h>
#include"graphADT.h"
using namespace std;

//Graph constructor
Graph::Graph(int n)
{
	vertices = n;
	edges = 0;
}

void Graph::GenerateFromFile(string file_path)
{
	ifstream file;
	file.open(file_path.c_str());
	
	for(int i=0;i<vertices;i++)
	{
		vector <int> temp;
		for(int j=0;j<vertices;j++)
		{
			int weigh;
			file>>weigh;
			temp.push_back(weigh);
		}
		Matrix.push_back(temp);

		ostringstream num;
		num<<i+1;
		string VertexName = "v"+num.str();
		Label.push_back(VertexName);
	}
	file.close();
}

//Print Adjacency Matrix
void Graph::printGraph()
{
	cout<<"\n\t";
	for(int i=-1;i<vertices;i++)
	{
		if(i==-1)//Printing vertice names
			{
				printVertLabels();
				continue;
			}

		for(int j=-1;j<vertices;j++)
		{
			if(j==-1)//FOr printing vertice names
				{
					cout<<Label[i]<<"\t";
					continue;
				}

			cout<<Matrix[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

//Insert Edge between two vertiecs of given label
void Graph::insertE(string a, string b, int weight)
{
	int a_index = search(a);
	int b_index = search(b);

	//If vertices not found
	if(a_index<0 || b_index<0)
	{
		cout<<"\n Either of the vertices donot exist.\n";
		return;
	}

	cout<<"\n";
	Matrix[a_index][b_index]=weight;
	Matrix[b_index][a_index]=weight;

	edges++;
}

//Insert Vertex with any label
void Graph::insertV(string a)
{
	if(search(a)>-1)
	{
		cout<<"\nVertex "+a+" already exists!\n";
		return;
	}
	//New vertex added to end of label
	Label.push_back(a);
	//Increase vertex count
	vertices++;

	//Increasing columns
	for(int i=0;i<vertices-1;i++)
	{
		Matrix[i].resize(vertices);
	}

	//Increase row
	vector <int> temp;
	temp.resize(vertices);
	Matrix.push_back(temp);
}

//Search for vertex with a label
//Returns index if found.
//Returns -1 if not found.
int Graph::search(string a)
{
	for(int i=0;i<Label.size();i++)
	{
		if(a==Label[i])
		{
			return i;
		}
	}
	return -1;
}

//Prints list of vertices
void Graph::printVertLabels()
{

	for(int i=0;i<Label.size();i++)
	{
		cout<<Label[i]<<"\t";
	}
	cout<<"\n";
}

bool Graph::isEmpty()
{
	if(Label.size()==0)
	{
		return true;
	}
	return false;
}

//If each pair of vertex has atleast one edge (self-loops not included)
bool Graph::isComplete()
{
	for(int i=0;i<vertices;i++){for(int j=0;j<vertices;j++){

			if(i==j) continue;//Ignores self loops
			if (Matrix[i][j]==0) return false;//If incomplete
	
	}}
	return true;
}

void Graph::removeE(string a, string b)
{

	int a_index = search(a);
	int b_index = search(b);

	//If vertices not found
	if(a_index<0 || b_index<0)
	{
		cout<<"\nEither of the vertices donot exist.\n";
		return;
	}

	cout<<"\n";
	Matrix[a_index][b_index]=0;
	Matrix[b_index][a_index]=0;

	edges--;
}

int Graph::vertex_count(){ return vertices;}
int Graph::edge_count(){return edges;}

