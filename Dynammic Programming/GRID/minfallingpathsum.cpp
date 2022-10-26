    #include<iostream>
    #include<vector>
    using namespace std;

    int minFallingPathSum(vector<vector<int> >&matrix) {
        int m = matrix.size();
        if(m == 0)return 0;
        int n = matrix[0].size();

        int dp[m][n];
        for(int j = 0;j<n;j++) dp[0][j] = matrix[0][j];
        for(int i = 1;i<m;i++){
            for(int j = 0;j<n;j++){
                if(j == 0){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                }else if(j == n-1){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                }else{
                    int n = min(dp[i-1][j],dp[i-1][j-1]);
                    dp[i][j] = matrix[i][j] + min(n,dp[i-1][j+1]);
                }
            }
        }
        int sum = INT_MAX;
        for(int i = 0;i<n;i++){
            sum = min(sum,dp[m-1][i]);
        }
        return sum;
    }
    int main(){
        vector< vector<int> > matrix;
        cout<<"minimum sum falling path is "<<minFallingPathSum(matrix);
        return 0;
    }
