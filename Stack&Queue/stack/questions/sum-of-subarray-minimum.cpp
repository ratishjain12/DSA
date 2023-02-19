// very tricky question
int sumSubarrayMins(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    int leftMin[n];
    int rightMin[n];
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            leftMin[i] = i + 1;
        }
        else
        {
            leftMin[i] = i - st.top();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            rightMin[i] = n - i;
        }
        else
        {
            rightMin[i] = st.top() - i;
        }

        st.push(i);
    }

    long long int res = 0;
    for (int i = 0; i < n; i++)
    {

        long long prod = (leftMin[i] * rightMin[i]);
        long long net = arr[i] * prod;
        res = (res + net) % mod;
    }
    return res;
}