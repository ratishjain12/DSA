int findFloor(vector<long long> v, long long n, long long x){

    // Your code here
    int l = 0,h = n-1;
    while(l<=h){
        int mid = l + (h-l)/2;
        if(v[mid] == x){
            return mid;
        }
        if(v[mid]>x){
            h = mid-1;
        }else if(v[mid]<x){
            l = mid+1;
        }
    }
    return h;

}
