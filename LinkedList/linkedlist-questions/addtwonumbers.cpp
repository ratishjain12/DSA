/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    int carry = 0;
    while(l1 || l2 || carry){
        int sum = 0;
        if(l1!=NULL){
            sum+=l1->val;
            l1 = l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2 = l2->next;
        }
        sum+=carry;
        carry = sum/10;
        ListNode  *node = new ListNode(sum%10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}
