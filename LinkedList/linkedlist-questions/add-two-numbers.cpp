Node *reverse(Node *head){
    Node *curr = head;
    Node *prev = NULL;
    while(curr){
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    
    return prev;
}

void insert(Node *&head,Node *&tail, int data){
    Node *temp = new Node(data);
    
    if(head == NULL){
        head = tail = temp;
    }else{
        tail->next = temp;
        tail = tail->next;
    }
}
Node *add(Node *first,Node *second){
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    while(first != NULL && second != NULL){
        int sum = carry + first->data + second->data;
        int digit = sum%10;
        
        insert(ansHead,ansTail,digit);
        carry = sum/10;
        first = first->next;
        second = second->next;
    }
    
    while(first != NULL){
        int sum = carry + first->data;
        int digit = sum%10;
        
        insert(ansHead,ansTail,digit);
        carry = sum/10;
        first = first->next;
    }
    
    while(second!=NULL){
        int sum = carry + second->data;
        int digit = sum%10;
        
        insert(ansHead,ansTail,digit);
        carry = sum/10;
        second = second->next;
    }
    
    while(carry != 0){
        int sum = carry;
        int digit = sum%10;
        insert(ansHead,ansTail,digit);
        carry = sum/10;
    }
    return ansHead;
}


struct Node* addTwoLists(struct Node* first, struct Node* second){
    // code here
    Node *firstList = reverse(first); // reverse first list
    Node *secondList = reverse(second);// reverse second list
    
    Node *ansHead = add(firstList,secondList);
    ansHead = reverse(ansHead);// reverse ans list
    return ansHead;
}