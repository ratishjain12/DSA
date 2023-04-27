/*
   In parent array the indices is the value of the node and the element at
   that index is the parent of that node.

   for root node parent element is -1
*/

int findHeight(int N, int arr[])
{
    // code here
    int ans = 0;
    for (int i = 0; i < N; i++) // iterate over each element
    {
        int crr = i, height = 0;
        while (crr != -1) // for each element check depth till reaching root
        {
            height++; // increment height
            crr = arr[crr];
        }
        ans = max(ans, height); // store the maximum height
    }
    return ans;
}