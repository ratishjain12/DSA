static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int activitySelection(vector<int> start, vector<int> end, int n)
{
    // Your code here
    vector<pair<int, int>> activity;
    for (int i = 0; i < n; i++)
    {
        activity.push_back({start[i], end[i]});
    }

    sort(activity.begin(), activity.end(), cmp);

    int count = 1;
    int ActivityEnd = activity[0].second;

    for (int i = 1; i < n; i++)
    {
        if (activity[i].first > ActivityEnd)
        {
            count++;
            ActivityEnd = activity[i].second;
        }
    }
    return count;
}