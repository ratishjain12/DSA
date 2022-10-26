#include <iostream>
#include <vector>
using namespace std;

int minpathsum(vector<vector<int> >&grid){
    int m = grid.size();
    if(m == 0) return 0;
    int n = grid[0].size();
    int dp[m][n];
    dp[0][0]=grid[0][0];
    for(int j = 1;j<n;j++){
        dp[0][j] = grid[0][j] + dp[0][j-1];
    }
    for(int i = 1;i<m;i++){
        dp[i][0] = grid[i][0] + dp[i-1][0];
    }
    for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}
int main(){
    vector<vector<int> >grid(3,vector<int>(3,1));
    cout<<"Minimum path sum is - "<<minpathsum(grid);
    return 0;
}
