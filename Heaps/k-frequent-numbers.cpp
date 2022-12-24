#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
vector<int> topK(vector<int> &nums, int k)
{
    // Code here
    unordered_map<int, int> mp;
    vector<int> ans;

    for (auto x : nums)
    {
        mp[x]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto i : mp)
    {
        pq.push({i.second, i.first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        ans.insert(ans.begin(), pq.top().second);
        pq.pop();
    }

    return ans;
}