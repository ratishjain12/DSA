#include <iostream>
#include <vector>
using namespace std;

vector<int> leaders(int a[], int n)
{
    // Code here
    vector<int> ans;
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] >= maxi)
        {
            ans.push_back(a[i]);
        }
        maxi = max(maxi, a[i]);
    }
    reverse(ans.begin(), ans.end()); // if answer to be returned in order of array
    return ans;
}
