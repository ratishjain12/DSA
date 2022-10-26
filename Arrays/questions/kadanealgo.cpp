#include<iostream>
using namespace std;


long long maxSubarraySum(int arr[], int n){

    // Your code here
    int res = arr[0];
    int curr_max = arr[0];
    for(int i = 1;i<n;i++){
        curr_max = max(arr[i],curr_max+arr[i]);
        res = max(res,curr_max);
    }
    return res;

}
int main(){
  int arr[] = {-1,-2,-3,-4};
  cout<<maxSubarraySum(arr,4);
  return 0;
}
