// we need to find minimum divisor such that after dividing the sum of the numbers is <= threshold;
// range will be from 1 to maximum element in the array

bool isPossible(vector<int>&nums,int threshold,int mid){
    int sum = 0;
    for(int i = 0;i<nums.size();i++){
        sum += ceil((double)nums[i]/mid);
    }
    if(sum <= threshold){
        return true;
    }

    return false;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    int l = 1;
    int h = INT_MIN;
    for(int i = 0;i<n;i++){
        h = max(h,nums[i]);
    }

    int ans = -1;
    while(l<=h){
        int mid = (l+h)/2;
        if(isPossible(nums,threshold,mid)){
            ans = mid;
            h = mid - 1;
        }else{
            l = mid+1;
        }
    }

    return ans;
}