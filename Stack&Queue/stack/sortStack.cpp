#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void insert_at_correct(stack<int>&s,int x){
    if(s.size()==0 || x>s.top()){
        s.push(x);
    }else{
        int top = s.top();
        s.pop();
        insert_at_correct(s,x);
        s.push(top);
    }
}
void sort(stack<int>& s){
    if(s.size()>0){
        int x = s.top();
        s.pop();
        sort(s);
        insert_at_correct(s,x);
    }
}
int main(){
  stack<int>s;
  s.push(3);
  s.push(2);
  s.push(1);
  sort(s);
  while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
  }
  return 0;
}
