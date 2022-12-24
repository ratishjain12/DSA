#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kLargest(int arr[], int n, int k)
{
    // code here
    vector<int> ans;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (k--)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int kthLargest(int arr[], int n, int k)
{
    // code here
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    return pq.top();
}