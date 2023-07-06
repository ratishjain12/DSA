// you need to return minimum capacity such that all the packages can be loaded on ship within d days
bool isPossible(vector<int>&weights,int days,int capacity){
    int load = 0;
    int ans = 1;
    int n = weights.size();
    for(int i = 0;i<n;i++){
        if(load + weights[i] > capacity){
            ans++;
            load = weights[i];
        }else{
            load += weights[i];
        }
    }
    if(ans<=days) return true;
    return false;
}
int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int l = INT_MIN;
    int h = 0;

    for(int i = 0;i<n;i++){
        l = max(l,weights[i]);
        h +=weights[i];
    }

    int ans = -1;
    while(l<=h){
        int mid = (l+h)/2;
        if(isPossible(weights,days,mid)){
            ans = mid;
            h = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}