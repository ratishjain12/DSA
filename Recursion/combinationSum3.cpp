#include<iostream>
#include<vector>
using namespace std;

/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
  . Only numbers 1 through 9 are used.
  . Each number is used at most once.

Return a list of all possible valid combinations. The list must not contain the same combination twice,
and the combinations may be returned in any order.
*/

void help(int i,int k,int n,vector<int>&subset,vector<vector<int>>&ans,int &sumTillNow){

  if(sumTillNow>n) return;

  if(k == 0){
      if(sumTillNow == n){
          ans.push_back(subset);
          return;
      }
      return;
  }
  if(i == 10) return;



  //pick i-th element
  sumTillNow+=i;
  subset.push_back(i);

  help(i+1,k-1,n,subset,ans,sumTillNow);
  sumTillNow-=i; //backtracking
  subset.pop_back();  //backtracking

  //skip i-th element
  help(i+1,k,n,subset,ans,sumTillNow);

}


vector<vector<int>>combinationSum3(int k,int n){
  vector<vector<int>>ans;
  int sumTillNow = 0;
  vector<int>subset;
  help(1,k,n,subset,ans,sumTillNow);
  return ans;
}
