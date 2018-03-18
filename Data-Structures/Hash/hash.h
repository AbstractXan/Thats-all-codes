#ifndef __HASH_H_INCLUDE
#define __HASH_H_INCLUDE

#include <bits/stdc++.h>
using namespace std;



struct node
{
  string name;
  long long int count;
  int flag;
};

class Hash
{
private:
  long long int SIZE;
  long long CollID;
  long long int currSIZE;
  long long int up, sp;
  node **hash;
  long long int collisions;
  long long int rehashes;

public:
  Hash(long long int,long long int);
  void readfromfile();
  unsigned long hashfunc(string str);
  bool isEmpty(long long int index);
  void Insert(node *p);
  long long int resolve(string str, long long int temp);
  long long int find(string str);
  bool del(string str);
  void rehash(long long int newsize);
  void retrieve(string str);
  float loadfactor();
  void stats();
  void print();
  long long int getcurrentsize();
  long long int gethashsize();
  void manualrehash(long long int newsize);
};

#endif
