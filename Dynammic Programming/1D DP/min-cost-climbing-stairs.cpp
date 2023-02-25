// top-down-recursive-memoization
int solveMem(vector<int> &cost, int n, vector<int> &dp)
{
    if (n == 0)
        return cost[0];
    if (n == 1)
        return cost[1];
    if (dp[n] != -1)
        return dp[n];

    for (int i = 0; i < cost.size(); i++)
    {
        dp[i] = cost[i] + min(solveMem(cost, n - 1, dp), solveMem(cost, n - 2, dp));
    }
    return dp[n];
}

int minCostClimbinStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    int ans = min(solveMem(cost, n - 1, dp), solveMem(cost, n - 2, dp));
    return ans;
}

// bottom-up - tabulation
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n, -1);

    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    return min(dp[n - 1], dp[n - 2]);
}