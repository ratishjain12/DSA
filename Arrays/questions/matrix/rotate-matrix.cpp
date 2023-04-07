void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]); // making transpose of matrix
        }
    }

    for (int i = 0; i < n; i++) // reversing each row of the matrix
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}