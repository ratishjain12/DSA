vector<int> sumTriangles(const vector<vector<int>> &matrix, int n)
{
    // code here
    int uppersum = 0;
    int lowersum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            uppersum += matrix[i][j];
            lowersum += matrix[j][i];
        }
    }
    return {uppersum, lowersum};
}