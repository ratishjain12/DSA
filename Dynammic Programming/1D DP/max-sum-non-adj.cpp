// top-down-recursive-memoization
int solveRec(int arr[], int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return arr[0];
    if (dp[n] != -1)
        return dp[n];
    int include = solveRec(arr, n - 2) + arr[n];
    int exclude = solve(arr, n - 1) + 0;
    dp[n] = max(include, exclude);
    return dp[n];
}

int FindMaxSum(int arr[], int n)
{
    vector<int> dp(n, -1);
    return solveRec(arr, n - 1);
}

//  bottom-up-tabulation
int FindMaxSum(int arr[], int n)
{
    // Your code here
    vector<int> dp(n, -1);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        int include = dp[i - 2] + arr[i];
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[n - 1];
}