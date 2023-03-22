// return all meeting numbers a modification to N meetings in one room
static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
vector<int> maxMeetings(int n, vector<int> &start, vector<int> &end)
{
    vector<int> ans;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back({end[i], i});
    }

    sort(vec.begin(), vec.end(), cmp);
    int lastend = vec[0].first;
    ans.push_back(vec[0].second + 1);

    for (int i = 1; i < n; i++)
    {
        if (start[vec[i].second] > lastend)
        {
            lastend = vec[i].first;
            ans.push_back(vec[i].second + 1);
        }
    }
    sort(ans.begin(), ans.end()); // this is only to return answer in sorted way
    return ans;
}