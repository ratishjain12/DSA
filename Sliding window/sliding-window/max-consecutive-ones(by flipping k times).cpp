int longestOnes(vector<int>& nums, int k) {
    int r = 0;
    int l = 0;
    int len = 0;
    int countZero = 0;
    for(;r<nums.size();r++){
        if(nums[r] == 0) countZero++;
        while(countZero>k){
            if(nums[l] == 0) countZero--;
            l++;
        }
        len = max(len,r-l+1);
    }

    return len;
}