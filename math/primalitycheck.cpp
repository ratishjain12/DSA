// check whether a given is prime number or not

bool isPrime(int N){
//Your code here
    if(N == 0 || N == 1){
        return false;
    }
    for(int i = 2;i<=sqrt(N);i++){
        if(N%i == 0){
            return false;
        }
    }
    
    return true;
}