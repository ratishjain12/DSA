int longestCommonSubstr(string s1, string s2, int n, int m)
{
    // your code here
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    int res = INT_MIN;
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        for (int j = s2.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (s1[i] == s2[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                ans = 0;
            }
            dp[i][j] = ans;
            res = max(res, dp[i][j]);
        }
    }
    return res;
}