// Find maximum number of ways you can make the sum by using the denominations
long long int solveTab(int coins[], int N, int sum)
{
    long long int dp[N + 1][sum + 1];
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 1; // if the sum value is zero maximum possible is 1
    }
    for (int j = 0; j <= sum; j++)
    {
        dp[0][j] = 0; // if there are zero coins and there is 0 ways to make the sum
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][sum];
}
long long int count(int coins[], int N, int sum)
{

    // code here.
    return solveTab(coins, N, sum);
}