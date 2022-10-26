


#include<iostream>
#include<vector>
using namespace std;

void insert_at_bottom(int x,stack<int>&St){
        if(St.size() == 0){
            St.push(x);
        }else{
            int top = St.top();
            St.pop();
            insert_at_bottom(x,St);
            St.push(top);
        }
        return;

    }
    void reverseStack(stack<int>St){
        if(St.size()>1){
            int x = St.top();
            St.pop();
            reverseStack(St);
            insert_at_bottom(x,St);
        }
        return;
    }

    vector<int> Reverse(stack<int>St){

        vector<int>ans;
        if(St.size() == 0){
            return ans;
        }
        if(St.size() == 1){
            ans.push_back(St.top());
            return ans;
        }
        reverseStack(St);


        while(!St.empty())
       {
           ans.push_back(St.top());
           St.pop();
       }
        return ans;
    }
