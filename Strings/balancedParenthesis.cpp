#include <iostream>
#include<stack>
using namespace std;

bool ispar(string x)
{
    stack<char>s;
    for(int i=0;i<x.size();i++){
        if(x[i] == '{' || x[i]=='(' || x[i]=='['){
            s.push(x[i]);
        }else{
            if(s.empty()) return false;
            else if(x[i] == '}'){
                char top = s.top();
                s.pop();
                if(top == '[' || top == '('){
                    return false;
                }
            }else if(x[i] == ']'){
                char top = s.top();
                s.pop();
                if(top == '(' || top == '{'){
                    return false;
                }
            }else if(x[i] == ')'){
                char top = s.top();
                s.pop();
                if(top == '{' || top == '['){
                    return false;
                }
            }
        }
    }
    return s.empty() == 1;
}

int main(){
  string s = "([])";
  if(ispar(s)){
    cout<<"balanced";
  }else{
    cout<<"Not balanced";
  }
  return 0;
}
