   int getDifference(Node* head1,Node* head2) {
     int len1 = 0,len2 = 0;
        while(head1 != NULL || head2 != NULL) {
            if(head1 != NULL) {
                ++len1; head1 = head1->next;
            }
            if(head2 != NULL) {
                ++len2; head2 = head2->next;
            }

        }
        return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
    }
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        int diff = getDifference(head1,head2);
        if(diff < 0)
            while(diff++ != 0) head2 = head2->next;
        else while(diff-- != 0) head1 = head1->next;
        while(head1 != NULL) {
            if(head1 == head2) return head1;
            head2 = head2->next;
            head1 = head1->next;
        }
        return head1;
    }
