// algorithm
// count the length of the of the linked list with two heads separately C1 and C2
// traverse the list with longer length abs(C1-C2) times
// traverse both the list simulataneously until you find the name node

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int cnt1 = 0,cnt2=0;
    Node *curr1 = head1;
    Node *curr2 = head2;
    while(curr1){
        cnt1++;
        curr1 = curr1->next;
    }
    
    while(curr2){
        cnt2++;
        curr2 = curr2->next;
    }
    curr1 = head1;
    curr2 = head2;
    
    int diff = abs(cnt1-cnt2);
    
    if(cnt1 > cnt2){
        while(diff){
            curr1 = curr1->next;
            diff-=1;
        }
    }else{
        while(diff){
            curr2 = curr2->next;
            diff-=1;
        }
    }
    
    while(curr1 && curr2){
        if(curr1 == curr2){
            return curr1->data;
        }
        
        curr1= curr1->next;
        curr2= curr2->next;
    }
    
    return -1;
}