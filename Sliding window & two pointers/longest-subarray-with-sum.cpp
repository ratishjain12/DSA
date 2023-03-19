// one approach
// takes space but solves for both positives and negatives in array
int lenOfLongSubarr(int a[], int n, int k)
{
    // Complete the function
    map<int, int> mp;
    int len = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == k)
        {
            len = max(len, i + 1);
        }
        if (mp.find(sum - k) != mp.end())
        {
            len = max(len, i - mp[sum - k]);
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    return len;
}

// note below solution works only if positive values are there
// two pointer approach
int lenOfLongSubarr(int a[], int n, int k)
{
    // Complete the function
    int i = 0;
    int j = 0;
    int len = 0;
    int sum = a[0];
    while (j < n)
    {
        while (i <= j && sum > k)
        {
            sum -= a[i];
            i++;
        }
        if (sum == k)
        {
            len = max(len, j - i + 1);
        }
        j++;
        if (j < n)
            sum += a[j];
    }
    return len;
}