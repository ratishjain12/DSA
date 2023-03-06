// bruteforce

// left rotate
void leftRotate(int arr[], int k, int n)
{
    // Your code goes
    k = k % n;
    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - (n - k)];
    }
}

// both left and right rotate optimal solution reversal algorithm

// right rotate
void reverse(vector<int> &arr, int i, int j)
{
    while (i <= j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}
void rotate(vector<int> &arr, int k)
{
    if (arr.size() == 0 || arr.size() < 2)
    {
        return;
    }
    k = k % arr.size();
    reverse(arr, 0, arr.size() - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, arr.size() - 1);
}

// left rotate
void reverse(vector<int> &arr, int i, int j)
{
    while (i <= j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}
void rotate(vector<int> &arr, int k)
{
    if (arr.size() == 0 || arr.size() < 2)
    {
        return;
    }
    k = k % arr.size();
    reverse(arr, 0, k - 1);
    reverse(arr, k, arr.size() - 1);
    reverse(arr, 0, arr.size() - 1);
}
