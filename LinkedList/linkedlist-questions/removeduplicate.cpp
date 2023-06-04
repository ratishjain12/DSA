// from sorted linked list

Node *removeDuplicates(Node *head){
 // your code goes here
    Node *curr = head;
    while(curr->next!=NULL){
        if(curr->data == curr->next->data){
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }else{
            curr = curr->next;
        }
    }
    return head;
}


// from unsorted linked list
Node * removeDuplicates( Node *head) {
    // your code goes here
    map<int,int>mp;
    Node *curr = head;
    mp[curr->data] = 1;
    Node *prev = curr;
    curr = curr->next;
    while(curr!=NULL){
        if(mp[curr->data]){
            prev->next = curr->next;
            free(curr);
        }else{
            mp[curr->data] = 1;
            prev=curr;
        }
        curr = prev->next;
    }
    
    return head;
}