#include <bits/stdc++.h>
#include "hash.h"

using namespace std;
node *Makenode(long long int c, string s){
	node *t = new node;
	t->name = s;
	t->count = c;
	t->flag = 0;
	return t;
}

int main(int argc, char**argv){
	assert(argc==3);
	long long int si = atoi(argv[1]),co = 2;
	string s = argv[2];
	if(s=="LP"){
		co = 1;
	}
  else if(s=="QP")
  {
    co=2;
  }
	Hash h(si,co);
  cout<<"\n<<<Reading from file>>>\n";
  h.readfromfile();
  cout<<"\n<<<Reading complete>>>\n";

  while(1){
		int opt;
		long long int siz;
		string s;
		cout<<"\n---------------------------------------------------------------------------------\n";
		cout<<"\nOptions:\n1.Exit\t\t2.Retrive <string>\t3.Insert <string>\n4.Delete\t5.Loadfactor\t\t6.Rehash <tablesize>\n7.Probe Stats\t8. Print data\n";

		cout<<"\n Currentsize: "<<h.getcurrentsize()<<"/"<<h.gethashsize()<<"\n Input :";
		cin >> opt;
		cin.clear();

		if(opt == 1){
			break;
		}
		else if(opt == 2){
			cin>>s;
			h.retrieve(s);
		}
		else if(opt == 3){
			cin>>s;
			h.Insert(Makenode(1,s));
		}
		else if(opt == 4){
			cin>>s;
			h.del(s);
		}
		else if(opt == 5){
			cout<<" Loadfactor = "<<h.loadfactor()<< "\n";
		}
		else if(opt == 6){
			cin>>siz;
			h.manualrehash(siz);
		}
		else if(opt == 7){
			h.stats();
		}
		else if(opt == 8){
			h.print();
		}
		else{
			cout<<"Invalid Entry\n";
			continue;
		}
	}
}
