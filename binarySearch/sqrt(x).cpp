int mySqrt(int x) {

    if(x == 0) return 0;
    long long l = 1;
    long long h = x;
    int ans = 1;
    while(l<=h){
        long long mid = (l+h)/2;
        if(mid*mid <= x){
            ans = mid;
            l = mid+1;
        }else{
            h = mid-1;
        }
    }

    return ans;
}