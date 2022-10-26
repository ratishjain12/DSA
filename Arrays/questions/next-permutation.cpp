#include<iostream>
#include<vector>;
using namespace std;


void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int idx1;
    for(int i = n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            idx1 = i;
            break;
        }
    }
    int idx2;
    if(idx1<0){
        reverse(nums.begin(),nums.end());
    }else{
        for(int i = n-1;i>idx1;i--){
            if(nums[i]>nums[idx1]){
                idx2 = i;
                break;
            }
        }
        swap(nums[idx1],nums[idx2]);
        reverse(nums.begin()+idx1+1,nums.end());
    }
}
