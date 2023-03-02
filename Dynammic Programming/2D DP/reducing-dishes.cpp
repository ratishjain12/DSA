// top-down-approach
// like-coefficient = time[i] * satisfaction[i].
int solve(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
{
    if (index == satisfaction.size())
        return 0;
    if (dp[index][time] != -1)
        return dp[index][time];
    int include = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1, dp);
    int exclude = 0 + solve(satisfaction, index + 1, time, dp);
    return dp[index][time] = max(include, exclude);
}
int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(satisfaction, 0, 0, dp);
}

// bottom-up approach

int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        { // here j is time
            int include = satisfaction[i] * (j + 1) + dp[i + 1][j + 1];
            int exclude = 0 + dp[i + 1][j];
            dp[i][j] = max(include, exclude);
        }
    }
    return dp[0][0];
}
