#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    priority_queue<pair<int, int>> pq;
    vector<int> ans;
    for (auto ele : arr)
    {

        pq.push({abs(x - ele), ele});

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
    sort(ans.begin(), ans.end());
    return ans;
}