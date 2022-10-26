#include <iostream>
using namespace std;
//Minimum characters to be added at front to make string palindrome

bool isPal(string&s1){
  int i=0,j = s1.length()-1;
  while(i<=j){
    if(s1[i]!=s1[j]) return false;
    i++;
    j--;
  }
  return true;
}

int minChar(string s){
  int cnt = 0;
  while(s.length()>0){
    if(isPal(s)){
      break;
    }else{
      cnt++;
      s.pop_back();
    }
  }
  return cnt;
}
int main(){
  string s = "ABC";
  cout<<minChar(s);

  return 0;
}
