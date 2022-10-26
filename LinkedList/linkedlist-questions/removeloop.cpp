void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    Node *slow = head,*fast = head;
    while(fast&&fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(slow!=fast) return;
    slow = head;
    if(slow!=fast){
        while(slow->next!=fast->next){
         slow = slow->next;
         fast = fast->next;
        }
    }else{
        while(fast->next!=slow){
            fast = fast->next;
        }
    }

    fast->next = NULL;
}
