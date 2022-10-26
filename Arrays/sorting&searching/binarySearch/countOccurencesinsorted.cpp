int binarySearch(int arr[],int n,int k){
    int l = 0,h = n-1;
      while(l<=h){
          int mid = l + (h-l)/2;
          if(arr[mid] == k){
              return mid;
          }
          if(arr[mid] > k){
              h = mid-1;
          }else if(arr[mid]<k){
              l = mid+1;
          }
      }
      return -1;
}
int count(int arr[], int n, int x) {
    // code here
    int idx = binarySearch(arr,n,x);
    if(idx == -1){
        return 0;
    }
    int k = 1;
    int left = idx-1;
    while(left>=0 && arr[left] == x){
        k++;
        left--;
    }
    int right = idx+1;
    while(right<=n-1 && arr[right] == x){
        k++;
        right++;
    }
    return k;

}
