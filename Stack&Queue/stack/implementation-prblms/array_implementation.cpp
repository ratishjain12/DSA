#include <iostream>
using namespace std;

class Stack{
private:
  int top;
  int cap;
  int *arr;

public:

  Stack(int c){
    top = -1;
    cap = c;
    arr = new int[c];
  }

  void push(int x){
    if(top == cap-1){
      cout<<"Stack overflow";
    }
    top++;
    arr[top] = x;
  }

  int pop(){
    if(top == -1){
      cout<<"Stack underflow";
    }
    int p = arr[top];
    top--;
    return p;
  }

  int peek(){
    return arr[top];
  }
  bool isEmpty(){
    if(top == -1){
      return true;
    }
    return false;
  }

};


int main(){
  Stack s(5);
  s.push(24);
  s.push(23);
  s.push(20);
  s.push(19);

  cout<<s.peek()<<'\n';
  s.pop();
  cout<<s.peek()<<'\n';
  if(s.isEmpty()){
    cout << "Stack is empty" << '\n';
  }else{
    cout << "Stack not empty" << '\n';
  }
  return 0;
}



// linked list implementation
