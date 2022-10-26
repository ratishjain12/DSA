int searchInsertK(vector<int>arr, int N, int k)
{
    // code here
    int l = 0,h = N-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(arr[mid] == k){
            return mid;
        }
        if(arr[mid]>k){
            h = mid-1;
        }else if(arr[mid]<k){
            l = mid+1;
        }
    }
    return l;
}
