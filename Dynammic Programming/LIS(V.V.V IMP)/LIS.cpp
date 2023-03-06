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

int longestSubsequence(int n, int a[])
{

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || a[curr] > a[prev])
            {
                include = 1 + dp[curr + 1][curr + 1]; // curr+1 to make sure to change preve
            }
            int exclude = dp[curr + 1][prev + 1]; // prev + 1 for no negative value
            dp[curr][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

// optimal
// instead of using 2D DP Array we use two arrays for current and next
// ans is stored in nextRow[0] as at end nextRow will be equal to last row
int longestSubsequence(int n, int a[])
{

    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || a[curr] > a[prev])
            {
                include = 1 + nextRow[curr + 1]; // curr+1 to make sure to change preve
            }
            int exclude = nextRow[prev + 1]; // prev + 1 for no negative value
            currRow[prev + 1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}