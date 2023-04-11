
#include <iostream>
#include <vector>
using namespace std;

int maxLen(vector<int> &A, int n)
{
    // Your code here
    unordered_map<int, int> mp;
    int maxlen = 0;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += A[i];
        if (pre_sum == 0)
            maxlen = max(maxlen, i + 1);
        if (mp.find(pre_sum) != mp.end())
        {
            if (i - mp[pre_sum] > maxlen)
            {
                maxlen = i - mp[pre_sum];
            }
        }

        mp[pre_sum] = i;
    }
    return maxlen;
}