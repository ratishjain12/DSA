#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n)
{
    // Your code goes here
    for (int i = 0; i <= (n - 2) / 2; i++)
    {
        if (arr[i] < arr[2 * i + 1] || arr[i] < arr[2 * i + 2])
        {
            return false;
        }
    }
    return true;
}