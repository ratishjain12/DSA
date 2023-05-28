int reverse(int x) {
    long long sum = 0;
    while(x){
        sum = sum*10 + x%10;
        x = x/10;
    }
    return sum;
}
