int numberOfSubstrings(string s)
{
    map<char, int> mp;
    int i = 0;
    int j = 0;
    int count = 0;
    int ans = 0;

    while (j < s.length())
    {
        mp[s[j]]++;
        while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0)
        {
            count++;
            mp[s[i]]--;
            i++;
        }
        ans += count;
        j++;
    }
    return ans;
}