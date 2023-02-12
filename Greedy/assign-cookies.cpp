int findContentChildren(vector<int> &g, vector<int> &s)
{
    int cnt = 0;
    int i = 0, j = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    while (i < g.size() && j < s.size())
    {
        if (s[j] >= g[i])
        {
            cnt++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return cnt;
}