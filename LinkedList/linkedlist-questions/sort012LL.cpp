Node* segregate(Node *head) {

    // Add code here
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node *temp = head;
    while(temp!=NULL){
        if(temp->data == 0){
            zeroCount++;
        }else if(temp->data == 1){
            oneCount++;
        }else if(temp->data == 2){
            twoCount++;
        }
        temp=temp->next;
    }

    temp = head;
    while(temp!=NULL){
        if(zeroCount!= 0){
            temp->data = 0;
            zeroCount--;
        }else if(oneCount!=0){
            temp->data = 1;
            oneCount--;
        }else if(twoCount!=0){
            temp->data = 2;
            twoCount--;
        }
        temp=temp->next;
    }
    return head;

}

//By changing Links
void insertAtEnd(Node *&tail,Node *curr){
    tail->next = curr;
    tail = tail->next;
}
Node* segregate(Node *head) {

    // Add code here
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;
    Node *curr = head;
    while(curr!=NULL){
        int value = curr->data;
        if(value == 0){
            insertAtEnd(zeroTail,curr);
        }else if(value == 1){
            insertAtEnd(oneTail,curr);
        }else if(value == 2){
            insertAtEnd(twoTail,curr);
        }
        curr=curr->next;
    }

       if(oneHead->next == NULL){
            zeroTail->next = twoHead->next;
        }else{
            zeroTail->next = oneHead->next;
        }
        oneTail->next = twoHead->next;
        twoTail->next = NULL;
        head = zeroHead->next;
        return head;

}
