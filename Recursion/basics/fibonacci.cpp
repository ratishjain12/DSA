int fibonacci(int n){
    //Your code here
    if(n <= 2){
        return 1;
    }
    int fibo = fibonacci(n-1) + fibonacci(n-2);
    return fibo;
}