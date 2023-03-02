// recursive
int solve(vector<vector<char>> &matrix, int i, int j, int &maxi)
{
    if (i >= matrix.size() || j >= matrix[0].size())
        return 0;
    int right = solve(matrix, i, j + 1, maxi);
    int diagonal = solve(matrix, i + 1, j + 1, maxi);
    int down = solve(matrix, i + 1, j, maxi);
    if (matrix[i][j] == '1')
    {
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}
int maximalSquare(vector<vector<char>> &matrix)
{

    int maxi = 0;
    solve(matrix, 0, 0, maxi);
    return maxi * maxi;
}

// Recursive + Memoization(Top-down)
int solve(vector<vector<char>> &matrix, int i, int j, int &maxi, vector<vector<int>> &dp)
{
    if (i >= matrix.size() || j >= matrix[0].size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int right = solve(matrix, i, j + 1, maxi, dp);
    int diagonal = solve(matrix, i + 1, j + 1, maxi, dp);
    int down = solve(matrix, i + 1, j, maxi, dp);
    if (matrix[i][j] == '1')
    {
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
    {
        return 0;
    }
}
int maximalSquare(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int maxi = 0;
    solve(matrix, 0, 0, maxi, dp);
    return maxi * maxi;
}

// Tabulation (Bottom-up Approach)
int solve(vector<vector<char>> &matrix)
{
    int maxi = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int right = dp[i][j + 1];
            int diagonal = dp[i + 1][j + 1];
            int down = dp[i + 1][j];
            if (matrix[i][j] == '1')
            {
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return maxi * maxi;
}
int maximalSquare(vector<vector<char>> &matrix)
{
    return solve(matrix);
}