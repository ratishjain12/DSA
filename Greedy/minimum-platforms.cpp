int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    sort(arr, arr + n);
    sort(dep, dep + n);
    int ans = 0;
    int i = 1, platform = 1;
    int j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            platform++;
            i++;
        }
        else
        {
            platform--;
            j++;
        }
        ans = max(ans, platform);
    }
    return ans;
}