

// tabulation
int lcs(string a, string b)
{
    int t[a.size() + 1][b.size() + 1];
    for (int i = 0; i <= a.size(); i++)
        t[i][0] = i; // filling first row upto a.length()
    for (int j = 0; j <= b.size(); j++)
        t[0][j] = j; // filling first row upto a.length()

    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
                t[i][j] = t[i - 1][j - 1];
            else
                t[i][j] = 1 + min(min(t[i - 1][j], t[i][j - 1]), t[i - 1][j - 1]);
            // t[i-1][j] for delete
            // t[i][j-1] for insert
            // t[i-1][j-1] for replacement
        }
    }
    return t[a.size()][b.size()];
}
int editDistance(string s, string t)
{
    // Code here
    return lcs(s, t);
}