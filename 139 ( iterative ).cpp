class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node* forward= NULL;
        Node* curr= head;
        Node* prev= NULL;
        
      //traversing the linked list
        while( curr != NULL ){
           forward = curr->next;
           curr->next = prev;
           prev = curr;
           curr = forward;
        }
      //head of reversed list
        return prev;
    }
    
};
