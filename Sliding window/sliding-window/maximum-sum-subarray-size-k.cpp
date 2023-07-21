//Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.
long maximumSumSubarray(int K, vector<int> &arr , int N){
    // code here 
    long long sum = 0;
    int l = 0;
    int r = 0;
    long long maxSum = LONG_MIN;
    for(;r<N;r++){
        sum+=arr[r];
        while((r-l+1) > K){
            sum-=arr[l];
            l++;
        }
        maxSum = max(maxSum,sum);
    }
    
    return maxSum;
}