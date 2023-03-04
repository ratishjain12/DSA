// longest increasing subsequence

// recursive

int solve(int n, int a[], int curr, int prev)
{
    if (curr == n)
        return 0;
    int include = 0;
    if (prev == -1 || a[curr] > a[prev])
    {
        include = 1 + solve(n, a, curr + 1, curr);
    }
    int exclude = solve(n, a, curr + 1, prev);
    return max(include, exclude);
}
int longestSubsequence(int n, int a[])
{
    // your code here
    return solve(n, a, 0, -1);
}

// Recursive + Memoization
// prev+1 because we are starting from -1 and array does not have -1 index
int solveMem(int n, int a[], int curr, int prev, vector<vector<int>> &dp)
{
    if (curr == n)
        return 0;

    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];
    int include = 0;
    if (prev == -1 || a[curr] > a[prev])
    {
        include = 1 + solveMem(n, a, curr + 1, curr, dp);
    }
    int exclude = solveMem(n, a, curr + 1, prev, dp);
    return dp[curr][prev + 1] = max(include, exclude);
}

int longestSubsequence(int n, int a[])
{
    // your code here
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solveMem(n, a, 0, -1, dp);
}

// Tabulation
