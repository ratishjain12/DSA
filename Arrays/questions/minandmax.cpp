
#include<iostream>
#include <pair>
using namespace std;




pair<long long, long long> getMinMax(long long a[], int n) {

    long long mini = INT_MAX;
    long long maxi = INT_MIN;
    for(int i = 0;i<n;i++){
        maxi = max(maxi,a[i]);
        mini = min(mini,a[i]);
    }
    return {mini,maxi};
}
