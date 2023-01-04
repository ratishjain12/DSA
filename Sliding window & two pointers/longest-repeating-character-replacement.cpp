int characterReplacement(string s, int k)
{
    int i = 0;
    vector<int> count(26, 0);
    int result = 0;
    int maxf = 0;
    for (int j = 0; j < s.length(); j++)
    {
        count[s[j] - 'A']++;
        maxf = max(maxf, count[s[j] - 'A']);
        while (((j - i + 1) - maxf) > k)
        {
            count[s[i] - 'A']--;
            i++;
        }
        result = max(result, j - i + 1);
    }
    return result;
}