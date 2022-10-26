#include <iostream>
using namespace std;

bool isPal(string&s1){
  int i=0,j = s1.length()-1;
  while(i<=j){
    if(s1[i]!=s1[j]) return false;
    i++;
    j--;
  }
  return true;
}

int main(){
  string s1 = "abbab";
  if(isPal(s1)){
    cout<<"yes";
  }else{
    cout<<"no";
  }

  return 0;
}
