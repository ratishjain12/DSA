Node *revll(Node *head){
  Node *prev = NULL;
  Node *curr = head;
  while(curr){
    Node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}
