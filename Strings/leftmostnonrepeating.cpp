#include<iostream>
#include <unordered_map>
#include <map>
using namespace std;

char leftnonrepeat(string&s){
  unordered_map<char,int> mp;
  for(int i=0;i<s.size();i++){
    mp[s[i]]++;
  }
  for(int i=0;i<s.size();i++){
    if(mp[s[i]] == 1){
      return s[i];
    }
  }
  return '$';
}

int main(){
  string s="xyzxxt";
  cout<<leftnonrepeat(s);
  return 0;
}
