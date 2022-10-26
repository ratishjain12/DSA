
#include<iostream>
using namespace std;


/*
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is 
killed in circle in a fixed direction.
*/


int j(int n,int k){                       // this function block returns indexing with 0 as starting
    if(n == 1) return 0;
    int x = j(n-1,k);
    int y = (x+k)%n;
    return y;
}
int josephus(int n, int k)
{
  int ans = j(n,k);
  return ans+1; // for zero based indexing simply return ans else ans+1
}
