#include<iostream>
#include<vector>
using namespace std;

/*
  Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
  you may return answer in any order;
*/

void helper(int i,int n,int k,vector<int>&subsets,vector<vector<int> >&ans){
  if(k == 0){
    ans.push_back(subsets);
    return;
  }
  if(k>n-i+1) return;
  if(i>n)return;
  // pick i-th element
  subsets.push_back(i);
  helper(i+1,n,k-1,subsets,ans);

  subsets.pop_back();
  //not pick i-th element
  helper(i+1,n,k,subsets,ans);
}

vector<vector<int> >combinations(int n,int k){
  vector<int>subsets;
  vector<vector<int> >ans;
  helper(1,n,k,subsets,ans);
  return ans;
}
