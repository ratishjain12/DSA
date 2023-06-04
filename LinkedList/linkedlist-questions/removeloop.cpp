    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(head == NULL || head->next == NULL){
            return;
        }
        Node *slow = head;
        Node *fast = head;
        Node *entry = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        if(slow == head){ // if slow and fast meet at head then move only fast 
            while(fast->next != slow){
                fast = fast->next;
            }
            fast->next = NULL;
        }else if(slow == fast){
            slow = head;
            while(slow->next != fast->next){
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL;
        }
        
    }