int findKRotation(int arr[], int n) {
    // code here
    int l = 0;
    int h = n-1;
    if(arr[l]<=arr[h]){
        return 0;
    }
    while(l<=h){
        int mid = (l+h)>>1;
        if(arr[mid]>arr[mid+1]){
            return mid+1;
        }
        if(arr[mid]<arr[mid-1]){
            return mid;
        }
        if(arr[l]<=arr[mid]){
            l = mid+1;
        }else{
            h = mid-1;
        }
    }
    return -1;
}
