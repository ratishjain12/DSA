

#include<iostream>
using namespace std;



int minJumps(int arr[], int n){
  int farthest = 0,end = 0,jumps = 0;
  if(n == 0){
      return 0;
    }

  for(int i =0;i<n-1;i++){
    farthest = max(farthest,arr[i]+i);
    if(i == end){
        end = farthest;
        jumps++;
    }

}
if(end<n-1) return -1;
return jumps;
}
