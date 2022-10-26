#include<iostream>
using namespace std;

string lps(string &s){
  int start = 0;
  int end = 1;
  for(int i=1;i<s.size();i++){
    //even
    int low = i-1;
    int high = i;
    while(low>=0 && high<s.size()&& s[high] == s[low]){
      if(high-low+1>end){
        start = low;
        end = high-low+1;
      }
      low--;
      high++;
    }
    //odd;
    low = i-1;
    high = i+1;
    while(low>=0 && high<s.size()&& s[high] == s[low]){
      if(high-low+1>end){
        start = low;
        end = high-low+1;
      }
      low--;
      high++;
    }
  }
  return s.substr(start,end);
}

int main(){
  string s = "ababba";
  cout<<lps(s);
  return 0;
}
