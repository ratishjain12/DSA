#include<iostream>
#include<vector>
using namespace std;

string minWindow(string s, string t) {
    if(s.length() == 0 || t.length() == 0 || s.length()<t.length()) return "";
    vector<int>v(256,0);
    for(int i = 0;i<t.length();i++){
        v[t[i]]++;
    }
    int start=0,end=0,ans_start=0;
    int min_length=INT_MAX;
    int count=0;
    while(end<s.length()){
        if(v[s[end]]>0){
            count++;
        }
        v[s[end]]--;
        while(count == t.length()){
            if(min_length>end-start+1){
                min_length = end-start+1;
                ans_start = start;
            }
            v[s[start]]++;
            if(v[s[start]]>0){
                count--;
            }
            start++;
        }
        end++;
    }
    if(min_length == INT_MAX){
        return "";
    }
    return s.substr(ans_start,min_length);
}

int main(){
  string s = "ADOBECODEBANC";
  string t = "ABC";
  cout<<minWindow(s,t);

  return 0;
}
