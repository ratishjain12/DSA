#include<iostream>
using namespace std;

string shuffle(string s,int indices[]){
  string res = s;
  for(int i=0;i<s.size();i++){
    res[indices[i]] = s[i];
  }
  return res;
}

int main(){
  string s = "codeleet";
  int indices[] = {4,5,6,7,0,2,1,3};
  cout<<shuffle(s,indices);
  return 0;
}
