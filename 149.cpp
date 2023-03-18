Node* findIntersection(Node* head1, Node* head2)
{
    Node* curr1 = head1;
    Node* curr2 = head2;
  //creating a dummy node to make an answer linked list
    Node* chotaHead = new Node(-1);
    //pointing a dummy pointer , to traverse the ans linke dlist
    Node* ans = chotaHead;
    
    while( curr1 != NULL && curr2 != NULL ){
        if( curr1->data < curr2->data ){
            curr1 = curr1->next;
        }
        else if ( curr1->data > curr2->data ){
            curr2 = curr2->next;
        }
        else{// adding new noodes to ans linked list
            Node* temp = new Node( curr1->data );
            ans->next = temp;
            ans = temp;
            curr1 = curr1->next;
            curr2 = curr2->next;
            
        }
    }return chotaHead->next;
}
