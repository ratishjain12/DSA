vector<int> findPairs(int arr[], int n)
{
    // code here
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int check = 0 - arr[i];
        if (mp.find(check) != mp.end())
        {
            if (check < 0)
            {
                ans.push_back(check);
                ans.push_back(0 - check);
            }
            else
            {
                ans.push_back(0 - check);
                ans.push_back(check);
            }
        }
        mp[arr[i]]++;
    }
    return ans;
}