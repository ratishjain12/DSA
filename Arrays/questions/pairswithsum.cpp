#include<iostream>
#include<vector>
using namespace std;

/*
Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both
arrays whose sum is equal to X.
*/

vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
{
    // Your code goes here
    vector<pair<int,int>>ans;
    map<int,int>mp;
    for(int i=0;i<N;i++){
        mp[A[i]]++;
    }
    for(int i = 0;i<M;i++){
        if(mp.find(X - B[i])!= mp.end()){
            ans.push_back({X-B[i],B[i]});
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
