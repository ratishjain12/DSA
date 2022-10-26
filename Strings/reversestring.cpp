#include <iostream>
using namespace std;

void reverse(string&s1,int i,int j){
  while(i<=j){
    swap(s1[i],s1[j]);
    i++;
    j--;
  }
}
int main(){
  string s1 = "hello";
  reverse(s1,0,s1.length()-1);
  cout<<s1;
  return 0;
}
