// Recursive Approach
// a little bit tricky question
// base case if two vertex are only present then return 0 as no triangulation is possible
int solve(vector<int> &values, int i, int j)
{
    if (i + 1 == j) // base case since first and last element of array will be near to each other
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, values[i] * values[j] * values[k] + solve(values, i, k) + solve(values, k, j));
    }
    return ans;
}
int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    return solve(values, 0, n - 1);
}

// Top-down-approach(Recursive + Memoization)
int solve(vector<int> &values, int i, int j, vector<vector<int>> &dp)
{
    if (i + 1 == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, values[i] * values[j] * values[k] + solve(values, i, k, dp) + solve(values, k, j, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(values, 0, n - 1, dp);
}

// Bottom-up approach

int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {
            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                ans = min(ans, values[i] * values[j] * values[k] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n - 1];
}