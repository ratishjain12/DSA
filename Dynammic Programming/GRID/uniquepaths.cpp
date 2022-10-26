#include <iostream>
using namespace std;
// Count unique paths to reach destination (no obstacles)
int uniquepaths(int m,int n){
    int grid[m][n];
    for(int j = 0;j<n;j++){
        grid[0][j] = 1;
    }
    for(int i=0;i<m;i++){
        grid[i][0] = 1;
    }
    for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
    }
    return grid[m-1][n-1];
}

void main(){
    int m = 3;
    int n = 2;
    cout<<"Unique paths are - "<<uniquepaths(m,n); 
}