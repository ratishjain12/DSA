bool detectloop(Node *head){
    // your code here
    Node *slow = head,*fast = head;
    if(head == NULL || head->next==NULL){
        return false;
    }
    while(fast&&fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }

    return false;
}
