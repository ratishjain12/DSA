#include <iostream>
using namespace std;

// O(1) space

long long trappingWater(int h[], int n)
{
    // code here
    int l = 0;
    int r = n - 1;
    int lmax = 0, rmax = 0;
    long long ans = 0;
    while (l < r)
    {
        lmax = max(lmax, h[l]);
        rmax = max(rmax, h[r]);
        if (lmax < rmax)
        {
            ans += lmax - h[l];
            l++;
        }
        else
        {
            ans += rmax - h[r];
            r--;
        }
    }
    return ans;
}

// T.C = O(N) S.C = O(N)

long long trappingWater(int arr[], int n)
{
    // code here
    int lmax[n];
    int rmax[n];
    lmax[0] = arr[0];
    rmax[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(lmax[i - 1], arr[i]); // calculate max at each point from left
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(rmax[i + 1], arr[i]); // calculate max at each point from right
    }
    long res = 0;
    for (int i = 0; i < n; i++)
    {
        int waterlevel = min(lmax[i], rmax[i]); //  max water to calculate water level
        res += waterlevel - arr[i];             // amount of trapped
    }
    return res;
}

// using stack
