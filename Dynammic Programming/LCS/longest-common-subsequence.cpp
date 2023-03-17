// recursive + memoization
int solve(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i == s1.length())
    {
        return 0;
    }
    if (j == s2.length())
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    if (s1[i] == s2[j])
    {
        ans = 1 + solve(s1, s2, i + 1, j + 1, dp);
    }
    else
    {
        ans = max(solve(s1, s2, i, j + 1, dp), solve(s1, s2, i + 1, j, dp));
    }

    return dp[i][j] = ans;
}
int lcs(string s1, string s2)
{
    // your code here
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    return solve(s1, s2, 0, 0, dp);
}

// tabulation(Bottom-up)
int lcs(string s1, string s2)
{
    // your code here
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));

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
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            }

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

///// Aditya Verma Approach /////
int lcs(int x, int y, string s1, string s2)
{
    // your code here
    int t[s1.length() + 1][s2.length() + 1];
    for (int i = 0; i <= s2.length(); i++)
        t[0][i] = 0;
    for (int i = 0; i <= s1.length(); i++)
        t[i][0] = 0;
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }
    return t[s1.length()][s2.length()];
}