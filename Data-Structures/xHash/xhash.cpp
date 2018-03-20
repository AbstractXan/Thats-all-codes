#include<bits/c++.h>

typedef long long int POSTYPE; 
struct Bukt
{

  int count;              //Total data
  vector<string> data;     //Data
}
class xHash
{
  Bukt **Directory;
  
  xHash();
  void readfromfile();

  //Converting input key to index 
  string KeyToBinary(string);
  POSTYPE BinaryToIndex(string);

  //If bucket is Empty or Full
  bool isEmpty(POSTYPE index);
  bool isFull(POSTYPE index);

  void insert(Bukt *b);
}

xHash::xHash()
{
  Directory = new Bukt*[POSTYPE tempsize];
  
}
