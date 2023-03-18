bool isCircular(Node *head)
{
   Node* temp = head;
   if( head == NULL ){
       return 1;
   }
   //traversing the linked list
   while( temp != NULL ){
       if( temp->next == head ){ //checking if last node->next == head or not
           return 1;
       }
       temp = temp->next;  //if not move temp forward
       
   }
   return 0;
}
