#include<iostream>
using namespace std;

long long toh(int N, int from, int to, int aux) {
    // Your code here
    if(N == 0) return 0;
    int steps = 1;
    steps+= toh(N-1,from,aux,to);
    cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
    steps += toh(N-1,aux,to,from);
    return steps;
}

int main(){
  cout<<toh(2,1,3,2);
  return 0;
}
