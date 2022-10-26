Node *middle(Node *head){
    Node *fast = head,*slow=head;
    Node *prevMid;
    while(fast&&fast->next){
        prevMid = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    return prevMid;
}
Node* deleteMid(Node* head)
{
    // Your Code Here
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node *mid = middle(head);
    Node *temp = mid->next;
    mid->next = mid->next->next;

    delete(temp);



    return head;

}
