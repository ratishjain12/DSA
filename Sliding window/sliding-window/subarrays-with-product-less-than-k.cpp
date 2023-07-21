// product should be strictly less than k
// return count of such subarrays
// at each step we induce x new subarrays of size r-l+1
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int l = 0;
    int r = 0;
    int product = 1;
    int cnt  = 0;
    for(;r<nums.size();r++){
        product = product*nums[r];
        while(product>=k && l<nums.size()){ // change window if product is >= k
            product/=nums[l];
            l++;
        }
        if(product<k)cnt+=r-l+1;
    }

    return cnt;
}