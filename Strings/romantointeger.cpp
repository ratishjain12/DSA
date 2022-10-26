#include<iostream>
#include<map>
using namespace std;


int romantoint(string &s){
  map<char,int>mp;
  mp['I'] = 1;
  mp['V'] = 5;
  mp['X'] = 10;
  mp['L'] = 50;
  mp['C'] = 100;
  mp['D'] = 500;
  mp['M'] = 1000;
  int sum = 0;
  for(int i=0;i<s.size();i++){
    if(mp[s[i]]<mp[s[i+1]]){
      sum-=mp[s[i]];
    }else{
      sum+=mp[s[i]];
    }
  }
  return sum;
}

int main(){
  string s = "MCMXCIV";
  cout<<romantoint(s);
  return 0;
}
