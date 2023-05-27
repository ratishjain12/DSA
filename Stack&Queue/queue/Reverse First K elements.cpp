void reverse(queue<int>&q,int k){
    if(k == 0){
        return;
    }
    
    int temp = q.front();
    q.pop();
    reverse(q,k-1);
    q.push(temp);
}
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    
    reverse(q,k);
    
    int itemLeft = q.size() - k;
    while(itemLeft){
        q.push(q.front());
        q.pop();
        itemLeft-=1;
    }
    
    return q;
}