#include<bits/stdc++.h>
#include "hash.h"
using namespace std;

bool IsPrime(long long int number)
{
    if (number == 2 || number == 3)
        return true;
    if (number % 2 == 0 || number % 3 == 0)
        return false;
    long long int divisor = 6;
    while (divisor * divisor - 2 * divisor + 1 <= number)
    {
        if (number % (divisor - 1) == 0)
            return false;
        if (number % (divisor + 1) == 0)
            return false;
        divisor += 6;
    }
    return true;
}

long long int NextPrime(long long int a)
{
    while (!IsPrime(++a))
    { }
    return a;
}


//Hash Table Constructor with
Hash::Hash(long long int tempsize, long long int Coll)
{
  hash = new node*[tempsize];
  for(long long int i=0;i<tempsize;i++)
    hash[i] = NULL;
  SIZE = tempsize;
  CollID=Coll;
  up=0;
  sp=0;
  currSIZE=0;
  collisions=0;
  rehashes=0;
}

void Hash::readfromfile()
    {
      std::string line;
      std::ifstream infile("data.txt");
      while (std::getline(infile, line))
      {
          istringstream iss(line);
          int year, male, female, total;
          char key[100];
          if (!(iss >> year >> total >> male >> female >> key))
          { break; }

          //Creating new node
          node *t = new node;
        	t->name = key;
        	t->count = total;
        	t->flag = 0;

          //Inserting new node
          Insert(t);
          //cout<<"\n Inserted"<<key<<"\n"<<endl;

          //Checking loadfactor
          float l = loadfactor();
          //cout<<"Load fac: "<< l<<endl;
          while(l>0.75)
          {
            cout<<"\n Rehashing after insert ... \n";
            rehash(NextPrime(SIZE*2));
            l = loadfactor();
          }

  // process pair (a,b)
      }
      infile.close();
    }
unsigned long Hash::hashfunc(string str)
{
    unsigned long hash = 5381;
    long long int c;
    int i=0;
    //cout<<"\n";
    while ( str[i]!='\0')
      {
        c = int(str[i]);
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        //cout<<str[i];
        i++;
      }
    //cout<<"\t"<< (hash%SIZE);
    return hash%SIZE;
}

bool Hash::isEmpty(long long int index)
{
  if(hash[index] == NULL || hash[index]->flag == 1){
    return true;
  }
  return false;
}

void Hash::Insert(node *p)
{
  long long int thash = hashfunc(p->name);
  //If not empty get new index
  if(!isEmpty(thash)){
    thash = resolve(p->name,thash);

  }

  //If not empty and is a match, increment count
  if(!isEmpty(thash) && hash[thash]->name == p->name && hash[thash]->flag == 0){
    hash[thash]->count += p->count;
  }
  else
  {
    hash[thash] = p;
    currSIZE++;
  }
}

long long int Hash::resolve(string str, long long int temp){
	//cout<<"Collision";
  collisions++;
	long long int collno = 1;
	long long int t = temp;
	while(not(isEmpty(t)) && hash[t]->name != str){
		if(CollID==1)
    {
			t = temp + collno;
		}
		else if(CollID==2)
    {
			t = temp + collno*collno;
		}
		collno++;
		t = t % SIZE;
	}

	return t;
}

long long int Hash::find(string str)
{
	long long int temp = hashfunc(str);
	long long int i = 1, t = temp;
	while(not(isEmpty(t)) && hash[t]->name != str && i < SIZE/CollID)
  {
		up++;
		if(CollID==1)
    {
			t = temp + i; //Linear Probing
		}
		else if(CollID==2)
    {
			t = temp + i*i;//Quadratic Probing
		}
		i++;
		t = t % SIZE;
	}
	if(i>=SIZE/CollID) //
  {
		return -1;
	}
	if(hash[t] == NULL || hash[t]->flag == 1)
  {
		return -1;
	}
	sp++;
	return t;
}

bool Hash::del(string str)
{
  //Find the entry
	long long int temp = find(str);
	if(temp==-1)
  {
		return false; //If not found
	}
	else
  {
		hash[temp]->flag = 1; //Delete if found
	}
	currSIZE--;
	return true;
}

void Hash::manualrehash(long long int newsize)
  {
    rehashes=0;
    if(newsize<currSIZE){
  		cout<<"Error value too small. Retaining current table size.";
      return;
  	}
    rehash(newsize);
  }
void Hash::rehash(long long int newsize)
{
  //cout<< "\n Newsize: "<<newsize<<"\n";
  currSIZE=0;
  //collisions=0;
  //Create new array of pointers
	node **old;

  //store current data to old
	old = hash;

  //create new hash
	hash = new node*[newsize];
	long long int oldsize = SIZE;

  //update SIZE of new hash
	SIZE = newsize;

  //Clear hash
	for(int i = 0; i < SIZE ; i++)
  {
		hash[i] = NULL;
	}

  //Update new hash with old values
	for(long long int i = 0; i<oldsize ; i++)
  {
		if(old[i]!=NULL&&old[i]->flag==0)
    {
			Insert(old[i]);
		}
    //cout<<"\n \tRehash complete";
	}

  rehashes++;
  //Delete old hash
	free(old);
}

void Hash::retrieve(string str){
	long long int temp = find(str);
	if(temp == -1){
		cout<<str<<" not found! \n";
	}
	else{
		cout<<"\n" <<str<<" has frequency "<<hash[temp]->count<<"\n";
	}
}

float Hash::loadfactor(){
  //cout<<"\n"<<currSIZE<<"/"<<SIZE<<"\n";
	return ((float)currSIZE)/SIZE;
}

void Hash::stats(){
  cout<<"\n <<<<STATS>>>>\n";
	cout<<" Unsuccesful Probes: "<<up<<"\n Succesful Probes: "<<sp<<"\n";
  cout<<" Collisions: "<<collisions<<"\n Rehashes: "<<rehashes<<"\n";
}

void Hash::print(){
  	for(long long int i = 0; i<SIZE ; i++){
  		if(hash[i]!=NULL&&hash[i]->flag==0){
  			cout<<i<<" -> "<<hash[i]->name<<" -> " << hash[i]->count <<"\n" ;
  		}
  	}
  }

long long int Hash::getcurrentsize(){
  return currSIZE;
}

long long int Hash::gethashsize(){
  return SIZE;
}
