
#include<iostream>
using namespace std;


//T.C = O(N) S.C = O(N)

long long trappingWater(int arr[], int n){
    // code here
    int lmax[n];
    int rmax[n];
    lmax[0] = arr[0];
    rmax[n-1] = arr[n-1];

    for(int i = 1;i<n;i++){
        lmax[i] = max(lmax[i-1],arr[i]); // calculate max at each point from left
    }
    for(int i = n-2;i>=0;i--){
        rmax[i] = max(rmax[i+1],arr[i]);// calculate max at each point from right
    }
    long res = 0;
    for(int i = 0;i<n;i++){
        int waterlevel = min(lmax[i],rmax[i]); //  max water to calculate water level
        res+=waterlevel-arr[i]; // amount of trapped
    }
    return res;
}


// another approach T.C = O(N) S.C = O(1)

long long trappingWater(int arr[], int n){
    // code here
    int l = 0,r = n-1;
    long long res = 0,ml = 0,mr = 0;
    while(l<=r){
        if(arr[l]<=arr[r]){
            if(arr[l]>=ml){
                ml = arr[l];
            }else{
               res+=ml-arr[l];
            }
            l++;
        }else{
            if(arr[r]>=mr){
                mr= arr[r];
            }else{
                res+=mr-arr[r];
            }
            r--;
        }
    }
    return res;
}
