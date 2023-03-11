// leetcode dice throw with target sum

// Recursive + Memoization(top-down Approach)
int mod = 1e9 + 7;

int solveMem(int dice, int faces, int target, vector<vector<int>> &dp)
{
    if (target < 0)
        return 0;
    if (target == 0 && dice != 0)
        return 0;
    if (dice == 0 && target != 0)
        return 0;
    if (dice == 0 && target == 0)
        return 1;
    if (dp[dice][target] != -1)
        return dp[dice][target];
    int ans = 0;
    for (int i = 1; i <= faces; i++)
    {
        ans = (ans + solveMem(dice - 1, faces, target - i, dp)) % mod;
    }
    return dp[dice][target] = ans % mod;
}
int numRollsToTarget(int n, int k, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    return solveMem(n, k, target, dp);
}

// Tabulation

int mod = 1e9 + 7;

int numRollsToTarget(int n, int k, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int dice = 1; dice <= n; dice++)
    {
        for (int t = 1; t <= target; t++) // t is target up to the given target
        {
            int ans = 0;
            for (int i = 1; i <= k; i++) // k here is faces
            {
                if (t - i >= 0)
                {
                    ans = (ans + dp[dice - 1][t - i]) % mod;
                }
            }
            dp[dice][t] = ans % mod;
        }
    }
    return dp[n][target];
}