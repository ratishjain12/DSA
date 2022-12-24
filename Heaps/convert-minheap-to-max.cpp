#include <iostream>
using namespace std;

void heapify(vector<int> &arr, int i, int n)
{
    int li = 2 * i + 1;
    int ri = 2 * i + 2;
    int greatest = i;
    if (li < n && arr[li] > arr[greatest])
    {
        greatest = li;
    }
    if (ri < n && arr[ri] > arr[greatest])
    {
        greatest = ri;
    }
    if (greatest != i)
    {
        swap(arr[greatest], arr[i]);
        heapify(arr, greatest, n);
    }
}
void convertMinToMaxHeap(vector<int> &arr, int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
}