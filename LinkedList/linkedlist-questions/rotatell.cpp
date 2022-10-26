/*
Calculate the length of the list.
Connect the last node to the first node, converting it to a circular linked list.
Iterate to cut the link of the last node and start a node of k%length of the list rotated list.
*/

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0){
        return head;
    }
    int length = 1;
    ListNode *temp = head;
    while(temp->next!=NULL){
        length++;
        temp = temp->next;
    }
    temp->next = head;
    k = k%length;
    int end = length-k;
    while(end--!=0){
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;
    return head;
}
