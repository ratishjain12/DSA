// top-down-approach-

int solve(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solve(n - i * i, dp));
    }
    dp[n] = ans;
    return dp[n];
}
int numSquares(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

// bottom-up-approach-tabulation

int numSquares(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= n; j++)
        {
            int temp = j * j;
            if (i - temp >= 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - temp]);
            }
        }
    }
    return dp[n];
}