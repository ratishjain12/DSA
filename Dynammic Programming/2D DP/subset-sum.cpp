// top-down approach
bool subsetSum(int index, int N, vector<int> arr, int target, vector<vector<int>> &dp)
{

    if (index == N)
    {
        if (target == 0)
            return true;
        else
            return false;
    }
    if (target == 0)
        return true;
    if (target < 0)
        return false;
    if (dp[index][target] != -1)
        return dp[index][target];
    bool incl = subsetSum(index + 1, N, arr, target - arr[index], dp);
    bool excl = subsetSum(index + 1, N, arr, target - 0, dp);

    return dp[index][target] = incl || excl;
}

bool isSubsetSum(vector<int> arr, int target)
{
    // code here
    int N = arr.size();
    vector<vector<int>> dp(N + 1, vector<int>(target + 1, -1));

    return subsetSum(0, N, arr, target, dp);
}

// Tabulation
bool subsetSumTabulation(vector<int> arr, int total)
{
    int N = arr.size();
    vector<vector<int>> dp(N + 1, vector<int>(total + 1, 0));
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
    }

    for (int index = N - 1; index >= 0; index--)
    {
        for (int target = 0; target <= total; target++)
        {
            bool incl = 0;
            if (target - arr[index] >= 0)
                incl = dp[index + 1][target - arr[index]];
            bool excl = dp[index + 1][target];

            dp[index][target] = incl || excl;
        }
    }
    return dp[0][total];
}

bool isSubsetSum(vector<int> arr, int target)
{
    // code here

    return subsetSumTabulation(arr, target);
}