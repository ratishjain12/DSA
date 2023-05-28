


long gcd(long long A,long long B){ // euclidean theorem
        if(B == 0){
            return A;
        }
        return gcd(B,A%B);
    }
long lcm(long long A, long long B){
        return (A*B)/gcd(A,B);
}
vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
      long long l = lcm(A,B);
      long long h = gcd(A,B);
      return {l,h};
}
