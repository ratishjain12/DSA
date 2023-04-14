void interchangeRows(vector<vector<int>> &matrix)
{
    // code here
    int n = matrix.size();
    int m = matrix[0].size();
    int column = 0;
    while (column < m)
    {
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            swap(matrix[i][column], matrix[j][column]);
            i++;
            j--;
        }
        column++;
    }
}