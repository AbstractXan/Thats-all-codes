#include <iostream>
using namespace std;
void sortit(int arr[],int size){
    int high, low, mid;
    low = mid = 0;
    high = size-1;
    
    for(mid=0;mid<=high;){
        
        // Watch carefully
        switch (arr[mid]){
            case 0:
                // Since the relation between mid and low is only to swap zeroes,
                // They swap and move on.
                swap(arr[mid++],arr[low++]);
                break;
            case 2:
            
                // Relation betwenn high and mid is to swap anything.
                // Thus to re-evaluate, mid doesn't move on yet.
                // High-- has to occur as there is certainity to get a 2
                swap(arr[high--],arr[mid]);
                break;
            default:
            
                // If mid encounters one, move on.
                mid++;
                break;
        }
    }
}
int main() {
	
	int testcases;
	cin >> testcases;
	
	for(int t=0; t< testcases; t++){
	    
	    int size;
	    cin >> size;
	    
	    int arr[size];
	    
	    for(int i=0; i<size; i++){
	        cin >> arr[i];
	    }
	    
	    sortit(arr,size);
	    
	    
	    for(int i=0; i<size; i++){
	        cout << arr[i] << " ";
	    }
	    
	    cout<<"\n";
	}
	return 0;
}