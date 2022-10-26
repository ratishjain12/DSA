
struct node{
  int data;
  node *next;
  node(int x){
    data = x;
    next = NULL;
  }
}
node *insert(node *head,int pos,int x){
  node *temp = new node(x);
  node *curr;
  curr = head;
  if(pos == 1){
    temp->next = head;
    return temp;
  }
  for(int i=1;i<=pos-2&&curr!=NULL;i++){
    curr=curr->next;
  }
  temp->next = curr->next;
  curr->next = temp;
  return head;
}

node *del(node *head,int pos){
  node *curr;
  curr = head;
  if(pos == 1){
    head = head->next;
    return head;
  }
  for(int i=1;i<=pos-2&&curr!=NULL;i++){
    curr=curr->next;
  }
  curr->next = curr->next->next;
  return head;
}


void display(node *head){
  node *curr = head;
  while(curr!=NULL){
    cout<<curr->data<<" ";
    curr=curr->next;
  }
  }
}
