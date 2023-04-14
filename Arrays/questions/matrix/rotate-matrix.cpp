// clock-wise (transpose + reverse rows)
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

// anti-clockwise(transpose + reverse columns)
void rotateby90(vector<vector<int>> &matrix, int n)
{
    // code here
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i + 1; j < matrix[0].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    int column = 0;
    while (column < n)
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