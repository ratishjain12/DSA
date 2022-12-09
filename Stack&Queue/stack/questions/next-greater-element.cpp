#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    // Your code here
    stack<long long> st;
    vector<long long> nge(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            nge[i] = st.top();
        }
        else
        {
            nge[i] = -1;
        }
        st.push(arr[i]);
    }
    return nge;
}