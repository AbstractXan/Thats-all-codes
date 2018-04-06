#include<bits/stdc++.h>
#include"Directory.h"
using namespace std;

Directory::Directory()
{
	count=0;
}

//Commits directory
void Directory::commit()
{
	ofstream file ;
	file.open("directory.txt");
	long int i=0;
	while(Dir[i])
	{
		string currname = Dir[i]->name;
		struct data *temp= Dir[i]->data_pointer;
		
		while(temp!=NULL)
			{
			file<<"\n"<<currname<<" "<<temp->number;
			temp=temp->next_data;
			}
		i++;
	}
	file.close();
}

//Buil directory
void Directory::build()
{
	cout<<"\nBuilding directory. Please standby.\n";
	cout<<"---------------------------------------------------\n";
	//Generating Diretory
	ifstream file ;
	file.open("directory.txt");

	//Temporary name and number variables
	string temp_name;
	string temp_number;
	
	//Add to directory until end of file
	while(!file.eof())
	{	
		file>>temp_name>>temp_number;
		
		//Add to directory
		addnum(temp_name,temp_number);
	}
	
	file.close();
	printDirectory();
}
//Deletenumber for given name
void Directory::deletenum(string name)
{
	int index = find(name);
	
	if(index<0)
		cout<<"\n '"<<name<<"' not found in Directory.\n";
	else
	{
		//If already empty
		if(Dir[index]->numcount==0)
		{
			return;
		}
		//If there exists only one number
		if(Dir[index]->numcount==1)
		{
			struct data *temp=Dir[index]->data_pointer;
			Dir[index]->data_pointer=NULL;
			free(temp);
			Dir[index]->numcount==0;
			return;
		}
		
		
		//If more than one numbers are present
		cout<<"Numbers are:\n";
		printnumbers(index);
		bool notDeleted=true;
		while(notDeleted)
		{
			cout<<"\nInput the number you want to DELETE\n";
			string newnum;
			cin>>newnum;
			
			struct data *temp=findnumber(index, newnum);
			if(temp!=NULL)	//if number is found
			{
				struct data *prev = findprevnumber(index, newnum);
				prev->next_data=prev->next_data->next_data;
				free(temp);
				notDeleted=false;
			}
			else
			{
				cout<<"\n"<<newnum<<" not found. Please enter a valid number.";
			}
			//Loop
		}
		
	}
}

//Modify
void Directory::modify(string name)
{
	int index = find(name);
	
	if(index<0)
		cout<<"\n '"<<name<<"' not found in Directory.\n";
	else
	{
		cout<<"Numbers are:\n";
		printnumbers(index);
		bool notModified=true;
		while(notModified)
		{
			cout<<"\nInput the number you want to MODIFY\n";
			string newnum;
			cin>>newnum;
			
			struct data *temp=findnumber(index, newnum);
			if(temp!=NULL)	//if number is found
			{
				cout<<"\nInput new number";
				cin>>newnum;
				temp->number=newnum;
				notModified=false;
			}
			else
			{
				cout<<"\n"<<newnum<<" not found. Please enter a valid number.";
			}
			//Loop
		}
		
	}
}
//Checks if name presentin directory ; prints numbers if present
void Directory::check(string name)
{
	int index=find(name);
	if(index<0)
		cout<<"\n '"<<name<<"' not found in Directory.\n";
	else
		printnumbers(index);	
}
//Finds if name present in directory
long int Directory::find(string name)
{
	long int i=0;
	while(i<count)
	{
		if(Dir[i]->name==name)
		{
			cout<<"\nFound "<<name<<"\n";
			//Return index
			return i;
		}
		i++;
	}
	
	//Return -1 if not found
	return -1;
}

//Adds both number along with string
void Directory::addnum(string name,string number)
{
	long int index = find(name);
	if(index<0)	//If not found, add.
	{
		struct root *r =new root;
		r->name=name;
		r->numcount=1;
	
		struct data *n = new data;
		n->number=number;
		n->next_data=NULL;
	
		r->data_pointer=n;
		Dir.push_back(r);
		count++;
	}
	else	//If name already present. insert as first number if not found. Works even if no number is present
	{
		//Inserts it if duplicate not found
		if(findnumber(index,number)==NULL)
		{
		struct data *n = new data;
		n->number=number;
		n->next_data=Dir[index]->data_pointer;
		
		Dir[index]->data_pointer=n;
		Dir[index]->numcount++;
		}
	}
	
}

//Prints Directory
void Directory::printDirectory()
{
	cout<<"\n========================Printing directory==========================";
	long int i=0;
	while(Dir[i])
	{
		cout<<"\n"<<Dir[i]->name<<" : ";
		printnumbers(i);
		i++;
	}
	cout<<"\n========================Printing complete==========================\n\n";	
}

//prints numbers of a given index
void Directory::printnumbers(long int i)
{
	struct data *temp= Dir[i]->data_pointer;
	while(temp!=NULL)
	{
			cout<<temp->number<<", ";
			temp=temp->next_data;
	}
}

//return Directory count
long int Directory::getcount()
{
	return count;
}

//finds if number present for a particular index; Returns null if not found
struct data * Directory::findnumber(long int index, string newnum)
{
	struct data *temp= Dir[index]->data_pointer;
	while(temp!=NULL)
	{
		//cout<<temp->number<<", ";
		//Break when found
		if(temp->number==newnum)
			break;
		temp=temp->next_data;
	}
	return temp;
}

//gets previous node address to the given number;
struct data * Directory::findprevnumber(long int index, string newnum)
{
	struct data *temp= Dir[index]->data_pointer;
	struct data *prev=NULL;
	while(temp!=NULL)
	{
		//cout<<temp->number<<", ";
		//Break when found
		if(temp->number==newnum)
			break;
		prev=temp;
		temp=temp->next_data;
	}
	return prev;
}

