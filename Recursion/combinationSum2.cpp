#include<iostream>
#include<vector>
using namespace std;

/*
  Problem Statement: Find all possible subsets combination of an array that is equal to the given sum.
  Note that reusing the numbers is not allowed.
*/


void help(int i,vector<int>&nums,vector<int>&subset,vector<vector<int>>&ans,int &sumTillNow,int &target){

  if(sumTillNow>target) return;

  if(sumTillNow == target){
    ans.push_back(subset);
    return;
  }
  if(i == nums.size()) return;



  //pick i-th element
  sumTillNow+=nums[i];
  subset.push_back(nums[i]);

  help(i+1,nums,subset,ans,sumTillNow,target);
  sumTillNow-=nums[i]; //backtracking
  subset.pop_back();  //backtracking

  while(i+1<nums.size() && nums[i] == nums[i+1]) i++;
  //skip i-th element
  help(i+1,nums,subset,ans,sumTillNow,target);
}


vector<vector<int>>combinationSum2(vector<int>&nums,int target){
  sort(nums.begin(),nums.end());
  vector<vector<int>>ans;
  int sumTillNow = 0;
  vector<int>subset;
  help(0,nums,subset,ans,sumTillNow,target);
  return ans;
}
