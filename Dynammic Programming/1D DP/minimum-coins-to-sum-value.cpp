// minimum number of coins required to sum up a value
//  top-down approach - recursive + memoization
int solveMem(int coins[], int M, int target, vector<int> &dp)
{
    if (target == 0)
        return 0;
    if (target < 0)
        return INT_MAX;
    if (dp[target] != -1)
        return dp[target];
    int mini = INT_MAX;

    for (int i = 0; i < M; i++)
    {
        int ans = solveMem(coins, M, target - coins[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    dp[target] = mini;
    return mini;
}
// M = size of array V = value for which you have to find number of coins
int minCoins(int coins[], int M, int V)
{
    // Your code goes here
    vector<int> dp(V + 1, -1);
    int ans = solveMem(coins, M, V, dp);
    if (ans == INT_MAX)
        return -1;
    else
        return ans;
}

//--------------------------------------------------//

// bottom-up approach - tabulation
int solveTab(int coins[], int M, int V)
{
    vector<int> dp(V + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    if (dp[V] == INT_MAX)
        return -1;
    return dp[V];
}
int minCoins(int coins[], int M, int V)
{
    // Your code goes here
    int ans = solveTab(coins, M, V);
    return ans;
}

// Another Approach -

int solveTab(int coins[], int N, int sum)
{
    long long int dp[N + 1][sum + 1];
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= sum; j++)
    {
        dp[0][j] = 1e4;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][sum] > 1e3 ? -1 : dp[N][sum];
}
int minCoins(int coins[], int N, int sum)
{
    // Your code goes here
    int ans = solveTab(coins, M, V);
    return ans;
}
