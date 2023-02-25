
// kadane's algorithm means find maximum subarray sum
// problem is to find maximum sum of contigious elements ending at each position and overall maximum sum
long long maximumSum(int arr[], int n)
{

    vector<int> dp(n, -1);
    int ans = INT_MIN;
    if (n == 0)
        return 0;

        for (int i = 0; i < n; i++)
    {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }
    cout << endl;
    return ans;
}