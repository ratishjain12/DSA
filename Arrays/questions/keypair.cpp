

#include<iostream>
#include<unordered_set>
using namespace std;


/*
Given an array Arr of N positive integers and another number X. Determine whether or not there exist
two elements in Arr whose sum is exactly X.
*/


bool hasArrayTwoCandidates(int arr[], int n, int x) {
    // code here
    unordered_set<int>mp ;

    for(int i = 0;i<n;i++){
        if(mp.find(x - arr[i])!=mp.end()){
            return true;
        }
        mp.insert(arr[i]);

    }
    return false;
}
