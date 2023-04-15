vector<vector<int>> multiplyMatrix(const vector<vector<int>> &a, const vector<vector<int>> &b)
{
    // code here
    int n1 = a.size();
    int m1 = a[0].size();
    int n2 = b.size();
    int m2 = b[0].size();
    vector<vector<int>> ans(n1, vector<int>(m2, 0));

    if (a[0].size() != b.size()) // check if columns in first matrix  == rows in second matrix
        return {{-1}};
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            for (int idx = 0; idx < n2; idx++)
            {
                ans[i][j] += a[i][idx] * b[idx][j];
            }
        }
    }
    return ans;
}