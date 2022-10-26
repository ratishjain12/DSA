Node *rev(Node *head){
    Node *prev = NULL;
    Node *curr = head;
    while(curr!=NULL){
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr= next;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    //Your code here
    Node *slow =head,*fast = head->next,*dummy = head;
    if(head == NULL||head->next == NULL){
        return true;
    }
    while(fast&&fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = rev(slow->next);
    slow = slow->next;
    while(slow!=NULL){
        if(dummy->data!=slow->data) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}
