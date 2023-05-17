#include<iostream>
using namespace std;

//Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

double myPow(double x, int n){
  if(n == 0){
    return 1;
  }
  if(n<0){
    x = 1/x;
    n = abs(n);
  }
  double temp = myPow(x,n/2);
  if(n%2 == 1){
    return temp*temp*x;
  }
  return temp*temp;
}

int main(){
  double x = 2.00000 ;
  int n = -2;
  cout<<myPow(x,n);
  return 0;
}
