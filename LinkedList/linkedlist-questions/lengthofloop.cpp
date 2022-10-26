int detectCycle(Node *head){
    Node *fast = head,*slow=head;
    int cnt=1;
    while(fast&&fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            slow = slow->next;
            while(slow!=fast){
                slow=slow->next;
                cnt++;
            }
            return cnt;
        }

    }


}
int countNodesinLoop(struct Node *head)
{
    // Code here

    int len = detectCycle(head);;
    return len;

}
