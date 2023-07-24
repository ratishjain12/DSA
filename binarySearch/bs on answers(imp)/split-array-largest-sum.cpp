// as book allocation problem
// you have to minimize the max sum by splitting array into k subrrays
// another similar problem is painter's partition

bool isPossible(vector<int>&nums,int n,int maxPages,int m){
    int cnt = 1;
    int sum = 0;
    for(int i = 0;i<n;i++){
        if(sum + nums[i] <= maxPages){
            sum+=nums[i];
        }else{
            cnt++;
            sum = nums[i];
        }
    }
    if(cnt<=m) return true;
    return false;
}
int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    int l = INT_MIN;
    int h = 0;
    for(int i = 0;i<nums.size();i++){
        l = max(nums[i],l);
        h+=nums[i];
    }

    int ans = -1;
    while(l<=h){
        int mid = (l+h)/2;
        if(isPossible(nums,n,mid,k)){
            ans = mid;
            h = mid - 1;
        }else{
            l = mid + 1;
        }

    }
    return ans;
}