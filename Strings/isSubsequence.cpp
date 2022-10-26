#include <iostream>
using namespace std;

bool isSubsequence(string&s1,string&s2){
    int i=0,j=0;
    while(i<s1.length() && j<s2.length()){
      if(s1[i] == s2[j]){
        i++;
        j++;
      }else{
        j++;
      }
    }
    return (i == s1.length());
}

int main(){
  string s1="geeks";
  string s2="geeksforgeeks";
  if(isSubsequence(s1,s2)){
    cout<<"yes";
  }else{
    cout<<"no";
  }
  return 0;
}
