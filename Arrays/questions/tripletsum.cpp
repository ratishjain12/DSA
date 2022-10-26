
#include <iostream>
using namespace std;


//TC = O(N^2) S.C = O(N)
bool find3Numbers(int a[], int n, int X)
{
    //Your Code Here
    for(int i = 0;i<n-2;i++){
        unordered_set<int>s;
        int t = X-a[i];
        for(int j = i+1;j<n;j++){
             if(s.find(t-a[j])!=s.end()){
                return true;
            }
            s.insert(a[j]);
        }
    }
    return false;

}

// TC = O(N^2) SC = O(1)
bool find3Numbers(int a[], int n, int X)
{
    //Your Code Here
    sort(a,a+n);
    for(int i = 0;i<n;i++){
        int l = i+1;
        int r = n-1;
        while(l<r){
            if(a[i]+a[l]+a[r] == X){
                return true;
            }
            if(a[i]+a[l]+a[r] < X){
                l++;
            }else{
                r--;
            }
        }
    }
    return false;

}
