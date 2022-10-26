
#include<iostream>
#include<vector>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(),a.end());
        long mini = INT_MAX;
        for(int i = 0;i+m-1<n;i++){
            long diff = a[i+m-1] - a[i];
            mini = min(mini,diff);
        }
        return mini;
}
