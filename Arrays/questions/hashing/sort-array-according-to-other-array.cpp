vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M)
{
    // Your code here
    vector<int> ans;
    map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        mp[A1[i]]++;
    }
    for (int i = 0; i < M; i++)
    {
        if (mp.find(A2[i]) != mp.end())
        {
            while (mp[A2[i]])
            {
                ans.push_back(A2[i]);
                mp[A2[i]]--;
            }
            mp.erase(A2[i]);
        }
    }

    for (auto x : mp)
    {
        while (x.second)
        {
            ans.push_back(x.first);
            x.second--;
        }
    }
    return ans;
}