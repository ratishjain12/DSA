// task is to find minimum possible distance which is maximum between two cows
// you are given k cows and you need to assign the cows the stalls
// Binary Search Hard Problem
// in leetcode question is 1552. Magnetic balls between two forces

bool isPossible(vector<int> &stalls,int minDistance,int cows){
    int cntCows = 1;
    int lastCowPos = stalls[0];
    for(int i = 0;i<stalls.size();i++){
        if(stalls[i] - lastCowPos >= minDistance){
            cntCows++;
            lastCowPos = stalls[i];
        }
        
        if(cntCows>= cows){
            return true;
        }
    }
    
    return false;
}

int solve(int n, int k, vector<int> &stalls) {

    // Write your code here
    
    sort(stalls.begin(),stalls.end());
    int l = 1;
    int h = INT_MIN;
    for(int  i = 0;i<n;i++){
        h = max(h,stalls[i]);
    }
    int ans = -1;
    while(l<=h){
        int mid = (l+h)/2;
        if(isPossible(stalls,mid,k)){
            ans = mid;
            l = mid+1;
        }else{
            h = mid-1;
        }
    }
    
    return ans;
}