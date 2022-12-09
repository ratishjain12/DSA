#include <iostream>
#include <vector>
#include <stack>
using namespace std;
string removeKdigits(string S, int k)
{
    stack<char> st;
    string ans;
    for (char c : S)
    {
        while (!st.empty() && k > 0 && st.top() > c)
        {
            st.pop();
            k--;
        }
        if (!st.empty() || c != '0')
        {
            st.push(c);
        }
    }
    while (!st.empty() && k > 0)
    {
        st.pop();
        k--;
    }
    if (st.empty())
    {
        return "0";
    }

    while (!st.empty())
    {
        ans.insert(ans.begin(), st.top());
        st.pop();
    }
    return ans;
}