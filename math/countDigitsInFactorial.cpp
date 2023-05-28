// brute force wont work on large test case

int digitsInFactorial(int N){
    // code here
    long long fact = 1;
    while(N>0){
        fact = fact*N;
        N-=1;
    }

    long long cnt = 0;
    while(fact){
        cnt++;
        fact/=10;
    }
    return cnt;
}


// optimal

//number of digits in X = floor(log10(x)) + 1; formula
int digitsInFactorial(int N){
    // code here
    double res = 0;
    for(int i = 1;i<=N;i++){
        res+=log10(i);
    }
    return res+1;
}
