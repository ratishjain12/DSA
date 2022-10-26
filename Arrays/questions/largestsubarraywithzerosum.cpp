
#include<iostream>
#include<vector>
using namespace std;

int maxLen(vector<int>&A, int n)
    {
        // Your code here
        unordered_map<int,int>mp;
        int maxlen = 0;
        mp[0] = -1;
        int pre_sum = 0;
        for(int i = 0;i<n;i++){
            pre_sum+=A[i];
            if(mp.find(pre_sum) != mp.end()){
                if(i-mp[pre_sum]>maxlen){
                    maxlen = i-mp[pre_sum];
                }
            }else{
                mp[pre_sum] = i;
            }
        }
        return maxlen;
}
