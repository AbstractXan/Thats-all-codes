#include <iostream>
using namespace std;

int main() {
	
	int testcases;
	cin >> testcases;
	
	for(int t=0; t< testcases; t++){
	    
	    int size;
	    cin >> size;
	    
	    int zero, one , two;
	    zero = one = two = 0;
	    for(int i=0; i<size; i++){
	        int temp;
	        cin >> temp;
	        
	        switch (temp){
	            case 0:
	                zero++;
	                break;
	            case 1:
	                one++;
	               break;
	            case 2:
	                two++;
	                break;
	        }
	    }
	    
	    for(int i=0; i<zero;i++){
	        cout<< "0 ";
	    }
	    for(int i=0; i<one;i++){
	        cout<< "1 ";
	    }
	    for(int i=0; i<two;i++){
	        cout<< "2 ";
	    }
	    cout<<"\n";
	}
	return 0;
}