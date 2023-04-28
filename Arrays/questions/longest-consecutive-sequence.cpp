int findLongestConseqSubseq(int arr[], int n)
{
    // Your code here
    unordered_set<int> st(arr, arr + n);
    int longest = 1;
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end()) // check for a number below if not then we count for continuous number after it
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}