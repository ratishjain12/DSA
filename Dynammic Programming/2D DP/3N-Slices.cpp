
// this question is similar to houserobber-2 question
// 3N slices are there and there are three people so each will get 3N/3 = N slices

// Top-down approach (Recursive + Memoization)

int solve(int index, int endIndex, vector<int> &slices, int n, vector<vector<int>> &dp)
{
    if (index > endIndex || n == 0)
    {
        return 0;
    }
    if (dp[index][n] != -1)
        return dp[index][n];
    int take = slices[index] + solve(index + 2, endIndex, slices, n - 1, dp);
    int notTake = 0 + solve(index + 1, endIndex, slices, n, dp);
    return dp[index][n] = max(take, notTake);
}

int maxSizeSlices(vector<int> &slices)
{
    int k = slices.size();
    vector<vector<int>> dp1(k + 1, vector<int>(k + 1, -1));
    int case1 = solve(0, k - 2, slices, k / 3, dp1);
    vector<vector<int>> dp2(k + 1, vector<int>(k + 1, -1));
    int case2 = solve(1, k - 1, slices, k / 3, dp2);
    return max(case1, case2);
}

// Bottom-up approach(Tabulation)
