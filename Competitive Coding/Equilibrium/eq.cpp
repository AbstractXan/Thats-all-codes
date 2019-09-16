#include <iostream>
using namespace std;

int main() {
	int testcases;
	cin >> testcases;
	
	for(int t=0; t<testcases; t++){
	    
	    int size;
	    cin >> size;
	    
	    int arr[size];
	    int sum=0;
	    for(int i=0; i<size;i++){
	        cin >> arr[i];
	        sum+=arr[i];
	    }
	    
	    int leftsum=0;
	    int rightsum=sum;
	    int i;
	    for(i=0;i<size;i++){
	        
	        // arr[i] as pivot
	        rightsum-=arr[i];
	        
	        if(leftsum==rightsum){
	            cout << i+1 ;
	            break;
	        }
	        
	        // Update left sum to include arr[i] now
	        leftsum+=arr[i];
	    }
	    if(i==size){
	        cout << "-1" ;
	    }
	    cout << "\n";
	}
	return 0;
}