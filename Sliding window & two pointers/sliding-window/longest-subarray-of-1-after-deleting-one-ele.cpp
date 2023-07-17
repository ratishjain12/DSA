// we are given a binary array 
// we need to find ;ongest subarray of 1's we can delete one item

//approach is allowing the window to have atmost 1 zero and finding largest subarray
// now we can return the size of largest subarray finding the lenght of subarray including one zero and subtracting one from it(len-1)
int longestSubarray(vector<int>& nums) {
    int countZero  = 0;
    int len = 0;
    int l = 0;
    for(int r = 0;r<nums.size();r++){
        if(nums[r] == 0) countZero++;
        while(countZero > 1){
            if(nums[l] == 0) countZero--;
            l++;
        }
        len = max(len,r-l+1);
    }
    return len-1;
}
