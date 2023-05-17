int countDigits(int n){
    //Your code here
    if(n == 0){
        return 0;
    }
    int digits = 0;
    digits = 1 + countDigits(n/10);
    return digits;
}