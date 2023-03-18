void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* slow = head;
    Node* fast = head->next;
    //finding the middle of the Linked List
    while( fast != head && fast->next != head ){
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is the middle;
    //  pointing the heads given to the half LL
    *head1_ref = head;
    *head2_ref = slow->next;
    
    //pointing the end of first list to head1
    slow->next = *head1_ref;
    
    Node* curr = *head2_ref;
    while( curr->next != head){
        curr = curr->next;
    }
    curr->next = *head2_ref; //pointing the end of list 2 to the middle->next or slow->next, because slow is middle
}
