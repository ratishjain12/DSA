// largest rect histogram code
int getMaxArea(int arr[], int n)
{
    // Your code here

    int rb[n];
    int lb[n];
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            rb[i] = n;
        }
        else
        {
            rb[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            lb[i] = -1;
        }
        else
        {
            lb[i] = st.top();
        }
        st.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int width = rb[i] - lb[i] - 1;
        int area = width * arr[i];
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

// maximal-rect using largest rect histo code
int maxArea(int M[MAX][MAX], int n, int m)
{
    // Your code here
    int heights[m];
    for (int i = 0; i < m; i++)
    {
        heights[i] = M[0][i];
    }
    int area = getMaxArea(heights, m);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
            {
                heights[j]++;
            }
            else
            {
                heights[j] = 0;
            }
        }
        area = max(area, getMaxArea(heights, m));
    }
    return area;
}