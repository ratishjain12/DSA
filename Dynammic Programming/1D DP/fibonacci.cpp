
// top-down approach - recursive+memoization
int fib(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

long long int nthFibonacci(long long int n)
{
    // code here
    vector<int> dp(n + 1, -1);
    return fib(n, dp);
}

// bottom-up approach - tabulation

long long int nthFibonacci(long long int n)
{
    // code here
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}