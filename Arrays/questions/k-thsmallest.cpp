#include<iostream>
#include <priority_queue>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    priority_queue<int>pq;
    for(int i = l;i<=r;i++){
        pq.push(arr[i]);
    }
    while(pq.size()>k){
        pq.pop();
    }
    return pq.top();
}
