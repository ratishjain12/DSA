node *reverse (node *head, int k)
{
    // Complete this method
    node *prev = NULL;
    node *next;
    int c = 0;
    node *curr = head;
    while(curr!=NULL && c<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        c++;
    }
    if(next!=NULL){
        head->next = reverse(next,k);
    }
    return prev;
}
