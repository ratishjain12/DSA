pair<long, long> findRepeating(long *arr, int n){
    //code here
    if(n - (arr[n-1] - arr[0]) == 1){ // if there is no repeatition
        return {-1,-1};
    }
    
    int l = 0;
    int h = n-1;
    while(l<=h){
        int mid = (l+h)/2;
        if(arr[mid] >= mid+1){
            l = mid+1;
        }else{
            h = mid-1;
        }
    }
    
    
    return {arr[l],n-(arr[n-1] - arr[0])};
}