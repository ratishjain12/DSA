#include <iostream>
using namespace std;

bool stringRotation(string&s1,string&s2){
  if(s1.length() != s2.length()) return false;
  return (s1+s1).find(s2)!= string::npos;
}

int main(){
  string s1 = "geeks";
  string s2 = "gseek";
  if(stringRotation(s1,s2)){
    cout<<"yes";
  }else{
    cout<<"no";
  }
  return 0;
}
