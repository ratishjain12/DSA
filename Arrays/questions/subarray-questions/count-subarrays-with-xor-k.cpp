int subarraysWithXorK(vector<int> a, int k)
{
    int xor = 0;
    map<int, int> mp;
    mp[0] = 1;
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        xor = xor^a[i];
        int x = xor^k;
        count += mp[x];
        mp[xor]++;
    }
    return count;
}