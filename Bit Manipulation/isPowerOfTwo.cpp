// numbers which are power of 2 have only one set bit(1) in their binary representation
// therefore, count set bits and if its one then return true else return false
bool isPowerOfTwo(int n){
    int cnt = 0;
    while(n){
        n = n&(n-1);
        cnt++;
    }
    return cnt == 1;
}