int sumOfDigits(int n){
    //Your code here
    if(n == 0) return 0;
    int sum=0;
    sum+= n%10 + sumOfDigits(n/10);
    return sum;
}