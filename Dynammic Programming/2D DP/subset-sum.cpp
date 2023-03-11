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