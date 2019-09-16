// https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately/0/?ref=self

#include <iostream>
using namespace std;

long int getOld(long int number,long int max){
    if(number/max==0){
        return number;
    }
    return number%max;    
}

int main() {
		int testcases;
	cin >> testcases;
	
	//Loop over all testcases
	for(int t=0;t<testcases;t++){
	    int size;
	    cin >> size;
	    long int arr[size];
	    for(int i=0; i<size; i++){
	       cin >> arr[i];
	    }
	    
	    int j = size-1;
	    int max_element = arr[j];
	    
	    for(int i=0;i<=size-1;i=i+2){
	        // Even => Max
	            //New
	            if(i<=j){
	            arr[i] += max_element*arr[j]; //*New + old
	            j--;
	            }else{
	                arr[i] += max_element*getOld(arr[j],max_element);
	                j--;
	            }
	    }
	    //Reset j to beginning
	    j=0;
	    for(int i=1;i<=size-1;i=i+2){
	        // Odd => Min
	            //New
	            arr[i] += max_element*(arr[j]%max_element);
	            j++;
	    }
	    for(int i=0; i<size-1; i++){
	        cout << arr[i]/max_element << " ";
	    }

        // Hacky fix to get last element right
	    cout << (arr[size-1]/max_element)-1;
	    cout << "\n";
	}
	return 0;
}