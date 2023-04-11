int findSubArraySum(int arr[], int N, int k)
{
    // code here
    int cnt = 0;
    map<int, int> mp;
    mp[0] = 1;
    int pre_sum = 0;
    for (int i = 0; i < N; i++)
    {
        pre_sum += arr[i];
        int exclude = pre_sum - k;
        cnt += mp[exclude];
        mp[pre_sum]++;
    }
    return cnt;
}