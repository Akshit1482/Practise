class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* temp = head;
        Node* last = head;
         
        // iterate till last->next is not null
        while( last->next != NULL ){
            last = last->next;  // last element
        }
        
        // one by one move first element of LL to last
        for( int i=0; i<k; i++ ){
            temp = head;
            // moving head forward
            head = head->next;
            last->next = temp; // pointing last element to first;
            // as first is last element temp
            temp->next = NULL;
            
            last = temp; // first element is new last
        }
        return head;
    }
};
