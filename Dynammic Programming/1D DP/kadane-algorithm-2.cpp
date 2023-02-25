// finding maximum sum of non-adjacent elements
long long maximumSum(int arr[], int n)
{
    // Your code here
    vector<int> dp(n, -1);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(arr[i], max(dp[i - 1], dp[i - 2] + arr[i]));
        // for negative value we are checking for current arr[i];
    }
    return dp[n - 1];
}