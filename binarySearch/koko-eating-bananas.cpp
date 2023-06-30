// Return the minimum integer k such that she can eat all the bananas within h hours.
// Koko can decide her bananas-per-hour eating speed of k
long totalHrs(vector<int>& piles,int bananaperhour){
    long ans = 0;
    for(int i = 0;i<piles.size();i++){
        ans+= ceil((double)piles[i]/bananaperhour);
    }
    return ans;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = INT_MIN;
    for(int i=0;i<piles.size();i++){
        high = max(high,piles[i]);
    }

    int ans = INT_MAX;
    while(low<=high){
        int mid = (low+high)/2;
        long totalhrs = totalHrs(piles,mid);
        if(totalhrs<=h){
            ans = min(ans,mid);
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    return ans;
}