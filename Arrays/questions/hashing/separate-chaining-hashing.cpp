vector<vector<int>> separateChaining(int hashSize, int arr[], int sizeOfArray)
{
    // Your code here
    vector<vector<int>> separateChaining(hashSize);
    for (int i = 0; i < sizeOfArray; i++)
    {
        int key = arr[i] % hashSize;
        separateChaining[key].push_back(arr[i]);
    }
    return separateChaining;
}