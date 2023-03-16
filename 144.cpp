Node *removeDuplicates(Node *head)
{
    if( head == NULL ){
        return NULL;
    }
    Node* curr = head;
    
    while( curr != NULL ){
        if((curr->next != NULL) && curr->data == curr->next->data ){
            //duplictae element k next element ka track rakhne ke liye
            Node* forward = curr->next->next;
            //element to delete
            Node* temp = curr->next;
            delete( temp );
            //curr ko duplicate ke next element se pint kardo
            curr->next = forward;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}
