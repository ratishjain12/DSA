Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    
    Node *head = NULL,*tail = NULL;
    
    Node *curr1 = head1;
    Node *curr2 = head2;

    if(head == NULL && tail == NULL){
        if(curr1->data <= curr2->data){
            head=tail=curr1;
            curr1 = curr1->next;
        }else{
            head=tail=curr2;
            curr2 = curr2->next;
        }
    }
    
    while(curr1 && curr2){
        if(curr1->data <=curr2->data){
            tail->next = curr1;
            tail = curr1;
            curr1 = curr1->next;
        }else{
            tail->next = curr2;
            tail = curr2;
            curr2 = curr2->next;
        }
    }
    
    if(curr1){
        tail->next = curr1;
    }
    if(curr2){
        tail->next = curr2;
    }
    
    return head;
    
}  