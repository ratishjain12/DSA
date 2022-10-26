int first(int arr[], int n , int k){ // first occurence
    int fst = -1;
    int l = 0,h = n-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(arr[mid] == k){
            fst = mid;
            h = mid-1;
        }
        if(arr[mid]>k){
            h = mid-1;
        }else if(arr[mid]<k){
            l = mid+1;
        }
    }
    return fst;
}

int last(int arr[], int n , int k){  // last occurence
    int lst = -1;
    int l = 0,h = n-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(arr[mid] == k){
            lst = mid;
            l= mid+1;
        }
        if(arr[mid]>k){
            h = mid-1;
        }else if(arr[mid]<k){
            l = mid+1;
        }
    }
    return lst;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
    int f = first(arr,n,x);
    int l = last(arr,n,x);
    return {f,l};
}
