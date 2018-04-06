#include<bits/stdc++.h>
using namespace std;
struct root
{
	string name;
	int numcount;
	struct data *data_pointer;	
};
struct data{
	string number;
	struct data *next_data;
};

class Directory
{
	vector<struct root *> Dir;
	long int count;

public:	
	//Main operations
	Directory();
	void getdirectory();
	void check(string name);
	void modify(string name);
	void deletenum(string name);
	void addnum(string name,string number);
	void savedir();
	void printDirectory();
	void build();
	void commit();
	//Sub-operations seful for main operations
	long int find(string name);
	void printnumbers(long int i);
	long int getcount();
	struct data * findnumber(long int index, string newnum);
	struct data * findprevnumber(long int index, string newnum);
};



