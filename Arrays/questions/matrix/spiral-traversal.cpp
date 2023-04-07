vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int n = matrix[0].size(); // columns
    int m = matrix.size();    // rows
    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = m - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]); // top is constant
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]); // right column is constant
        }
        right--;
        if (top <= bottom) // as top increased we check for overflow
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]); // bottom constant
            }
            bottom--;
        }
        if (left <= right) // as right is decreased we check for overflow
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]); // left constant
            }
            left++;
        }
    }
    return ans;
}