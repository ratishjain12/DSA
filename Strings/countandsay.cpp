#include<iostream>
using namespace std;

string cns(int n){
  if(n==1) return "1";
  if(n==2) return "11";
  string s = "11";
  for(int i=3;i<=n;i++){
    int count = 1;
    string t = "";
    s+='$';
    for(int j=1;j<s.size();j++){
      if(s[j-1]!=s[j]){
        t+=to_string(count);
        t+=s[j-1];
        count=1;
      }else{
        count++;
      }
    }
    s=t;
  }
  return s;
}

int main(){
  int n;
  cout<<"Enter value of n: ";
  cin>>n;
  cout<<cns(n);
  return 0;
}
