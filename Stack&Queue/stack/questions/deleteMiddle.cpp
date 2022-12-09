#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void delMiddle(stack<int>&s,int count,int n){
    if(count == n/2){
      s.pop();
      return;
    }
    int top = s.top();
    s.pop();
    delMiddle(s,count+1,n);
    s.push(top);

}

int main(){
  stack<int>s;
  s.push(3);
  s.push(2);
  s.push(1);
  delMiddle(s,0,s.size());
  while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
  }
  return 0;
}
