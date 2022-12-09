#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> asteroidCollision(int N, vector<int> &asteroids)
{
    // code here
    vector<int> ans;
    stack<int> s;
    for (int val : asteroids)
    {
        if (val > 0)
        {
            s.push(val);
        }
        else
        {
            while (!s.empty() && s.top() > 0 && s.top() < -val)
            {
                s.pop();
            }
            if (!s.empty() && s.top() == -val)
            {
                s.pop();
            }
            else if (!s.empty() && s.top() > -val)
            {
            }
            else
            {
                s.push(val);
            }
        }
    }

    while (!s.empty())
    {
        ans.insert(ans.begin(), s.top());
        s.pop();
    }
    return ans; 
}