ListNode *detectCycle(ListNode *head) {
    ListNode *slow=head,*fast=head,*entry=head;
    while(fast&&fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            while(slow!=entry){
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;       
}
