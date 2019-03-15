#include <iostream>
#include <cmath>
using namespace std;

//factorial
long long int fact(int n)
{
  return (n == 1 || n == 0) ? 1 : fact(n - 1) * n;
}

//number of paths from top left corner to bottom right corner
int main() {
	int tests;
	cin >> tests;

	for(int i=0;i<tests;i++){
	    int a,b;
	    cin>>a>>b;
	    long long int num=fact(a+b-2);
	    long long int den=(fact(a-1)*fact(b-1));
	    cout<<num/den<<endl;
	}
	return 0;
}