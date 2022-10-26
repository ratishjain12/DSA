
#include<iostream>
#include<vector>
using namespace std;
//Given a binary array nums, return the maximum number of consecutive 1's in the array.

int findMaxConsecutiveOnes(vector<int>& nums) {
     int maxi = INT_MIN;
     int cnt = 0;
     for(int i = 0;i<nums.size();i++){
         if(nums[i] == 1){
             cnt++;
         }else{
             cnt = 0;
         }
         maxi = max(maxi,cnt);
     }
     return maxi;
 }
