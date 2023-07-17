// we are given a array and we can do the operation of incrementing by 1
// we can do this operation k times
// return the max frequency of an element you can obtain doing this
int maxFrequency(vector<int>& nums, int k) {
    int l = 0;
    int r = 0;
    long long sum = 0;
    int len = 0;
    sort(nums.begin(),nums.end());

    for(;r<nums.size();r++){
        sum+=nums[r];
        while((long long)nums[r] * (r-l+1) > sum + k){
            sum-=nums[l];
            l++;
        }
        len = max(len,r-l+1);
    }
    return len;
}