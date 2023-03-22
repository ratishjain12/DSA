static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back({start[i], end[i]});
    }

    sort(vec.begin(), vec.end(), cmp);
    int lastend = vec[0].second;
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (vec[i].first > lastend)
        {
            lastend = vec[i].second;
            res++;
        }
    }
    return res;
}