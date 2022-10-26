
#include<iostream>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
   vector<vector<int>>res;
   sort(intervals.begin(),intervals.end());
   if(intervals.size() == 1){
       return intervals;
   }
   res.push_back(intervals[0]);
   for(int i = 1;i<intervals.size();i++){
       if(res.back()[1] >= intervals[i][0]){
           res.back()[1] = max(res.back()[1],intervals[i][1]);
       }else{
           res.push_back(intervals[i]);
       }
   }
   return res;
}
