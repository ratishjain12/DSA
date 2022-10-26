#include <iostream>
#include <vector>
using namespace std;
// Count unique paths to reach destination (with obstacles).
// 0 1 0   1 -> obstacle.
// 0 0 0   0 -> free path.
// 1 0 0

int uniquepathsWithObstacles(vector<vector<int>>&obsGrid){
    int m = obsGrid.size();
    int n = obsGrid[0].size();
    int grid[m][n];
    int flag = false;
    for(int j = 0;j<n;j++){
        if(flag||obsGrid[0][j] == 1){
            flag = true;
            grid[0][j] = 0;
        }else{
            grid[0][j] = 1;
        }
    }
    flag = false   
    for(int i=0;i<m;i++){
       if(flag||obsGrid[i][0] == 1){
            flag = true;
            grid[i][0] = 0;
        }else{
            grid[i][0] = 1;
        }
    }
    for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            if(obsGrid[i][j] == 1){
                grid[i][j] = 0;
            }else{
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
            
        }
    }
    return grid[m-1][n-1];
}

void main(){
    vector<vector<int>>obsGrid(3,vector<int>(3,0));
    obsGrid[0][1] = 1;
    obsGrid[2][0] = 1;
    cout<<"Unique paths are - "<<uniquepathsWithObstacles(obsGrid); 
}