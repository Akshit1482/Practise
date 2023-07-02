Node* reverseDLL(Node * head)
{
    Node* forward = NULL;
    Node* back = NULL;
    Node* curr = head;
    
    while( curr != NULL ){
        forward = curr->next;
        curr->next = back;
        curr->prev = forward;
        back = curr;
        curr = forward;
    }
    return back;
}
