
// sort envelopes based on width and if width is same sort based on height in descending
// then apply lis binary search on envelopes based on height
static int cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}
int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), cmp);

    vector<int> ans;
    ans.push_back(envelopes[0][1]);
    for (int i = 1; i < envelopes.size(); i++)
    {
        int ele = envelopes[i][1];
        if (ele > ans.back())
        {
            ans.push_back(ele);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), ele) - ans.begin();
            ans[index] = ele;
        }
    }
    return ans.size();
}