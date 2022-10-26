#include <iostream>
#include <map>
using namespace std;

char maxOccur(string&s1){
  map<char,int>mp;
  int maxi = INT_MIN;
  for(int i=0;i<s1.length();i++){
    mp[s1[i]]++;
    maxi = max(maxi,mp[s1[i]]);
  }
  for(auto it:mp){
    if(it.second == maxi){
      return it.first;
    }
  }
  return '$';
}

int main(){
  string s1 = "geeksforgeeks";
  cout<<maxOccur(s1);
  return 0;
}
