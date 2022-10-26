#include <iostream>
using namespace std;

string revwords(string&s1){
  int i=0;
  int n = s1.length();
  string result;
  while(i<n){
    while(i<n && s1[i]==' ') i++;
    if(i>=n)break;
    int j = i+1;
    while(j<n&&s1[j]!=' ')j++;
    string sub = s1.substr(i,j-i);
    if(result.length() == 0)result = sub;
    else result = sub+" "+result;
    i=j+1;
  }
  return result;
}

int main(){
  string s1 = "How are you";
  cout<<revwords(s1);
  return 0;
}
