int lenOfLongSubarr(int a[], int n, int k)
{
    // Complete the function
    int maxLen = 0;
    map<int, int> mp;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += a[i];
        if (pre_sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        if (mp.find(pre_sum - k) != mp.end())
        {
            if (i - mp[pre_sum - k] > maxLen)
            {
                maxLen = i - mp[pre_sum];
            }
        }
        mp[pre_sum] = i;
    }
    return maxLen;
}