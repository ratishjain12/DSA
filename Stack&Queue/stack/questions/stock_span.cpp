#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> calculateSpan(int price[], int n)
{
    // Your code here
    vector<int> ans(n);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && price[s.top()] <= price[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - s.top();
        }
        s.push(i);
    }

    return ans;
}