int lcs(string str1, string str2)
{
    vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));

    for (int i = str1.length() - 1; i >= 0; i--)
    {
        for (int j = str2.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (str1[i] == str2[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int minOperations(string str1, string str2)
{
    // Your code goes here
    int dele = str1.length() - lcs(str1, str2);
    int ins = str2.length() - lcs(str1, str2);
    return dele + ins;
}