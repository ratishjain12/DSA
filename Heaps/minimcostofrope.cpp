#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long minCost(long long arr[], long long n)
{
    // Your code here
    priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr + n);

    long long sum = 0;
    while (pq.size() >= 2)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a + b);
        sum += (a + b);
    }
    return sum;
}