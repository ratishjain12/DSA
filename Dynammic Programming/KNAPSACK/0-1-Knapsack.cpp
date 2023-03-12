// Top-down Approach (Recursive + Memoization)
int solveMem(int wt[], int val[], int index, int W, vector<vector<int>> &dp)
{
    if (index == 0) // if we last element of array then check if we can take that weight or not if yes we return that value
    {
        if (wt[0] <= W)
        {
            return val[0];
        }
        else
        {
            return 0; // else we return 0
        }
    }
    if (dp[index][W] != -1)
        return dp[index][W];
    int include = 0;
    if (wt[index] <= W)
    {
        include = val[index] + solveMem(wt, val, index - 1, W - wt[index], dp);
    }
    int exclude = solveMem(wt, val, index - 1, W, dp);

    return dp[index][W] = max(include, exclude);
}

int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return solveMem(wt, val, n - 1, W, dp);
}

// Bottom-up approach(Tabulation)

int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    int t[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = 0;
    }
    for (int j = 0; j <= W; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}