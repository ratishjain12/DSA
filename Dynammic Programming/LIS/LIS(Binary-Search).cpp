// most optimal solution for longest increasing subsequence
// for dry run checkout love babbar video
// if we find a greater element then last we simply add that element in ans
// else we find index for smallest number greater then the element in the ans and
// replace that with the element
int longestSubsequence(int n, int a[])
{
    // your code here
    if (n == 0)
    {
        return 0;
    }
    vector<int> ans;
    ans.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] > ans.back())
        {
            ans.push_back(a[i]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }
    return ans.size();
}