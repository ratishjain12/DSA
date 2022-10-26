#include<iostream>
#include<vector>
using namespace std;




vector<int> leaders(int a[], int n){
        // Code here
        vector<int>ans;
        ans.push_back(a[n-1]);
        for(int i=n-2;i>=0;i--){
            if(a[i]>=ans.back()){
                ans.push_back(a[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
