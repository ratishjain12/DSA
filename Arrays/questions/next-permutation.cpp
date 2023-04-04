vector<int> nextPermutation(int N, vector<int> arr)
{
    // code here
    int ind = -1;
    for (int i = N - 2; i >= 0; i--) // finding break point
    {
        if (arr[i] < arr[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1) // if no break point means array is in descending order reverse it
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for (int i = N - 1; i >= ind; i--) // swap the next greater element with element and break point
    {
        if (arr[i] > arr[ind])
        {
            swap(arr[i], arr[ind]);
            break;
        }
    }

    sort(arr.begin() + ind + 1, arr.end()); // sorting the array after break point index
    return arr;
}
