ListNode* removeNthFromEnd(ListNode* head, int n) {
   ListNode * start = new ListNode();
    start -> next = head; //dummy node
    ListNode *fast = start;
    ListNode *slow = start;

    for(int i = 1;i<=n;i++){
        fast = fast->next;
    }
    while(fast&&fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return start->next;
}
