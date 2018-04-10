#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int edges,vertices; 
    vector <vector<int> > Matrix;
    vector <string> Label;
    vector <bool> Visited;
    public:
        Graph(int);
        void GenerateFromFile(string);
        void insertV(string);
        void insertE(string,string,int);
        bool isEmpty();
        bool isComplete();
        void removeV(string);
        void removeE(string,string);
        void clear();
        void printGraph();
        bool isAdj(string,string);
        int vertex_count();
        int edge_count();
        int search(string);
        void neighbours(string,vector<string> &A);
        void set_wg(string,string,int);
        int degree(string);
        void clearVisits();
        void visit(string);
        bool isVisited(string);
        void printVertLabels();
};

