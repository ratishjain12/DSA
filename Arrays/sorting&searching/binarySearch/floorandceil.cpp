pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr,arr+n);
    // code here
    int l = 0,h = n-1;
    int c = -1,f = -1;
    while(l<=h){
        int mid = l + (h-l)/2;
        if(arr[mid] == x){
            return {arr[mid],arr[mid]};
        }
        if(arr[mid]>x){
            c = arr[mid];
            h = mid-1;
        }else if(arr[mid]<x){
            f = arr[mid];
            l = mid+1;
        }
    }

    return {f,c};
}
