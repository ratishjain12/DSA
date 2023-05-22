// using stack

queue<int> rev(queue<int> q){
    // add code here.
    stack<int>s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    return q;
}


// using recursion
void reverse(queue<int>&q){
    if(q.empty()){
        return;
    }
    
    int temp = q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}
queue<int> rev(queue<int> q){
    // add code here.
    reverse(q);
    return q;
    
}


