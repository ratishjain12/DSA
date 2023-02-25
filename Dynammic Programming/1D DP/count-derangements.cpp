
// top-down-approach-recursive-memoization
int mod = 1e9 + 7;

long int solveMem(int n, vector<int> &dp)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = (n - 1) % mod * ((solveMem(n - 1, dp) % mod + solveMem(n - 2, dp) % mod)) % mod;
    return dp[n];
}

long int disarrange(int n)
{
    vector<int> dp(n + 1, -1);
    int ans = solveMem(n, dp);
    return ans;
}

// bottom-up-approach-tabulation
int mod = 1e9 + 7;
long int disarrange(int n)
{
    vector<int> dp(n + 1, -1);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (i - 1) % mod * ((dp[i - 1] % mod + dp[i - 2] % mod)) % mod;
    }
    return dp[n];
}