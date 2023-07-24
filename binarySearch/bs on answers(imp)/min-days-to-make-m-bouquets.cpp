// to make  m bouquets you need k adjacent flowers
// and you are given bloomDay of each flower and flower can only be included in bouquet if its bloomday is already occured
// range for binary search will be min to max of the array as to atleast bloom one flower we will need the minimum from array
bool isPossible(vector<int>&bloomDay,int m, int k,int n,int day){
    int cnt = 0;
    int numberOfBouquets = 0;
    for(int i = 0;i<n;i++){
        if(bloomDay[i]<=day){
            cnt++;
        }else{
            numberOfBouquets += cnt/k;
            cnt=0;
        }
    }

    numberOfBouquets+=cnt/k;
    if(numberOfBouquets>=m) return true;
    return false;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();

    if((long)m*k > n){
        return -1;
    }

    int mini = bloomDay[0];
    int maxi = bloomDay[0];
    for(int i = 1;i<n;i++){
        mini = min(mini,bloomDay[i]);
        maxi = max(maxi,bloomDay[i]);
    }

    int l = mini;
    int h = maxi;

    int ans = h;
    while(l<=h){
        int mid = (l+h)/2;
        if(isPossible(bloomDay,m,k,n,mid)){
                ans = mid;
                h = mid - 1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}