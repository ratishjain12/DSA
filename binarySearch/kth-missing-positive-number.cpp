
// brute force -
int findKthPositive(vector<int>& arr, int k) {
    for(int i = 0;i<arr.size();i++){
        if(arr[i] <= k) k++;
        else break;
    }
    return k;
}

// binary search solution
int findKthPositive(vector<int>& arr, int k) {
    int l = 0;
    int h = arr.size()-1;
    while(l<=h){
        int mid = (l+h)/2;
        int missing = arr[mid] - (mid+1); // how missing till each index
        if(missing<k){
            l = mid+1;
        }else{
            h = mid-1;
        }
    }

    return l+k; // return  low + k (as k-missing equals to more missing needed so k - (arr[high] - high - 1) so arr[high] + k -arr[high]+ high + 1 therefore low+1 = k;
}