#include<iostream>
using namespace std;
bool isomorphic(string s1,string s2){
  if(s1.length()!=s2.length()) return false;
  int m1[256] = {0};
  int m2[256] = {0};
  for(int i=0;i<s1.length();i++){
    if(!m1[s1[i]] && !m2[s2[i]]){
      m1[s1[i]] = s2[i];
      m2[s2[i]] = s1[i];
    }else if(m1[s1[i]] != s2[i]) return false;
  }
  return true;
}

int main(){
  string s1 = "abc";
  string s2 = "xyy";
  cout<<isomorphic(s1,s2);
  return 0;
}
