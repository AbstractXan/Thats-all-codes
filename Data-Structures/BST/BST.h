#include<bits/stdc++.h>

using namespace std;
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

class BST
{
public:
	int count;	//Number of nodes
	struct Node *root;
	
	BST(); //Constructor
	void GenerateTree(string s);
	void recinsert(int data, struct Node *curr);
	void insert(int data);
	void merge(BST b,struct Node *curr);
	void inorder(struct Node *curr);
	struct Node * getroot();
	int getcount();
	void addcount();
};

