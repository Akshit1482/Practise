class Solution
{
    private:
    void reverse( Node* &head, Node* curr, Node* prev){
        
        //base case
        if( curr=NULL ){
            head=prev;
            return;
        }
         Node* forward = curr->next;
         reverse( head, forward, curr);
         //after traversing the entire LL we are pointing next ptr. to previous element
         curr->next = prev;
    }
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node* curr = head;
        Node* prev = NULL;
        reverse( head, curr, prev);
        return head;
    }
    
};
