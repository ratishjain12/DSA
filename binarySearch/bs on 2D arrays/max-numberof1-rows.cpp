int first(vector<int> arr)
{
    int l = 0;
    int h = arr.size() - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if ((arr[mid] == 0 || arr[mid - 1]) == 0 && arr[mid] == 1)
        {
            return mid;
        }
        if (arr[mid] < 1)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    return -1;
}
int maxOnes(vector<vector<int>> &mat, int N, int M)
{
    // your code here
    int maxi = 0;
    int rowindex;
    for (int i = 0; i < N; i++)
    {

        int index = first(mat[i]);
        if (index != -1 && M - index > maxi)
        {
            maxi = M - index;
            rowindex = i;
        }
    }
    return rowindex;
}
