#include <iostream>
using namespace std;

int equilibriumPoint(long long a[], int n)
{

    int pos = -1, leftSum = 0, rightSum = 0;
    for (int i = 0; i < n; i++)
    {
        rightSum += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        rightSum -= a[i];
        if (leftSum == rightSum)
        {
            pos = i + 1;
            break;
        }
        leftSum += a[i];
    }
    return pos;
}
int main()
{
    long long arr[] = {1, 3, 5, 2, 2};
    int n = 5;
    cout << equilibriumPoint(arr, n);
    return 0;
}

// prefix sum and suffix sum approach

int equilibriumPoint(long long a[], int n)
{

    // Your code here
    int p[n];
    p[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        p[i] = p[i - 1] + a[i];
    }
    int total = p[n - 1];
    for (int i = 1; i < n - 1; i++)
    { // first element and last element cannot be equilibriumPoint
        int leftSum = 0, rightSum = 0;
        leftSum = p[i] - a[i];
        rightSum = total - p[i];
        if (leftSum == rightSum)
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    long long arr[] = {1, 3, 5, 2, 2};
    int n = 5;
    cout << equilibriumPoint(arr, n);
    return 0;
}

// approach
int equilibriumPoint(long long a[], int n)
{

    // Your code here
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += a[i];
    }
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum -= a[i];
        if (prefixSum == totalSum)
        {
            return i + 1;
        }
        prefixSum += a[i];
    }
    return -1;
}
