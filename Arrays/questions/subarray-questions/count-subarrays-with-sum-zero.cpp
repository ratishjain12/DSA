long long int findSubarray(vector<long long int> &arr, int n)
{
    // code here
    int cnt = 0;
    map<int, int> mp;
    mp[0] = 1;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        cnt += mp[pre_sum];
        mp[pre_sum]++;
    }
    return cnt;
}