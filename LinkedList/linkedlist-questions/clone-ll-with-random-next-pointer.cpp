Node *copyList(Node *head){
    //Write your code here
    Node *curr = head;
    while(curr){ // linking duplicate nodes with main(mapping nodes)
        Node *temp = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
    
    curr = head;
    while(curr){ // setting random pointer
        
        curr->next->arb = (curr->arb!=NULL) ? curr->arb->next:NULL; 
        
        
        curr = curr->next->next;
    }
    
    Node *org  = head;
    Node *copy = head->next;
    Node *temp = copy;
    
    while(org){ // separating the duplicate linked list
        org->next = org->next->next;
        if(copy->next){
            copy->next = copy->next->next;
        }
        org = org->next;
        copy = copy->next;
    }
    
    return temp;
    
}
