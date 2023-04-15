static bool cmp(pair<int, int> a, pair<int, int> b)
{

    if (a.second == b.second)
    {
        return a.first <= b.first;
    }
    return a.second > b.second;
}
vector<int> sortByFreq(int arr[], int n)
{
    // Your code here
    vector<int> ans;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    vector<pair<int, int>> temp;

    for (int i = 0; i < n; i++)
    {
        temp.push_back({arr[i], mp[arr[i]]});
    }

    stable_sort(temp.begin(), temp.end(), cmp);

    for (auto it : temp)
    {
        ans.push_back(it.first);
    }
    return ans;
}