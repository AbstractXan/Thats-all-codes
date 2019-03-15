#include <iostream>
using namespace std;

//fills an area of matrix with colour such that adjacent cells of same colour are canged recursively
void floodfill(int x, int y,int colour,int m,int n, int matrix[][100]){
    int initcolour = matrix[x][y];
	matrix[x][y]=colour;
	if(matrix[x+1][y]==initcolour && x!=m-1){floodfill(x+1,y,colour,m,n,matrix);}
	if(matrix[x-1][y]==initcolour && x!=0){floodfill(x-1,y,colour,m,n,matrix);}
	if(matrix[x][y+1]==initcolour && y!=n-1){floodfill(x,y+1,colour,m,n,matrix);}
    if(matrix[x][y-1]==initcolour && y!=0){floodfill(x,y-1,colour,m,n,matrix);}
}

int main() {
	int testcases;
	cin>>testcases;

	for(int t=0; t<testcases; t++){

        //Dimensions of Matrix
	    int m,n;
	    cin>>m>>n;
	    int matrix[m][100];
	    
        //Input matrix
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            cin>>matrix[i][j];
	        }
	    }
	    
        //Coordinates of filling and colour
	    int x1,y1,colour1;
	    cin>>x1>>y1>>colour1;
	    
        //Flood Fill at that point
	    floodfill(x1,y1,colour1,m,n,matrix);
	    
        //Print Matrix
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            cout<<matrix[i][j]<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}