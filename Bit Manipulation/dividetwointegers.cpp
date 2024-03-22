    long long divide(long long dividend, long long divisor) {
        //code here
        if(dividend == divisor) return 1;
        
        bool sign = true;
        if(dividend < 0 && divisor>=0) sign = false;
        if(dividend >=0 && divisor<0) sign=false;
        
        long long target = abs(dividend);
        long long d = abs(divisor);
        long long ans = 0;
        while(target >= d){
            int cnt = 0;
            while((d<<cnt) <= target){
                cnt++;
            }
            cnt--;
            ans+= 1 << cnt;
            target -= d<<cnt;
        }
        if(!sign) return -ans;
        return ans;
    }