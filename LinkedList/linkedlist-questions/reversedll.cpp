Node* reverseDLL(Node * head)
{
    //Your code here
    Node *temp = NULL;
    Node *curr = head;
    while(curr){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if(temp!=NULL){
        head = temp->prev;
    }
    return head;
}
