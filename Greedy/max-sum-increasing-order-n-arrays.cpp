int maximumSum(int n, int m, vector<vector<int>> &a)
{
    // Complete the function
    int sum = 0;
    int limit = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        int maxi = INT_MIN;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] < limit)
            {
                maxi = max(maxi, a[i][j]);
            }
        }
        if (maxi < 0)
            return 0;
        sum += maxi;
        limit = maxi;
    }
    return sum;
}