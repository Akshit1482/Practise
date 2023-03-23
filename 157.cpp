void deleteNode(struct Node **head, int key)
{

    Node* temp = *head;
    
    // checking for key
    while( temp->next->data != key ){
        temp = temp->next;
    }
    // pointing the temp pointer to the node after key
    temp->next = temp->next->next;

}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{
    Node* temp = *head_ref;
    Node* tail = temp;
    
    // finding tail of circular LL
    while( tail->next != temp ){
        tail = tail->next;
    }
    
    Node* curr = temp;
    Node* prev = tail;
    Node* next = curr;
    
    // doing while till n-1 element
    while( curr != tail ){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    //  for nth element, pointer is pointoing at tail
    curr->next = prev;
    // circular LL is now reversed
    * head_ref = curr; // pointing the given head at the last element of original LL
}
