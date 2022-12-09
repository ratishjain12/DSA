#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    // Your code here
    stack<long long> st;
    vector<long long> nge(n);

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i % n])
        {
            st.pop();
        }

        if (i < n)
        {
            if (!st.empty())
            {
                nge[i] = st.top();
            }
            else
            {
                nge[i] = -1;
            }
        }

        st.push(arr[i % n]);
    }
    return nge;
}