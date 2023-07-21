// here based on true condition we are shrinking the window
// tricky question as we are to find minimum length of subarray with sum >= target
int minSubArrayLen(int target, vector<int>& nums) {
    int r = 0;
    int l = 0;
    int sum  = 0;
    int len =  INT_MAX;
    for(;r<nums.size();r++){
        sum+=nums[r];
        while(sum >= target){
            sum-=nums[l];
            len = min(len,r-l+1);
            l++;
        }
    
    }
    if(len == INT_MAX) return 0;
    return len;
}