// square a number without *,/,% or POW()

// brute force

int square(int n){
    if(n<0){
        n = -n;
    }
    int res = n;
    for(int i = 1;i<n;i++){
        res+=n;
    }
    return res;
}


// bit manipulation approach
// suppose we want to square a number 5
// we can write 5^2 = 5 * (2^2 + 2^0)
// i.e - (5 << 2) + (5 << 0)

int squareNumber(int n){
    if(n < 0){
        n = -n;
    }
    int target = n;
    int res = 0;
    while(target>0){
        int i = 1;
        while((1<<i)<= target){
            i++;
        }
        i--;
        res += (n<<i);
        target = target - (1<<i);
    }
    return res;
}
