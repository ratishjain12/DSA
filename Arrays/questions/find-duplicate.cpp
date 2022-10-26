
#include<iostream>
#include<vector>;
using namespace std;


int findDuplicate(vector<int>& nums) {

        int i = 0;
        while(i<nums.size()){
            int correct = nums[i]-1;
            if(nums[i] != nums[correct]){ // if [0,N] correct = nums[i] else if [1,N] correct = nums[i]-1;
                swap(nums[i],nums[correct]);
            }else{
                i++;
            }
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != i+1){ //if [0,N] nums[i] != i else if [1,N] nums[i]!= i+1;
                return nums[i];
            }
        }
        return -1;
}
