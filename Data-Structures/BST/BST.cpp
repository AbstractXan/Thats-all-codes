#include<bits/stdc++.h>
#include"BST.h"
using namespace std;
BST::BST()
{
	//Initialize count to zero and root to null
	count=0;
	root=NULL;
}
void BST::insert(int data)
{
	//Create root if tree doesn't exist
	if(root==NULL)
	{
		struct Node *temp = new Node;
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		root=temp;

		//Increment tree count
		count++;
		
		return;
	}
	
	else{
		//Traverse through tree to insert
		recinsert(data,root);
	}
}

void BST::recinsert(int data,struct Node *curr)
{
	//If data is less that current node's data
	if(data<(curr->data))
	{
		//If left node is NULL: Insert
		if(curr->left==NULL)
		{
		
		//temporary node
		struct Node *temp = new Node;
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		curr->left=temp;

		//Increment tree count		
		count++;

		}
		else
		{
			//Otherwise traverse the left side of current node
			recinsert(data,curr->left);
		}
	}
	if(data>(curr->data))
	{
		if(curr->right==NULL)
		{
		struct Node *temp = new Node;
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		curr->right=temp;
		count++;

		}
		else
		{
		
			recinsert(data,(curr->right));
		}
	}
	return;
	
}

void BST::inorder(struct Node * curr)
{
	
	if(curr==NULL)
	{
		return;
	}
	
	else{
		inorder(curr->left);
		cout<< (curr->data) <<"\t";
		inorder(curr->right);
	}
	
}

struct Node * BST::getroot()
{
	return root;
}

//Recursively calls merge to insert numbers in inorder (ascending) fashion to the other tree
//The smaller tree is deleted simulataneously
void BST::merge(BST b,struct Node * curr)
{
	if(curr==NULL)
	{
		return;
	}
	
	else{
		merge(b,curr->left);
		free(curr->left);
		
		b.insert(curr->data);
		b.addcount();
		merge(b,curr->right);
		free(curr->right);
	}
}

int BST::getcount()
{
	return count;
}
void BST::addcount()
{
	count++;
	return;
}
