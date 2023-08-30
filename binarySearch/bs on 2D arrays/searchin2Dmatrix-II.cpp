//row and column are sorted 
//but first element of row is not necessarily greater than last of previous row
bool search(vector<vector<int>> matrix, int n, int m, int x)
{
    // code here

    int i = 0;
    int j = matrix[0].size() - 1;
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == x)
            return true;
        if (matrix[i][j] < x)
            i++;
        else
            j--;
    }
    return false;
}