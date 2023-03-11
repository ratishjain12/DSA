
// return true if equal partition subset sum possible else return false

// Top-down approach(Recursive + Memoization)
int subsetSum(int index, int N, int arr[], int target, vector<vector<int>> &dp)
{
    if (index == N) // index crosses the size of array
    {
        if (target == 0) // check if target has become zero
            return true;
        else
            return false; // else return false
    }

    if (target == 0)
        return 1;
    if (target < 0)
        return 0;
    if (dp[index][target] != -1)
        return dp[index][target];
    int incl = subsetSum(index + 1, N, arr, target - arr[index], dp);
    int excl = subsetSum(index + 1, N, arr, target - 0, dp);

    return dp[index][target] = incl || excl;
}

int equalPartition(int N, int arr[])
{
    // code here

    int target = 0;
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        total += arr[i];
    }
    if (total % 2 != 0)
        return 0;
    if (total % 2 == 0)
    {
        target = total / 2;
    }
    vector<vector<int>> dp(N + 1, vector<int>(target + 1, -1));

    return subsetSum(0, N, arr, target, dp);
}

// Bottom-up Approach(Tabulation)
int subsetSumTabulation(int N, int arr[], int total)
{
    vector<vector<int>> dp(N + 1, vector<int>(total + 1, 0));
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
    }

    for (int index = N - 1; index >= 0; index--)
    {
        for (int target = 0; target <= total / 2; target++)
        {
            bool incl = 0;
            if (target - arr[index] >= 0)
            {
                incl = dp[index + 1][target - arr[index]];
            }

            bool excl = dp[index + 1][target];

            dp[index][target] = incl || excl;
        }
    }
    return dp[0][total / 2];
}
int equalPartition(int N, int arr[])
{
    // code here

    int total = 0;
    for (int i = 0; i < N; i++)
    {
        total += arr[i];
    }
    if (total % 2 != 0)
        return 0;

    return subsetSumTabulation(N, arr, total);
}