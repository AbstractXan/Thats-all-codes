#include<bits/stdc++.h>
#include"BST.h"
main()
{
//-------------------------------------
	BST a;
	ifstream file1;
	file1.open("t1.txt");
	int z;
	while(!file1.eof())
		{
			file1>>z;
			a.insert(z);
		}
	file1.close();
	
	cout<<"T1:  \n";
	a.inorder(a.getroot());
	cout<<"\n";
	
//------------------------------------
	BST b;
	ifstream file2;
	file2.open("t2.txt");
	while(!file2.eof())
		{
			file2>>z;
			b.insert(z);
		}
	file2.close();
	
	cout<<"T2:  \n";
	b.inorder(b.getroot());
	cout<<"\n";
//-------------------------------------
	
		
	if(b.getcount()>a.getcount())
	{
		//merge b with a
		a.merge(b,a.getroot());
	
		cout<<"\n Merged Tree: \n";
	
		//b is the new tree
		b.inorder(b.getroot());
		
	}	
	else
	{
		cout<<"\n Merged Tree: \n";
		//merge a with b
		b.merge(a,b.getroot());
	
		//a is the new tree
		a.inorder(a.getroot());
		
	}
	cout<<"\n";
}	
